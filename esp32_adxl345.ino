#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

#define SCL_pin 23
#define SDA_pin 21
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup(void)
{
  Wire.begin(SDA_pin,SCL_pin);
  Serial.begin(115200);
  if(!accel.begin())
  {
    Serial.println("Could not find a valid ADXL345 sensor, check wiring!");
    while(1);
  }
}

void loop(void)
{
  sensors_event_t event;
  accel.getEvent(&event);

  //Serial.print(event.acceleration.x); Serial.print(' ');
  //Serial.print(event.acceleration.y); Serial.print(' ');
  //Serial.println(event.acceleration.z);

  float accelerationX = event.acceleration.x;
  float accelerationY = event.acceleration.y;
  float accelerationZ = event.acceleration.z;

  float roll = atan2(accelerationY, accelerationZ) * 180.0 / PI;
  float pitch = atan2(accelerationX, sqrt(accelerationY * accelerationY + accelerationZ * accelerationZ)) * 180.0 / PI;

  Serial.print(roll);
  Serial.print('/');
  Serial.println(pitch);


  delay(50);
}
