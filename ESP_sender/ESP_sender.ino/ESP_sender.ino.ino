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
#define rx2Pin 16 // Merket rx2
#define tx2Pin 17 // Merket tx2

void setup() {
  //Starter opp seriell-tilkobling
  //Serial er koblingen som vil benyttesmellom ESP32 og PC
  //Serial2 er koblingen som skal brukes mellom ESP32 og Arduino Uno
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, rx2Pin, tx2Pin);
}

void loop() {
  //Sender kontinuerlig rollAndPitch til både PC og Arduino Uno.
  //Serial sendes til PC over USB, mens Serial2 sendes til Arduino Uno over TX2
  int roll = random(40, 51);
  int pitch = random(40, 51);
  String rollAndPitch = String(roll) + "/" + String(pitch) + ";";
  Serial.println(rollAndPitch);
  Serial2.println(rollAndPitch);
  //delay(10);
}