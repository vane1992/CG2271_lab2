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

int remapPotentialMeter (int x);
int remapTouchSensor(int x);
void potential_red_control();
void touch_sensor_yellow_control();


void setup() {
	pinMode(PIN_LED_RED, OUTPUT);
	pinMode(PIN_LED_YELLOW, OUTPUT);
	pinMode(PIN_POTENTIALMETER_INPUT, INPUT);
	pinMode(PIN_TOUCH_SENSOR_INPUT, INPUT);
}

void loop() {
	potential_red_control();
	touch_sensor_yellow_control();
}

void potential_red_control(){
	int val;
	val = analogRead(PIN_POTENTIALMETER_INPUT);
	analogWrite(PIN_LED_RED, remapPotentialMeter(val));
}

void touch_sensor_yellow_control(){
	int val;
	val = analogRead(PIN_TOUCH_SENSOR_INPUT);
	digitalWrite(PIN_LED_YELLOW, HIGH); // Set digital I/O pin to a 1
	delay(	remapTouchSensor(val)); // Delay
	digitalWrite(PIN_LED_YELLOW, LOW); // Set digital I/O pin to a 0
	delay(	remapTouchSensor(val));
}

int remapPotentialMeter(int val){
	int revised_val;
	revised_val = val/4;
	return revised_val;
}

int remapTouchSensor(int val){
	int remappedValue;
	remappedValue = (double)val/600.0 * 375.0 +125;
	return remappedValue;
}




