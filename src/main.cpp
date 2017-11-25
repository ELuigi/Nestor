#include <mbed.h>
#include <target.h>
#include <Motor.h>
//#include <RC_PWM.h>
#include "stm32f1xx_ll_tim.h"

Motor MainMotor(MotorLeftForward,MotorLeftBackward,MotorRightForward,MotorRightBackward);
Serial Computer(USBTX, USBRX);

//test of new pwm
void SystemClock_Config(void);
void TimerCaptureCompare_Ch2_Callback();
//declaration of new methods


/* TIM3_ARR register maximum value */
#define TIM3_ARR_MAX (uint32_t)0xFFFF

TIM_HandleTypeDef htim3;

/* Timer Input Capture Configuration Structure declaration */
TIM_IC_InitTypeDef       sConfig;

/* Slave configuration structure */
TIM_SlaveConfigTypeDef   sSlaveConfig;

//end of test of new pwmrc
/* Captured Value */
__IO uint32_t            uwIC2Value = 0;
/* Duty Cycle Value */
__IO uint32_t            uwDutyCycle = 0;
/* Frequency Value */
__IO uint32_t            uwFrequency = 0;

/* Counter Prescaler value */
uint32_t uhPrescalerValue = 0;

int main() {

  Computer.baud(115200);
  Computer.printf("Starting communication...");

  //test new pwmrc
  //SystemClock_Config();

  /*##-1- Configure the TIM peripheral #######################################*/
    /* ---------------------------------------------------------------------------
    TIM3 configuration: PWM Input mode

    In this example TIM3 input clock (TIM3CLK) is set to APB1 clock (PCLK1),
      since APB1 prescaler is 1.
      TIM3CLK = PCLK1
      PCLK1 = HCLK
      => TIM3CLK = HCLK = SystemCoreClock

    External Signal Frequency = TIM3 counter clock / TIM3_CCR2 in Hz.

    External Signal DutyCycle = (TIM3_CCR1*100)/(TIM3_CCR2) in %.

    --------------------------------------------------------------------------- */

    /* Set TIMx instance */
    htim3.Instance = TIM3;

    /* Initialize TIMx peripheral as follows:
         + Period = 0xFFFF
         + Prescaler = 0
         + ClockDivision = 0
         + Counter direction = Up
    */
    htim3.Init.Period            = 0xFFFF;
    htim3.Init.Prescaler         = 0;
    htim3.Init.ClockDivision     = 0;
    htim3.Init.CounterMode       = TIM_COUNTERMODE_UP;
    htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    if (HAL_TIM_IC_Init(&htim3) != HAL_OK)
    {
      /* Initialization Error */
    //  Error_Handler();
    }

    /*##-2- Configure the Input Capture channels ###############################*/
    /* Common configuration */
    sConfig.ICPrescaler = TIM_ICPSC_DIV1;
    sConfig.ICFilter = 0;

    /* Configure the Input Capture of channel 1 */
    sConfig.ICPolarity = TIM_ICPOLARITY_FALLING;
    sConfig.ICSelection = TIM_ICSELECTION_INDIRECTTI;
    if (HAL_TIM_IC_ConfigChannel(&htim3, &sConfig, TIM_CHANNEL_1) != HAL_OK)
    {
      /* Configuration Error */
      //Error_Handler();
    }

    /* Configure the Input Capture of channel 2 */
    sConfig.ICPolarity = TIM_ICPOLARITY_RISING;
    sConfig.ICSelection = TIM_ICSELECTION_DIRECTTI;
    if (HAL_TIM_IC_ConfigChannel(&htim3, &sConfig, TIM_CHANNEL_2) != HAL_OK)
    {
      /* Configuration Error */
      //Error_Handler();
    }
    /*##-3- Configure the slave mode ###########################################*/
    /* Select the slave Mode: Reset Mode  */
    sSlaveConfig.SlaveMode        = TIM_SLAVEMODE_RESET;
    sSlaveConfig.InputTrigger     = TIM_TS_TI2FP2;
    sSlaveConfig.TriggerPolarity  = TIM_TRIGGERPOLARITY_NONINVERTED;
    sSlaveConfig.TriggerPrescaler = TIM_TRIGGERPRESCALER_DIV1;
    sSlaveConfig.TriggerFilter    = 0;
    if (HAL_TIM_SlaveConfigSynchronization(&htim3, &sSlaveConfig) != HAL_OK)
    {
      /* Configuration Error */
      //Error_Handler();
    }

    /*##-4- Start the Input Capture in interrupt mode ##########################*/
    if (HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_2) != HAL_OK)
    {
      /* Starting Error */
      //Error_Handler();
    }

    /*##-5- Start the Input Capture in interrupt mode ##########################*/
    if (HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1) != HAL_OK)
    {
      /* Starting Error */
      //Error_Handler();
    }


  //end test new pwm



    while(1)
    {
     MainMotor.TurnRight(0.8);
    //  Computer.printf("period %f ",pwmrc.period());
    //  Computer.printf("pulse : %f \n",pwmrc.pulsewidth());
    //  wait(2);
    }
}
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Configure PLL ------------------------------------------------------*/
  /* PLL configuration: PLLCLK = HSE * PLLMUL = 8 * 9 = 72 MHz */
  /* PREDIV1 configuration: PREDIV1CLK = PLLCLK / HSEPredivValue = 72 / 1 = 72 MHz */
  /* Enable HSE and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState       = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSIState       = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState   = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource  = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.HSEPredivValue     = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.PLL.PLLMUL         = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
  {
    /* Initialization Error */
    Computer.printf("error in SystemClock") ;
    while(1);
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType      = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2)!= HAL_OK)
  {
    Computer.printf("error in SystemClock") ;

    while(1);
  }
}

void TimerCaptureCompare_Ch2_Callback()
 {
     /* Get the Input Capture value */
     uwIC2Value = LL_TIM_IC_GetCaptureCH2(TIM3);

     if (uwIC2Value != 0)
     {
       /* Duty cycle computation */
       uwDutyCycle = (LL_TIM_IC_GetCaptureCH1(TIM3) * 100) / uwIC2Value;

       /* uwFrequency computation
       TIM3 freq  = SystemCoreClock */
       uwFrequency = SystemCoreClock  / (1*uwIC2Value);
       Computer.printf("Frequency : %f DutyCycle : %f \n",uwFrequency,uwDutyCycle) ;
     }
     else
     {
       uwDutyCycle = 0;
       uwFrequency = 0;
     }
 }
