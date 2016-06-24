/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */     
#include "gpio.h"
/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/
osThreadId defaultTaskHandle;

/* USER CODE BEGIN Variables */
osThreadId led1TaskHandle1;
osThreadId led1TaskHandle2;
osThreadId led1TaskHandle3;
osThreadId led1TaskHandle4;
/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void StartDefaultTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */
void blinkLED1(void const * argument);
void blinkLED2(void const * argument);
void blinkLED3(void const * argument);
void blinkLED4(void const * argument);
/* USER CODE END FunctionPrototypes */

/* Hook prototypes */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
	osThreadDef(LED_thread1, blinkLED1, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);
	led1TaskHandle1 = osThreadCreate(osThread(LED_thread1),NULL);
	osThreadDef(LED_thread2, blinkLED2, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);
	led1TaskHandle2 = osThreadCreate(osThread(LED_thread2),NULL);
	osThreadDef(LED_thread3, blinkLED3, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);
	led1TaskHandle3 = osThreadCreate(osThread(LED_thread3),NULL);
	osThreadDef(LED_thread4, blinkLED4, osPriorityNormal, 0, configMINIMAL_STACK_SIZE*5);
	led1TaskHandle4 = osThreadCreate(osThread(LED_thread4),NULL);
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
}

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN StartDefaultTask */
		
	
  /* Infinite loop */
  for(;;)
  {
		//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);
    osDelay(1);
		//HAL_Delay(500);
		//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Application */
void blinkLED1(void const * argument)     
{
	
	for(;;)
	{
		GPIOA->ODR ^= GPIO_PIN_11;
		osDelay(500);
	}
}

void blinkLED2(void const * argument)     
{
	
	for(;;)
	{
		GPIOA->ODR ^= GPIO_PIN_8;
		osDelay(222);
	}
}

void blinkLED3(void const * argument)     
{

	for(;;)
	{
		GPIOB->ODR ^= GPIO_PIN_1;
		osDelay(777);
	}
}

void blinkLED4(void const * argument)     
{
	for(;;)
	{
		GPIOB->ODR ^= GPIO_PIN_3;
		osDelay(1000);
	}
}
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
