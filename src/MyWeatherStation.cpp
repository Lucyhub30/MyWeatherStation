/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/lucy/Desktop/project/MyWeatherStation/src/MyWeatherStation.ino"
/*
 * Project MyWeatherStation
 * Description: A level project cycle 1
 * Author: Lucy Smith
 * Date: 24/05/23
 */

#include "Adafruit_BME280.h"

void setup();
void loop();
#line 10 "/Users/lucy/Desktop/project/MyWeatherStation/src/MyWeatherStation.ino"
Adafruit_BME280 bme;

//initialising variables for BME280 sensor
int temp = 0;
int humidity = 0;
int pressure = 0;
int altitude = 0;

void setup() {
  bme.begin();

  //set variables of particle dashboard
  Particle.variable("temp", temp);
  Particle.variable("humidity", humidity);
  Particle.variable("pressure", pressure);
  Particle.variable("altitude", altitude);

  Particle.publish("Weather Station Online :)");
}


void loop() {

  temp = (int)bme.readTemperature();
  humidity = (int)bme.readHumidity();
  pressure = (int)bme.readPressure();
  altitude = (int)bme.readAltitude(1013.25); //sea level pressure, estimates altitude

  Particle.publish("testing");

}