
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  mySwitch.enableTransmit(D7);
}

void loop() {
  mySwitch.send(16404, 24); // off
  delay(500);
  mySwitch.send(16405, 24); // on
  delay(500);
}
