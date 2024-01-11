/*
 * RegLib.h
 *
 *  Created on: Jan 9, 2024
 *      Author: Mr.Robot
 */

#ifndef REGLIB_H_
#define REGLIB_H_

//Defines
#define INPUT      				00;
#define OUTPUT     				01;
#define ALTERNATE  				10;
#define ANALOG     				11;
#define LOW         			0;
#define HIGH        			1;
#define ENABLE       			0x01UL;
#define DISABLE        			0x00UL;
#define BASEADDRESSRCC          0x40023830;
#define ADDRESSPORTCMODE        0x40020800;
#define ADDRESSPORTCOUTD        0x40020814;



#include <stdint.h>

//Defining structs
typedef struct{
	//RRC configuration register

	uint32_t volatile GPIOA_EN   :1;
	uint32_t volatile GPIOB_EN   :1;
	uint32_t volatile GPIOC_EN   :1;
	uint32_t volatile GPIOD_EN   :1;
	uint32_t volatile GPIOE_EN   :1;
	uint32_t volatile Reserved0  :2;
	uint32_t volatile GPIOH_EN   :1;
	uint32_t volatile Reserved1  :4;
	uint32_t volatile CRC_EN   	 :1;
	uint32_t volatile Reserved2  :3;
	uint32_t volatile Reserved3  :5;
	uint32_t volatile DMA1_EN    :1;
	uint32_t volatile DMA2_EN    :1;
	uint32_t volatile Reserved4  :9;

}RCC_Conf_t; //tag for this struct (RCC (Reset and Control Clock))

typedef struct {
	//GPIO mode register

	uint32_t volatile Moder0     :2;
	uint32_t volatile Moder1     :2;
	uint32_t volatile Moder2     :2;
	uint32_t volatile Moder3     :2;
	uint32_t volatile Moder4     :2;
	uint32_t volatile Moder5     :2;
	uint32_t volatile Moder6     :2;
	uint32_t volatile Moder7     :2;
	uint32_t volatile Moder8     :2;
	uint32_t volatile Moder9     :2;
	uint32_t volatile Moder10    :2;
	uint32_t volatile Moder11    :2;
	uint32_t volatile Moder12    :2;
	uint32_t volatile Moder13    :2;
	uint32_t volatile Moder14    :2;
	uint32_t volatile Moder15    :2;

}GPIOX_MODE_REG_t; //Tag for this struct (GPIO port mode register)

typedef struct{
	//GPIO Port Output data Register

	uint32_t volatile pin0       :1;
	uint32_t volatile pin1       :1;
	uint32_t volatile pin2       :1;
	uint32_t volatile pin3       :1;
	uint32_t volatile pin4       :1;
	uint32_t volatile pin5       :1;
	uint32_t volatile pin6       :1;
	uint32_t volatile pin7       :1;
	uint32_t volatile pin8       :1;
	uint32_t volatile pin9       :1;
	uint32_t volatile pin10      :1;
	uint32_t volatile pin11      :1;
	uint32_t volatile pin12      :1;
	uint32_t volatile pin13      :1;
	uint32_t volatile pin14      :1;
	uint32_t volatile pin15      :1;
	uint32_t const 		     	 :16; //reserved pins

}GPIOX_OUTDAT_REG_t; //Tag for this struct (GPIO port output data register)



#endif /* REGLIB_H_ */
