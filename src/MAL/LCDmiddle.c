/*
 * LCDmiddle.c
 *
 *  Created on: 21/04/2018
 *      Author: Manuel
 */

/******************** INCLUSIONES ********************/
#include "LCDmiddle.h"

/******************** DEFINICIONES ********************/
#define ANCHODEBOTON			25
#define LARGODEBOTON			45
#define POSICIONCENTRALDE_X		120-LARGODEBOTON/2

/******************** DECLARACIONES ********************/
static T_ULONG CurrentFrameBuffer = LCD_FRAME_BUFFER;
/******************** CÓDIGO ********************/
/**
* @brief  Configure the IO Expander and the Touch Panel.
* @param  None
* @retval None
*/
extern void LCDmeddle_InitialConfig(){
	LCDmeddle_delay(0x1000);
	/* Clear the LCD */
	LCD_Clear(LCD_COLOR_WHITE);

	/* Configure the IO Expander */
	if(IOE_Config() == IOE_OK){
		LCD_SetFont(&Font8x8);
//		LCD_DisplayStringLine(LINE(32), (uint8_t*)"              Touch Panel Paint     ");

		//XMAX=320	YMAX=240
		LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*0+10, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 01
		LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*1+15, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 02
		LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*2+20, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 03
		LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*3+25, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 04
		LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*4+30, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 05
		LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*5+35, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 06
		LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*6+40, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 07
		LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*7+45, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 08
		LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*8+50, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 09
		LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*9+55, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 10

//		LCD_SetTextColor(LCD_COLOR_BLUE2);
//		LCD_DrawFullRect(5, 250, 30, 30);
//
//		LCD_DrawRect(180, 270, 48, 50);
//
//		LCD_SetFont(&Font16x24);
//		LCD_DisplayChar(LCD_LINE_12, 195, 'C');
//
//		LCD_DrawLine(0, 284, 180, LCD_DIR_HORIZONTAL);
//		LCD_DrawLine(1, 248, 71, LCD_DIR_VERTICAL);
	}
  else{
	  NVIC_SystemReset();
  }
}

extern void LCDmeddle_UpdateButtonPosition(T_UBYTE lul_BOTONPRESIONADO, T_ULONG X_Pos){
	LCDmeddle_CustomClear(LCD_COLOR_WHITE);

	switch(lul_BOTONPRESIONADO){
		case BOTON01:
			LCD_DrawRect(X_Pos-LARGODEBOTON/2, ANCHODEBOTON*0+10, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 01
			LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*1+15, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 02
			LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*2+20, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 03
			LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*3+25, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 04
			LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*4+30, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 05
			LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*5+35, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 06
			LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*6+40, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 07
			LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*7+45, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 08
			LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*8+50, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 09
			LCD_DrawRect(POSICIONCENTRALDE_X, ANCHODEBOTON*9+55, ANCHODEBOTON, LARGODEBOTON);		// BOTÓN 10
			break;

		default:
			break;
	}
}

void LCDmeddle_CustomClear(T_UWORD Color){
		T_ULONG lul_index = 0;

		/* erase memory */
		for (lul_index = 0; lul_index < BUFFER_OFFSET; lul_index++){
			*(__IO T_UWORD*)(CurrentFrameBuffer + (2*lul_index)) = Color;
		}
}

static void LCDmeddle_delay(__IO T_ULONG nCount){
  __IO T_ULONG index = 0;
  for(index = nCount; index != 0; index--){

  }
}
