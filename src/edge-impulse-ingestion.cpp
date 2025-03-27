/*
 * Project Edge Impulse ingestion example
 * Author: Eric Pietrowicz
 * Date: 03/27/2025
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "temperature/temperature.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

SerialLogHandler logHandler(LOG_LEVEL_INFO);

TemperatureReading temperatureReading = {0.0, 0.0};

// setup() runs once, when the device is first turned on
void setup()
{
  // Put initialization like pinMode and begin functions here
}

void loop()
{
  readTemperature(&temperatureReading);
  Log.info("Temperature reading: %f", temperatureReading.degreesF);
  Particle.publish("training-data", temperatureReading.degreesF);
  delay(15000);
}
