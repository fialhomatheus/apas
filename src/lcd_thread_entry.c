#include <stdio.h>
#include "lcd_thread.h"
#include "bsp_api.h"
#include "gx_api.h"
#include "hardware/lcd.h"

/* Include GUIX resource and specification files */
#include "gui/guiapp_resources.h"
#include "gui/guiapp_specifications.h"


/* Private function prototypes */
static bool ssp_touch_to_guix(sf_touch_panel_payload_t * p_touch_payload, GX_EVENT * g_gx_event);
void lcd_thread_entry(void);
void g_lcd_spi_callback(spi_callback_args_t * p_args);
static void update_prompt_text_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, UINT string_id);


/* Private global variables */
static GX_EVENT g_gx_event;
GX_WINDOW_ROOT *p_window_root;
extern GX_CONST GX_STUDIO_WIDGET *guiapp_widget_table[];
extern WINDOW1_CONTROL_BLOCK window1;

static UINT    val;
static GX_CHAR txt_buffer[4];

/* LCD Thread entry function */
void lcd_thread_entry(void)
{

    /* Initialize GUIX library */
    gx_system_initialize();

    /* Initialize GUIX drivers */
    g_sf_el_gx.p_api->open (g_sf_el_gx.p_ctrl, g_sf_el_gx.p_cfg);

    /* Configure the main display */
    gx_studio_display_configure(DISPLAY_1,                  /* Display to configure */
                                g_sf_el_gx.p_api->setup,    /* Driver to use        */
                                LANGUAGE_ENGLISH,           /* Language to install  */
                                DISPLAY_1_THEME_1,          /* Theme to install     */
                                &p_window_root);            /* Root window pointer  */

    g_sf_el_gx.p_api->canvasInit(g_sf_el_gx.p_ctrl, p_window_root);

    /* Create the widgets we have defined with the GUIX data structures and resources */
    GX_CONST GX_STUDIO_WIDGET ** pp_studio_widget = &guiapp_widget_table[0];
    GX_WIDGET * p_first_screen = NULL;

    while (GX_NULL != *pp_studio_widget)
    {
        /* We must first create the widgets according the data generated in GUIX Studio */

        /* Once we are working on the widget we want to see first, save the pointer for later */
        if (0 == strcmp("window1", (char*)(*pp_studio_widget)->widget_name))
        {
            gx_studio_named_widget_create((*pp_studio_widget)->widget_name, (GX_WIDGET *)p_window_root, GX_NULL);
        } else {
            gx_studio_named_widget_create((*pp_studio_widget)->widget_name, GX_NULL, GX_NULL);
        }
        /* Move to next top-level widget */
        pp_studio_widget++;
    }

    /* Attach the first screen to the root so we can see it when the root is shown */
    gx_widget_attach(p_window_root, p_first_screen);

    /* Shows the root window to make it and patients screen visible. */
    gx_widget_show(p_window_root);

    /* Let GUIX run */
    gx_system_start();

    /** Open the SPI driver to initialize the LCD (SK-S7G2) **/
    g_spi_lcdc.p_api->open(g_spi_lcdc.p_ctrl, (spi_cfg_t *)g_spi_lcdc.p_cfg);

    /** Setup the ILI9341V (SK-S7G2) **/
    ILI9341V_Init();

//    gx_prompt_text_set(&window1.window1_distance, "Distancia: 35 cm");
//    gx_system_dirty_mark(&window1.window1_distance);
//    gx_system_canvas_refresh();

    tx_thread_sleep(100);

    while (1)
    {
        /* Convert current counter value to string */
        gx_utility_ltoa((LONG) val, txt_buffer, 4);

        gx_prompt_text_set(&window1.window1_distance, (GX_CHAR *)txt_buffer);

        /* Let GUIX know that txt_counter should be re-drawn */
        gx_system_dirty_mark((GX_WIDGET *) &window1.window1_distance);

        /* Force re-draw all "dirty" widgets */
        gx_system_canvas_refresh();

        val++;

        if (99 < val)
            val = 0;

        tx_thread_sleep(10);
    }
}


UINT window1_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type)
    {
        default:
            gx_window_event_process(widget, event_ptr);
            break;
    }

    return result;
}


static bool ssp_touch_to_guix(sf_touch_panel_payload_t * p_touch_payload, GX_EVENT * gx_event)
{
    bool send_event = true;

    switch (p_touch_payload->event_type)
    {
    case SF_TOUCH_PANEL_EVENT_DOWN:
        gx_event->gx_event_type = GX_EVENT_PEN_DOWN;
        break;
    case SF_TOUCH_PANEL_EVENT_UP:
        gx_event->gx_event_type = GX_EVENT_PEN_UP;
        break;
    case SF_TOUCH_PANEL_EVENT_HOLD:
    case SF_TOUCH_PANEL_EVENT_MOVE:
        gx_event->gx_event_type = GX_EVENT_PEN_DRAG;
        break;
    case SF_TOUCH_PANEL_EVENT_INVALID:
        send_event = false;
        break;
    default:
        break;
    }

    if (send_event)
    {
        /** Send event to GUI */
        gx_event->gx_event_sender = GX_ID_NONE;
        gx_event->gx_event_target = 0;
        gx_event->gx_event_display_handle = 0;

        gx_event->gx_event_payload.gx_event_pointdata.gx_point_x = p_touch_payload->x;

#if defined(BSP_BOARD_S7G2_SK)
        gx_event->gx_event_payload.gx_event_pointdata.gx_point_y = (GX_VALUE)(320 - p_touch_payload->y);  // SK-S7G2
#else
        gx_event->gx_event_payload.gx_event_pointdata.gx_point_y = p_touch_payload->y;  // DK-S7G2, PE-HMI1
#endif
    }

    return send_event;
}

#if defined(BSP_BOARD_S7G2_SK)
void g_lcd_spi_callback(spi_callback_args_t * p_args)
{
    (void)p_args;
    tx_semaphore_ceiling_put(&g_lcd_semaphore, 1);
}
#endif

