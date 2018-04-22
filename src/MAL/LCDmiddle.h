/*
 * LCD_middle.h
 *
 *  Created on: 21/04/2018
 *      Author: Manuel
 */
#ifndef LCD_MIDDLE_H_
#define LCD_MIDDLE_H_

/******************** INCLUSIONES ********************/
#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_ioe.h"
#include "stdtypedef.h"
/******************** DEFINICIONES ********************/

/******************** DECLARACIONES ********************/
enum ButtonNumber_10{
	BOTON01 = 1u,
	BOTON02,
	BOTON03,
	BOTON04,
	BOTON05,
	BOTON06,
	BOTON07,
	BOTON08,
	BOTON09,
	BOTON10
};
/******************** PROTOTIPADOS ********************/
extern void LCDmeddle_InitialConfig(void);
extern void LCDmeddle_UpdateButtonPosition(T_UBYTE lul_BOTONPRESIONADO, uint32_t X_Pos);
void LCDmeddle_CustomClear(T_UWORD Color);
static void LCDmeddle_delay(__IO T_ULONG nCount);

#endif /* LCD_MIDDLE_H_ */
