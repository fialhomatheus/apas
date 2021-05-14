/* generated thread source file - do not edit */
#include "ultrassonic_sensor_thread.h"

TX_THREAD ultrassonic_sensor_thread;
void ultrassonic_sensor_thread_create(void);
static void ultrassonic_sensor_thread_func(ULONG thread_input);
static uint8_t ultrassonic_sensor_thread_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.ultrassonic_sensor_thread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
#if !defined(SSP_SUPPRESS_ISR_g_sensor_left) && !defined(SSP_SUPPRESS_ISR_GPT9)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 9);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_sensor_left) && !defined(SSP_SUPPRESS_ISR_GPT9)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_isr, GPT, CAPTURE_COMPARE_A, 9);
#endif
static gpt_input_capture_instance_ctrl_t g_sensor_left_ctrl;
static const gpt_input_capture_extend_t g_sensor_left_extend =
{ .signal = GPT_INPUT_CAPTURE_SIGNAL_PIN_GTIOCA, .signal_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, .clock_divider =
          GPT_INPUT_CAPTURE_CLOCK_DIVIDER_1,
  .enable_level = INPUT_CAPTURE_SIGNAL_LEVEL_NONE, .enable_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, };
static const input_capture_cfg_t g_sensor_left_cfg =
{ .channel = 9, .mode = INPUT_CAPTURE_MODE_PULSE_WIDTH, .edge = INPUT_CAPTURE_SIGNAL_EDGE_RISING, .repetition =
          INPUT_CAPTURE_REPETITION_PERIODIC,
  .autostart = false, .p_callback = echo_measurement_callback, .p_context = &g_sensor_left, .p_extend =
          &g_sensor_left_extend,
  .capture_irq_ipl = (12), .overflow_irq_ipl = (12), };
/* Instance structure to use this module. */
const input_capture_instance_t g_sensor_left =
{ .p_ctrl = &g_sensor_left_ctrl, .p_cfg = &g_sensor_left_cfg, .p_api = &g_input_capture_on_gpt };
#if !defined(SSP_SUPPRESS_ISR_g_sensor_front_middle) && !defined(SSP_SUPPRESS_ISR_GPT8)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 8);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_sensor_front_middle) && !defined(SSP_SUPPRESS_ISR_GPT8)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_isr, GPT, CAPTURE_COMPARE_A, 8);
#endif
static gpt_input_capture_instance_ctrl_t g_sensor_front_middle_ctrl;
static const gpt_input_capture_extend_t g_sensor_front_middle_extend =
{ .signal = GPT_INPUT_CAPTURE_SIGNAL_PIN_GTIOCA, .signal_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, .clock_divider =
          GPT_INPUT_CAPTURE_CLOCK_DIVIDER_1,
  .enable_level = INPUT_CAPTURE_SIGNAL_LEVEL_NONE, .enable_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, };
static const input_capture_cfg_t g_sensor_front_middle_cfg =
{ .channel = 8, .mode = INPUT_CAPTURE_MODE_PULSE_WIDTH, .edge = INPUT_CAPTURE_SIGNAL_EDGE_RISING, .repetition =
          INPUT_CAPTURE_REPETITION_PERIODIC,
  .autostart = false, .p_callback = echo_measurement_callback, .p_context = &g_sensor_front_middle, .p_extend =
          &g_sensor_front_middle_extend,
  .capture_irq_ipl = (12), .overflow_irq_ipl = (12), };
/* Instance structure to use this module. */
const input_capture_instance_t g_sensor_front_middle =
{ .p_ctrl = &g_sensor_front_middle_ctrl, .p_cfg = &g_sensor_front_middle_cfg, .p_api = &g_input_capture_on_gpt };
#if !defined(SSP_SUPPRESS_ISR_g_sensor_front_left) && !defined(SSP_SUPPRESS_ISR_GPT7)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 7);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_sensor_front_left) && !defined(SSP_SUPPRESS_ISR_GPT7)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_isr, GPT, CAPTURE_COMPARE_A, 7);
#endif
static gpt_input_capture_instance_ctrl_t g_sensor_front_left_ctrl;
static const gpt_input_capture_extend_t g_sensor_front_left_extend =
{ .signal = GPT_INPUT_CAPTURE_SIGNAL_PIN_GTIOCA, .signal_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, .clock_divider =
          GPT_INPUT_CAPTURE_CLOCK_DIVIDER_1,
  .enable_level = INPUT_CAPTURE_SIGNAL_LEVEL_NONE, .enable_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, };
static const input_capture_cfg_t g_sensor_front_left_cfg =
{ .channel = 7, .mode = INPUT_CAPTURE_MODE_PULSE_WIDTH, .edge = INPUT_CAPTURE_SIGNAL_EDGE_RISING, .repetition =
          INPUT_CAPTURE_REPETITION_PERIODIC,
  .autostart = false, .p_callback = echo_measurement_callback, .p_context = &g_sensor_front_left, .p_extend =
          &g_sensor_front_left_extend,
  .capture_irq_ipl = (12), .overflow_irq_ipl = (12), };
