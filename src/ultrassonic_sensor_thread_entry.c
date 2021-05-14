#include "ultrassonic_sensor_thread.h"
#include "bsp_api.h"
#include "gx_api.h"
#include "lcd_thread.h"
#include <math.h>

/* Setup the channels that the sensors were connected*/
#define CHANNEL_BACK_RIGHT      (1U)
#define CHANNEL_BACK_LEFT       (3U)
#define CHANNEL_BACK_MIDDLE     (4U)
#define CHANNEL_RIGHT           (5U)
#define CHANNEL_FRONT_RIGHT     (6U)
#define CHANNEL_FRONT_LEFT      (7U)
#define CHANNEL_FRONT_MIDDLE    (8U)
#define CHANNEL_LEFT            (9U)
#define TIMER_SECOND        (1000000000U)
#define TIMER_MILLISECOND   (1000000U)
#define TIMER_MICROSECOND   (1000U)
#define BIT_32              (0x100000000U)

/* Global Variables*/

input_capture_info_t echo_measurement_info;

static uint64_t capture_overflow = 0;
static uint32_t capture_counter = 0;

int backRightSensorDistance, backLeftSensorDistance, backMiddleSensorDistance;
int frontRightSensorDistance, frontLeftSensorDistance, frontMiddleSensorDistance;
int rightSensorDistance, leftSensorDistance;
int sumOfDistance = 0;
uint32_t val;
UINT err;

/* Functions Declaration*/

void echo_measurement_callback(input_capture_callback_args_t * p_args);
void ultrassonic_sensor_timers_setup();

/* Ultrassonic Sensor Thread entry function */
void ultrassonic_sensor_thread_entry(void)
{

    ultrassonic_sensor_timers_setup();

    while (1)
    {
        err = tx_queue_send(&g_lcd_distance_queue, &backRightSensorDistance, TX_WAIT_FOREVER);
        if(err != TX_SUCCESS)
        {
            while(1);
        }

        tx_thread_sleep (100);
    }
}

void echo_measurement_callback(input_capture_callback_args_t * p_args)
{
    static uint32_t pclk_freq_hz = 0;
    static uint64_t time_captured = 0;

    switch(p_args->event)
    {
        case INPUT_CAPTURE_EVENT_MEASUREMENT:

            /* Get the value of the captured counter and overflows number */
            capture_counter = p_args->counter;

            /* Get the frequency of PCLKD in Hz*/
            g_cgc_on_cgc.systemClockFreqGet(CGC_SYSTEM_CLOCKS_PCLKD, &pclk_freq_hz);

            /* Calculate time value of measurement (ns) */
            time_captured = (uint64_t)(((capture_overflow * BIT_32) + (uint64_t)capture_counter) * TIMER_SECOND / pclk_freq_hz);

            /* Calculate distance from the pulse width measured of the sensor that generates the callback. Refer to the HC-SR04 datasheet */
            switch(p_args->channel)
            {
                case CHANNEL_BACK_RIGHT:
                    backRightSensorDistance = (int)time_captured/58000;
                    g_sensor_back_right.p_api->disable(g_sensor_back_right.p_ctrl);
                    g_sensor_back_left.p_api->enable(g_sensor_back_left.p_ctrl);
                    break;
                case CHANNEL_BACK_LEFT:
                    backLeftSensorDistance = (int)time_captured/58000;
                    g_sensor_back_left.p_api->disable(g_sensor_back_left.p_ctrl);
                    g_sensor_back_middle.p_api->enable(g_sensor_back_middle.p_ctrl);
                    break;
                case CHANNEL_BACK_MIDDLE:
                    backMiddleSensorDistance = (int)time_captured/58000;
                    g_sensor_back_middle.p_api->disable(g_sensor_back_middle.p_ctrl);
                    g_sensor_right.p_api->enable(g_sensor_right.p_ctrl);
                    break;
                case CHANNEL_RIGHT:
                    rightSensorDistance = (int)time_captured/58000;
                    g_sensor_right.p_api->disable(g_sensor_right.p_ctrl);
                    g_sensor_front_right.p_api->enable(g_sensor_front_right.p_ctrl);
                    break;
                case CHANNEL_FRONT_RIGHT:
                    frontRightSensorDistance = (int)time_captured/58000;
                    g_sensor_front_right.p_api->disable(g_sensor_front_right.p_ctrl);
                    g_sensor_front_left.p_api->enable(g_sensor_front_left.p_ctrl);
                    break;
                case CHANNEL_FRONT_LEFT:
                    frontLeftSensorDistance = (int)time_captured/58000;
                    g_sensor_front_left.p_api->disable(g_sensor_front_left.p_ctrl);
                    g_sensor_front_middle.p_api->enable(g_sensor_front_middle.p_ctrl);
                    break;
                case CHANNEL_FRONT_MIDDLE:
                    frontMiddleSensorDistance = (int)time_captured/58000;
                    g_sensor_front_middle.p_api->disable(g_sensor_front_middle.p_ctrl);
                    g_sensor_left.p_api->enable(g_sensor_left.p_ctrl);
                    break;
                case CHANNEL_LEFT:
                    leftSensorDistance = (int)time_captured/58000;
                    g_sensor_left.p_api->disable(g_sensor_left.p_ctrl);
                    g_sensor_back_right.p_api->enable(g_sensor_back_right.p_ctrl);
                    break;
                default:
                    break;
            }
            time_captured = 0;
            capture_overflow = 0;
            break;

        case INPUT_CAPTURE_EVENT_OVERFLOW:

            /* Overflows counter add one */
            capture_overflow++;

            break;
        default:
            break;
    }
}

void ultrassonic_sensor_timers_setup()
{
    /* Initialize Input Capture Driver in all sensors */
    g_sensor_back_right.p_api->open(g_sensor_back_right.p_ctrl, g_sensor_back_right.p_cfg);
    g_sensor_back_left.p_api->open(g_sensor_back_left.p_ctrl, g_sensor_back_left.p_cfg);
    g_sensor_back_middle.p_api->open(g_sensor_back_middle.p_ctrl, g_sensor_back_middle.p_cfg);
    g_sensor_right.p_api->open(g_sensor_right.p_ctrl, g_sensor_right.p_cfg);
    g_sensor_front_right.p_api->open(g_sensor_front_right.p_ctrl, g_sensor_front_right.p_cfg);
    g_sensor_front_left.p_api->open(g_sensor_front_left.p_ctrl, g_sensor_front_left.p_cfg);
    g_sensor_front_middle.p_api->open(g_sensor_front_middle.p_ctrl, g_sensor_front_middle.p_cfg);
    g_sensor_left.p_api->open(g_sensor_left.p_ctrl, g_sensor_left.p_cfg);

    /* Start Input Capture Driver in the back right sensor */
    g_sensor_back_right.p_api->enable(g_sensor_back_right.p_ctrl);

    /* Initialize GPT Timer Driver */
    g_trigger.p_api->open(g_trigger.p_ctrl, g_trigger.p_cfg);

    return;
}
