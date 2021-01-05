/*
 * InfoBatt.h
 *
 *  Created on: 27 Nov 2020
 *      Author: jerem
 */
#include "BMS_Management.h" //a retirer si c'est l'inverse
#ifndef SRC_INFOBATT_H_
#define SRC_INFOBATT_H_

/*
 *	BATTERY 1 & 2
 */

/*
 * @brief: The user can access to the current value in
 * the battery 1 thanks to the gauge 1
 * @param: None
 * @retval: The value of the current in the battery 1
 * */
float InfoBatt_getCurrent(int nb_batt);


/*
 * @brief: The user can access to the voltage value in
 * the battery 1 thanks to the gauge 1
 * @param: None
 * @retval: The value of the voltage in the battery 1
 * */
float InfoBatt_getVoltage(int nb_batt);


/*
 * @brief: The user can access to the state of charge (Soc)
 * value in the battery 1 thanks to the gauge 1
 * @param: None
 * @retval: The value of the Soc in the battery 1
 * */
float InfoBatt_getSoc(int nb_batt);



/*
 *
 * 	FONCTION SUPPORT
 *
 */

/*
 * @brief: This function allows reading a specific register
 * through the I2C communication channel
 * @param: uint8_t register_pointer register's address,
 * I2C_HandleTypeDef *hi2c which channel/battery we are looking for
 * @retval: uint16_t pointer to the register's value
 */
uint16_t read_register(uint8_t register_pointer,I2C_HandleTypeDef *hi2c);

#endif /* SRC_INFOBATT_H_ */
