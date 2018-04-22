/**
  ******************************************************************************
  * @file    Touch_Panel/main.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    20-September-2013
  * @brief   This example describes how to configure and use the touch panel 
  *          mounted on STM32F429I-DISCO boards.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

volatile T_ULONG PosiciondeX = 0, PosiciondeY = 0;
volatile T_BOOLEAN TouchDetected = FALSE;

/**
  * @brief   	Main program
  * @param  	None
  * @retval 	None
  */
int main(void){
  static TP_STATE* TP_State;
  /*!< At this stage the microcontroller clock setting is already configured, 
  this is done through SystemInit() function which is called from startup
  file (startup_stm32f429_439xx.s) before to branch to application main.
  To reconfigure the default setting of SystemInit() function, refer to
  system_stm32f4xx.c file
  */
  /* LCD initiatization */
  LCD_Init();
  /* LCD Layer initiatization */
  LCD_LayerInit();
  /* Enable the LTDC */
  LTDC_Cmd(ENABLE);
  /* Set LCD foreground layer */
  LCD_SetLayer(LCD_FOREGROUND_LAYER);
  /* Touch Panel configuration */
  LCDmeddle_InitialConfig();

  while(8){
	  TP_State = IOE_TP_GetState();
	  TouchDetected = TP_State->TouchDetected;
	  PosiciondeX = TP_State->X;
	  PosiciondeY = TP_State->Y;

	  if(TouchDetected && PosiciondeY < 30){
		  LCDmeddle_UpdateButtonPosition(BOTON01, PosiciondeX);
	  }
  }	//WHILE(1)
} //INT MAIN

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  while (1)
  {
  }
}
#endif	// USE_FULL_ASSERT
