/* generated thread header file - do not edit */
#ifndef SERVO_MOTOR_THREAD_H_
#define SERVO_MOTOR_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
extern "C" void servo_motor_thread_entry(void);
#else
extern void servo_motor_thread_entry(void);
#endif
#include "r_gpt.h"
#include "r_timer_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_servo_control;
#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* SERVO_MOTOR_THREAD_H_ */
