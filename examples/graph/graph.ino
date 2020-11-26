#include "AnalogSmoother.h"

AnalogSmoother sensor(A0);

void setup() {
	Serial.begin(115200);
	sensor.fill();
}

void loop() {
	Serial.print(analogRead(A0));
	Serial.print(" ");
	Serial.println(sensor.read());
	delay(10); // Slow down the serial output
}
