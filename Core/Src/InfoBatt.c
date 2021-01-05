/*
 * InfoBatt.c
 *
 *  Created on: 27 Nov 2020
 *      Author: jerem
 */

#include "InfoBatt.h"

static const uint8_t GAUGE_ADDR=0x64<<1;
static const uint8_t VOLT_REG=0x08;
static const uint8_t AMP_REG=0x0E;


/***********************************
 *	BATTERY 1 & 2
 **********************************/

float InfoBatt_getCurrent(int nb_batt)
{
	float current;
	uint16_t bufRx16;
	I2C_HandleTypeDef hi2c;

	if (nb_batt==1)
		hi2c=hi2c1;
	else
		hi2c=hi2c2;

	bufRx16=read_register(AMP_REG,&hi2c);
	current=6.4*(bufRx16-32767)/32767;
	return current;
}


float InfoBatt_getVoltage(int nb_batt)
{
	float voltage;
	uint16_t bufRx16;
	I2C_HandleTypeDef hi2c;

	if (nb_batt==1)
		hi2c=hi2c1;
	else
		hi2c=hi2c2;

	bufRx16=read_register(VOLT_REG,&hi2c);
	voltage=70.8*bufRx16/65535;
	return voltage;
}


float InfoBatt_getSoc(int nb_batt)
{
	float val;
	//Do your thing mate
	return val;
}



/*
 *
 * 		FONCTION SUPPORT
 *
 */

uint16_t read_register(uint8_t register_pointer,I2C_HandleTypeDef *hi2c)
{
	uint16_t return_value=0;
	HAL_I2C_Mem_Read(&hi2c,GAUGE_ADDR,(uint16_t)register_pointer,I2C_MEMADD_SIZE_8BIT,&return_value,2,HAL_MAX_DELAY);
	return return_value;
}

