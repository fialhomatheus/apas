#include "servo_motor_thread.h"

uint32_t position = 45;
uint32_t period = 92100;

/* Servo Motor Thread entry function */
void servo_motor_thread_entry(void)
{
    /*Initialize servo control timer*/
    g_servo_control.p_api->open(g_servo_control.p_ctrl, g_servo_control.p_cfg);

    while(1)
    {
        period = (380/9)*position+88300;
        g_servo_control.p_api->dutyCycleSet(g_servo_control.p_ctrl,period, TIMER_PWM_UNIT_PERCENT_X_1000, 0);
        R_BSP_SoftwareDelay(10,BSP_DELAY_UNITS_MILLISECONDS);
    }
}
