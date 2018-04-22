/*
 * LCDconfig.c
 *
 *  Created on: 21/04/2018
 *      Author: Manuel
 */

#include "LCDconfig.h"

extern T_UWORD LCDconfig_getX(void){

	  int32_t x, xr;

	  /* Read x value from DATA_X register */
	  x = I2C_ReadDataBuffer(IOE_REG_TP_DATA_X);

	  /* x value first correction */
	  if(x <= 3000)
	  {
	  x = 3870 - x;
	  }
	  else
	  {
	   x = 3800 - x;
	  }

	  /* x value second correction */
	  xr = x / 15;

	  /* return x position value */
	  if(xr <= 0)
	  {
	    xr = 0;
	  }
	  else if (xr > 240)
	  {
	    xr = 239;
	  }
	  else
	  {}
	  return (uint16_t)(xr);
}

extern T_UWORD LCDconfig_getY(void){

	  int32_t y, yr;

	  /* Read y value from DATA_Y register */
	  y = I2C_ReadDataBuffer(IOE_REG_TP_DATA_Y);

	  /* y value first correction */

	  y -= 360;

	  /* y value second correction */
	  yr = y / 11;

	  /* return y position value */
	  if(yr <= 0)
	  {
	    yr = 0;
	  }
	  else if (yr > 320)
	  {
	    yr = 319;
	  }
	  else
	  {}
	  return (uint16_t)(yr);
}

extern T_BOOLEAN LCDconfig_getTouchDetected(void){
	return (I2C_ReadDeviceRegister(IOE_REG_TP_CTRL) & 0x80);
}
