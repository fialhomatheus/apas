#include "ultrassonic_sensor_thread.h"
#include "bsp_api.h"
#include "gx_api.h"
#include "lcd_thread.h"

uint32_t val;
UINT err;

/* Ultrassonic Sensor Thread entry function */
void ultrassonic_sensor_thread_entry(void)
{
    val = 25;
    while (1)
    {
        val++;
        val %= 100;
        err = tx_queue_send(&g_lcd_distance_queue, &val, TX_WAIT_FOREVER);
        if(err != TX_SUCCESS)
        {
            while(1);
        }

        tx_thread_sleep (100);
    }
}
