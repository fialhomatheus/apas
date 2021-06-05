/* generated thread source file - do not edit */
#include "servo_motor_thread.h"

TX_THREAD servo_motor_thread;
void servo_motor_thread_create(void);
static void servo_motor_thread_func(ULONG thread_input);
static uint8_t servo_motor_thread_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.servo_motor_thread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_servo_control) && !defined(SSP_SUPPRESS_ISR_GPT10)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 10);
#endif
#endif
static gpt_instance_ctrl_t g_servo_control_ctrl;
static const timer_on_gpt_cfg_t g_servo_control_extend =
{ .gtioca =
{ .output_enabled = true, .stop_level = GPT_PIN_LEVEL_HIGH },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_servo_control_cfg =
{ .mode = TIMER_MODE_PWM, .period = 20, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 92500, .duty_cycle_unit =
          TIMER_PWM_UNIT_PERCENT_X_1000,
  .channel = 10, .autostart = true, .p_callback = NULL, .p_context = &g_servo_control, .p_extend =
          &g_servo_control_extend,
  .irq_ipl = (BSP_IRQ_DISABLED), };
/* Instance structure to use this module. */
const timer_instance_t g_servo_control =
{ .p_ctrl = &g_servo_control_ctrl, .p_cfg = &g_servo_control_cfg, .p_api = &g_timer_on_gpt };
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void servo_motor_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&servo_motor_thread, (CHAR *) "Servo Motor Thread", servo_motor_thread_func, (ULONG) NULL,
                            &servo_motor_thread_stack, 1024, 1, 1, 1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&servo_motor_thread, 0);
    }
}

static void servo_motor_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    servo_motor_thread_entry ();
}
