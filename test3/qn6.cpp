/*
 * qn6.cpp
 *
 *  Created on: 7 Feb 2017
 *      Author: user-pc
 */
#include <Arduino.h>
#define PIN_LED_RED 6
#define PIN_LED_YELLOW 7
#define PIN_POTENTIALMETER_INPUT 0
#define PIN_TOUCH_SENSOR_INPUT 1

int remap (int);

void setup() {
	pinMode(PIN_LED_RED, OUTPUT);
	pinMode(PIN_LED_YELLOW, OUTPUT);
	pinMode(PIN_POTENTIALMETER_INPUT, INPUT);
	pinMode(PIN_TOUCH_SENSOR_INPUT, INPUT);
}

void loop() {
////	int revised_val2;
//	val = analogRead(PIN_PTTM);
////	revised_val2 = remap(val);
//	analogWrite(PIN_LED, remap(val));
//	delay(500);
	potential_red();
	touch_sensor_yellow(PIN_TOUCH_SENSOR_INPUT);


}

int remapPotential(int val){
	int revised_val;
	revised_val = val/4;
	return revised_val;
}

void remapTouchSensor(int touch_sensor_value){

}

void potential_red(){
	//	int revised_val2;
		val = analogRead(PIN_POTENTIALMETER_INPUT);
	//	revised_val2 = remap(val);
		analogWrite(PIN_LED_RED, remapPotential(val));
}


