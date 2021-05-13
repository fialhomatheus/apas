/* generated thread source file - do not edit */
#include "ultrassonic_sensor_thread.h"

TX_THREAD ultrassonic_sensor_thread;
void ultrassonic_sensor_thread_create(void);
static void ultrassonic_sensor_thread_func(ULONG thread_input);
static uint8_t ultrassonic_sensor_thread_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.ultrassonic_sensor_thread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
TX_QUEUE g_ultrassonic_sensor_queue;
static uint8_t queue_memory_g_ultrassonic_sensor_queue[4];
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void ultrassonic_sensor_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */
    UINT err_g_ultrassonic_sensor_queue;
    err_g_ultrassonic_sensor_queue = tx_queue_create (&g_ultrassonic_sensor_queue, (CHAR *) "ultrassonic_sensor_queue",
                                                      1, &queue_memory_g_ultrassonic_sensor_queue,
                                                      sizeof(queue_memory_g_ultrassonic_sensor_queue));
    if (TX_SUCCESS != err_g_ultrassonic_sensor_queue)
    {
        tx_startup_err_callback (&g_ultrassonic_sensor_queue, 0);
    }

    UINT err;
    err = tx_thread_create (&ultrassonic_sensor_thread, (CHAR *) "Ultrassonic Sensor Thread",
                            ultrassonic_sensor_thread_func, (ULONG) NULL, &ultrassonic_sensor_thread_stack, 1024, 1, 1,
                            1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&ultrassonic_sensor_thread, 0);
    }
}

static void ultrassonic_sensor_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    ultrassonic_sensor_thread_entry ();
}