/* Instance structure to use this module. */
const input_capture_instance_t g_sensor_front_left =
{ .p_ctrl = &g_sensor_front_left_ctrl, .p_cfg = &g_sensor_front_left_cfg, .p_api = &g_input_capture_on_gpt };
#if !defined(SSP_SUPPRESS_ISR_g_sensor_front_right) && !defined(SSP_SUPPRESS_ISR_GPT6)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 6);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_sensor_front_right) && !defined(SSP_SUPPRESS_ISR_GPT6)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_isr, GPT, CAPTURE_COMPARE_A, 6);
#endif
static gpt_input_capture_instance_ctrl_t g_sensor_front_right_ctrl;
static const gpt_input_capture_extend_t g_sensor_front_right_extend =
{ .signal = GPT_INPUT_CAPTURE_SIGNAL_PIN_GTIOCA, .signal_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, .clock_divider =
          GPT_INPUT_CAPTURE_CLOCK_DIVIDER_1,
  .enable_level = INPUT_CAPTURE_SIGNAL_LEVEL_NONE, .enable_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, };
static const input_capture_cfg_t g_sensor_front_right_cfg =
{ .channel = 6, .mode = INPUT_CAPTURE_MODE_PULSE_WIDTH, .edge = INPUT_CAPTURE_SIGNAL_EDGE_RISING, .repetition =
          INPUT_CAPTURE_REPETITION_PERIODIC,
  .autostart = false, .p_callback = echo_measurement_callback, .p_context = &g_sensor_front_right, .p_extend =
          &g_sensor_front_right_extend,
  .capture_irq_ipl = (12), .overflow_irq_ipl = (12), };
/* Instance structure to use this module. */
const input_capture_instance_t g_sensor_front_right =
{ .p_ctrl = &g_sensor_front_right_ctrl, .p_cfg = &g_sensor_front_right_cfg, .p_api = &g_input_capture_on_gpt };
#if !defined(SSP_SUPPRESS_ISR_g_sensor_right) && !defined(SSP_SUPPRESS_ISR_GPT5)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 5);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_sensor_right) && !defined(SSP_SUPPRESS_ISR_GPT5)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_isr, GPT, CAPTURE_COMPARE_A, 5);
#endif
static gpt_input_capture_instance_ctrl_t g_sensor_right_ctrl;
static const gpt_input_capture_extend_t g_sensor_right_extend =
{ .signal = GPT_INPUT_CAPTURE_SIGNAL_PIN_GTIOCA, .signal_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, .clock_divider =
          GPT_INPUT_CAPTURE_CLOCK_DIVIDER_1,
  .enable_level = INPUT_CAPTURE_SIGNAL_LEVEL_NONE, .enable_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, };
static const input_capture_cfg_t g_sensor_right_cfg =
{ .channel = 5, .mode = INPUT_CAPTURE_MODE_PULSE_WIDTH, .edge = INPUT_CAPTURE_SIGNAL_EDGE_RISING, .repetition =
          INPUT_CAPTURE_REPETITION_PERIODIC,
  .autostart = false, .p_callback = echo_measurement_callback, .p_context = &g_sensor_right, .p_extend =
          &g_sensor_right_extend,
  .capture_irq_ipl = (12), .overflow_irq_ipl = (12), };
/* Instance structure to use this module. */
const input_capture_instance_t g_sensor_right =
{ .p_ctrl = &g_sensor_right_ctrl, .p_cfg = &g_sensor_right_cfg, .p_api = &g_input_capture_on_gpt };
#if !defined(SSP_SUPPRESS_ISR_g_sensor_back_middle) && !defined(SSP_SUPPRESS_ISR_GPT4)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 4);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_sensor_back_middle) && !defined(SSP_SUPPRESS_ISR_GPT4)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_isr, GPT, CAPTURE_COMPARE_A, 4);
#endif
static gpt_input_capture_instance_ctrl_t g_sensor_back_middle_ctrl;
static const gpt_input_capture_extend_t g_sensor_back_middle_extend =
{ .signal = GPT_INPUT_CAPTURE_SIGNAL_PIN_GTIOCA, .signal_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, .clock_divider =
          GPT_INPUT_CAPTURE_CLOCK_DIVIDER_1,
  .enable_level = INPUT_CAPTURE_SIGNAL_LEVEL_NONE, .enable_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, };
static const input_capture_cfg_t g_sensor_back_middle_cfg =
{ .channel = 4, .mode = INPUT_CAPTURE_MODE_PULSE_WIDTH, .edge = INPUT_CAPTURE_SIGNAL_EDGE_RISING, .repetition =
          INPUT_CAPTURE_REPETITION_PERIODIC,
  .autostart = false, .p_callback = echo_measurement_callback, .p_context = &g_sensor_back_middle, .p_extend =
          &g_sensor_back_middle_extend,
  .capture_irq_ipl = (12), .overflow_irq_ipl = (12), };
