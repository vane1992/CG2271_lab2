/*
 * qn7.cpp
 *
 *  Created on: 7 Feb 2017
 *      Author: user-pc
 */

#include <Arduino.h>
unsigned char flag=0;

void isr()
{
	flag=!flag;
	delay(100);
}
void setup()
{

	attachInterrupt(0, isr, RISING)

	pinMode(6, OUTPUT);
}
void loop()
{

	digitalWrite(6, flag);
}
