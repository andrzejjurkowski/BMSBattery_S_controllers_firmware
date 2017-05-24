/*
 * BMSBattery S series motor controllers firmware
 *
 * Copyright (C) Casainho, 2017.
 *
 * Released under the GPL License, Version 3
 */

#include "stm8s.h"
#include "stm8s_gpio.h"
#include "hall_sensors.h"
#include "main.h"
#include "gpio.h"
#include "motor.h"

void hall_sensor_init (void)
{
  //hall sensors pins as external input pin interrupt
  GPIO_Init(HALL_SENSORS__PORT,
	    (GPIO_Pin_TypeDef)(HALL_SENSOR_A__PIN | HALL_SENSOR_B__PIN | HALL_SENSOR_C__PIN),
            GPIO_MODE_IN_FL_IT);

  //initialize the Interrupt sensitivity
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOE,
			    EXTI_SENSITIVITY_RISE_FALL);
}