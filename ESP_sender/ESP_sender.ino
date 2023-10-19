/*
╔═══╗╔═══╗╔═══╗╔═══╗╔═══╗
║╔══╝║╔═╗║║╔═╗║║╔═╗║║╔═╗║
║╚══╗║╚══╗║╚═╝║╚╝╔╝║╚╝╔╝║
║╔══╝╚══╗║║╔══╝╔╗╚╗║╔═╝╔╝
║╚══╗║╚═╝║║║   ║╚═╝║║║╚═╗
╚═══╝╚═══╝╚╝   ╚═══╝╚═══╝
Kode for å sende verdier fra ESP32, til Arduino Uno.
ESP32-delen.
*/

//Definerer RX, og TX-pinnene
//I denne koden bruker vi ikke RX, da vi kun skal sende, men jeg har
//valgt å inkludere den for å enklere kunne utvide programmet ved behov.
#define RXpin 16 // Merket rx2
#define TXpin 17 // Merket tx2

void setup() {
  //Starter opp seriell-tilkobling
  //Serial er koblingen som vil benyttesmellom ESP32 og PC
  //Serial2 er koblingen som skal brukes mellom ESP32 og Arduino Uno
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXpin, TXpin);
}

void loop() {
  //Sender kontinuerlig tallene 1, 2, og 3 til både PC og Arduino Uno.
  //Serial sendes til PC over USB, mens Serial2 sendes til Arduino Uno over TX2
  Serial.print("Sender ");
  delay(500);
  Serial2.println("35/78");
}