/* Instance structure to use this module. */
const input_capture_instance_t g_sensor_back_middle =
{ .p_ctrl = &g_sensor_back_middle_ctrl, .p_cfg = &g_sensor_back_middle_cfg, .p_api = &g_input_capture_on_gpt };
#if !defined(SSP_SUPPRESS_ISR_g_sensor_back_left) && !defined(SSP_SUPPRESS_ISR_GPT3)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 3);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_sensor_back_left) && !defined(SSP_SUPPRESS_ISR_GPT3)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_isr, GPT, CAPTURE_COMPARE_A, 3);
#endif
static gpt_input_capture_instance_ctrl_t g_sensor_back_left_ctrl;
static const gpt_input_capture_extend_t g_sensor_back_left_extend =
{ .signal = GPT_INPUT_CAPTURE_SIGNAL_PIN_GTIOCA, .signal_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, .clock_divider =
          GPT_INPUT_CAPTURE_CLOCK_DIVIDER_1,
  .enable_level = INPUT_CAPTURE_SIGNAL_LEVEL_NONE, .enable_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, };
static const input_capture_cfg_t g_sensor_back_left_cfg =
{ .channel = 3, .mode = INPUT_CAPTURE_MODE_PULSE_WIDTH, .edge = INPUT_CAPTURE_SIGNAL_EDGE_RISING, .repetition =
          INPUT_CAPTURE_REPETITION_PERIODIC,
  .autostart = false, .p_callback = echo_measurement_callback, .p_context = &g_sensor_back_left, .p_extend =
          &g_sensor_back_left_extend,
  .capture_irq_ipl = (12), .overflow_irq_ipl = (12), };
/* Instance structure to use this module. */
const input_capture_instance_t g_sensor_back_left =
{ .p_ctrl = &g_sensor_back_left_ctrl, .p_cfg = &g_sensor_back_left_cfg, .p_api = &g_input_capture_on_gpt };
#if !defined(SSP_SUPPRESS_ISR_g_sensor_back_right) && !defined(SSP_SUPPRESS_ISR_GPT1)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 1);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_sensor_back_right) && !defined(SSP_SUPPRESS_ISR_GPT1)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_isr, GPT, CAPTURE_COMPARE_A, 1);
#endif
static gpt_input_capture_instance_ctrl_t g_sensor_back_right_ctrl;
static const gpt_input_capture_extend_t g_sensor_back_right_extend =
{ .signal = GPT_INPUT_CAPTURE_SIGNAL_PIN_GTIOCA, .signal_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, .clock_divider =
          GPT_INPUT_CAPTURE_CLOCK_DIVIDER_1,
  .enable_level = INPUT_CAPTURE_SIGNAL_LEVEL_NONE, .enable_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, };
static const input_capture_cfg_t g_sensor_back_right_cfg =
{ .channel = 1, .mode = INPUT_CAPTURE_MODE_PULSE_WIDTH, .edge = INPUT_CAPTURE_SIGNAL_EDGE_RISING, .repetition =
          INPUT_CAPTURE_REPETITION_PERIODIC,
  .autostart = false, .p_callback = echo_measurement_callback, .p_context = &g_sensor_back_right, .p_extend =
          &g_sensor_back_right_extend,
  .capture_irq_ipl = (12), .overflow_irq_ipl = (12), };
/* Instance structure to use this module. */
const input_capture_instance_t g_sensor_back_right =
{ .p_ctrl = &g_sensor_back_right_ctrl, .p_cfg = &g_sensor_back_right_cfg, .p_api = &g_input_capture_on_gpt };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_trigger) && !defined(SSP_SUPPRESS_ISR_GPT11)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 11);
#endif
#endif
static gpt_instance_ctrl_t g_trigger_ctrl;
static const timer_on_gpt_cfg_t g_trigger_extend =
{ .gtioca =
{ .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_trigger_cfg =
{ .mode = TIMER_MODE_PWM,
  .period = 110,
  .unit = TIMER_UNIT_PERIOD_MSEC,
  .duty_cycle = 9099,
  .duty_cycle_unit = TIMER_PWM_UNIT_PERCENT_X_1000,
  .channel = 11,
  .autostart = true,
  .p_callback = NULL,
  .p_context = &g_trigger,
  .p_extend = &g_trigger_extend,
  .irq_ipl = (BSP_IRQ_DISABLED), };
/* Instance structure to use this module. */
const timer_instance_t g_trigger =
{ .p_ctrl = &g_trigger_ctrl, .p_cfg = &g_trigger_cfg, .p_api = &g_timer_on_gpt };
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
