#include "AnalogSmoother.h"

AnalogSmoother analog(A0);

void setup() {
	Serial.begin(115200);
}

void loop() {
	Serial.print(analogRead(A0));
	Serial.print(",");
	Serial.println(analog.read());
	delay(10);
}
