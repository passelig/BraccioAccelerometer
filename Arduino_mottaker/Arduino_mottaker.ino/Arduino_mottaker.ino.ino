/*
╔═══╗     ╔╗                  ╔╗ ╔╗        
║╔═╗║     ║║                  ║║ ║║        
║║ ║║╔═╗╔═╝║╔╗╔╗╔╗╔═╗ ╔══╗    ║║ ║║╔═╗ ╔══╗
║╚═╝║║╔╝║╔╗║║║║║╠╣║╔╗╗║╔╗║    ║║ ║║║╔╗╗║╔╗║
║╔═╗║║║ ║╚╝║║╚╝║║║║║║║║╚╝║    ║╚═╝║║║║║║╚╝║
╚╝ ╚╝╚╝ ╚══╝╚══╝╚╝╚╝╚╝╚══╝    ╚═══╝╚╝╚╝╚══╝
Kode for å lese av verdier sendt fra ESP32, til Arduino Uno.
Arduino Uno-delen.
*/

//Man må benytte SoftwareSerial-biblioteket for å kunne
//både lese av data sendt fra ESP32, og å skrive til PC via USB-Serial
#include <SoftwareSerial.h>

//Definerer hvilke pins som benyttes som software-RX og TX pins.
//I denne koden bruker vi ikke TX, da vi kun skal motta, men jeg 
//har valgt å inkludere den for å enklere kunne utvide programmet ved behov.
#define SoftRXpin 10
#define SoftTXpin 11

SoftwareSerial esp32serial(SoftRXpin, SoftTXpin);

void setup() {
  //Definerer at RX er en input, og TX er en output.
  pinMode(SoftRXpin, INPUT);
  pinMode(SoftTXpin, OUTPUT);
  
  //Starter opp både USB-seriell (Arduino Uno <-> PC) og software-seriell (Arduino Uno <-> ESP32)
  Serial.begin(115200);
  esp32serial.begin(9600);
}

void loop() {

  if (esp32serial.available() > 0) {
    char receivedChar = esp32serial.read();
    Serial.print(receivedChar);
  }
  // Add other code or logic here as needed
}