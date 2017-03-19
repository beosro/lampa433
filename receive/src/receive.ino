#include <RCSwitch.h>

#define LAMPOUT 13

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  pinMode(LAMPOUT, OUTPUT);
  digitalWrite(LAMPOUT, 1);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {

    int value = mySwitch.getReceivedValue();

    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      Serial.print("Received ");
      Serial.print( mySwitch.getReceivedValue() );
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch.getReceivedProtocol() );

      if (value == 16405) {
        digitalWrite(LAMPOUT, 1);
      } else if (value == 16404) {
        digitalWrite(LAMPOUT, 0);
      }
    }

    mySwitch.resetAvailable();
  }
}
