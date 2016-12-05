// ESP AT Commands Test
// Written by Spencer Kulbacki
// For thimble.io

// July 5th 2016
// Connect your ESP like so:
// GND -> GND
// 3.3v -> VCC (You should really use a 3.3v regualtor that can supportt at least 200mA, 
//                        most arduinos can't supply more than 150mA from their 3.3v regualtors)
// A3 -> TX
// A2 -> RX

#include <SoftwareSerial.h>
SoftwareSerial ESPSerial(A3, A2); // RX, TX  This can be any two pins on your Arduino

void setup() {
  Serial.begin(115200);           //change to 9600 after you run the AT+UART_DEF comand
  Serial.println("ESP Test:");
  ESPSerial.begin(115200);      //change to 9600 after you run the AT+UART_DEF comand
  Serial.print("Type AT and you should recieve OK.\nType AT+GMR and you should see the version information of your ESP.\n");
  Serial.print("Make sure to run this command: \nAT+UART_DEF=9600,8,1,0,0");
} //end Setup

void loop() {
  if (ESPSerial.available())
    Serial.write(ESPSerial.read());

  if (Serial.available())
    ESPSerial.write(Serial.read());
} //end loop


