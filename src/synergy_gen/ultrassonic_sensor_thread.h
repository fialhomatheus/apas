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
#ifdef __cplusplus
extern "C"
{
#endif
extern TX_QUEUE g_ultrassonic_sensor_queue;
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* ULTRASSONIC_SENSOR_THREAD_H_ */
