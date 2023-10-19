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

SoftwareSerial mySerial(SoftRXpin, SoftTXpin);

void setup() {
  //Definerer at RX er en input, og TX er en output.
  pinMode(SoftRXpin, INPUT);
  pinMode(SoftTXpin, OUTPUT);
  
  //Starter opp både USB-seriell (Arduino Uno <-> PC) og software-seriell (Arduino Uno <-> ESP32)
  Serial.begin(115200);
  mySerial.begin(9600);
}

void loop() {

  //Kontrollerer at SoftwareSerial-porten er ledig, og skriver den ut til USB-seriellporten
  if(mySerial.available()){
    String mottatt = mySerial.readString();
    Serial.println("Følgende er mottatt:");
    Serial.println(mottatt);
  }
}
