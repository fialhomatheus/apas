/* generated thread header file - do not edit */
#ifndef ULTRASSONIC_SENSOR_THREAD_H_
#define ULTRASSONIC_SENSOR_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
extern "C" void ultrassonic_sensor_thread_entry(void);
#else
extern void ultrassonic_sensor_thread_entry(void);
#endif
#include "r_gpt_input_capture.h"
#include "r_input_capture_api.h"
#include "r_gpt.h"
#include "r_timer_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/** Timer on GPT Instance. */
extern const input_capture_instance_t g_sensor_left;
#ifndef echo_measurement_callback
void echo_measurement_callback(input_capture_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const input_capture_instance_t g_sensor_front_middle;
#ifndef echo_measurement_callback
void echo_measurement_callback(input_capture_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const input_capture_instance_t g_sensor_front_left;
#ifndef echo_measurement_callback
void echo_measurement_callback(input_capture_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const input_capture_instance_t g_sensor_front_right;
#ifndef echo_measurement_callback
void echo_measurement_callback(input_capture_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const input_capture_instance_t g_sensor_right;
#ifndef echo_measurement_callback
void echo_measurement_callback(input_capture_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const input_capture_instance_t g_sensor_back_middle;
#ifndef echo_measurement_callback
void echo_measurement_callback(input_capture_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const input_capture_instance_t g_sensor_back_left;
#ifndef echo_measurement_callback
void echo_measurement_callback(input_capture_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const input_capture_instance_t g_sensor_back_right;
#ifndef echo_measurement_callback
void echo_measurement_callback(input_capture_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_trigger;
#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
extern TX_QUEUE g_ultrassonic_sensor_queue;
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* ULTRASSONIC_SENSOR_THREAD_H_ */
