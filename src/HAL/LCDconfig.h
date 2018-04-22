/*
 * LCDconfig.h
 *
 *  Created on: 21/04/2018
 *      Author: Manuel
 */
#ifndef HAL_LCDCONFIG_H_
#define HAL_LCDCONFIG_H_
/******************** INCLUSIONES ********************/
#include "stdtypedef.h"
#include "stm32f429i_discovery_ioe.h"

/******************** PROTOTIPOS ********************/
extern T_UWORD LCDconfig_getX(void);
extern T_UWORD LCDconfig_getY(void);
extern T_BOOLEAN LCDconfig_getTouchDetected(void);

#endif /* HAL_LCDCONFIG_H_ */
