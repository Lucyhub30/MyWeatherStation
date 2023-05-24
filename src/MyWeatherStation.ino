/*
 * Project MyWeatherStation
 * Description:
 * Author:
 * Date:
 */

// setup() runs once, when the device is first turned on.
#include "Adafruit_BME280.h"
Adafruit_BME280 bme;
int temp = 0;
int humidity = 0;
int pressure = 0;
int altitude = 0;
void setup() {
  // Put initialization like pinMode and begin functions here.
  bme.begin();
  Particle.variable("temp", temp);
  Particle.variable("humidity", humidity);
  Particle.variable("pressure", pressure);
  Particle.variable("altitude", altitude);
  Particle.publish("testing");
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  temp = (int)bme.readTemperature();
  humidity = (int)bme.readHumidity();
  pressure = (int)bme.readPressure();
  altitude = (int)bme.readAltitude(1013.25); //sea level pressure, estimates altitude

}