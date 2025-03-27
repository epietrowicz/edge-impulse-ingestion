/*
 * Project myProject
 * Author: Your Name
 * Date:
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
  // The core of your code will likely live here.
  readTemperature(&temperatureReading);
  Log.info("Temperature reading: %f", temperatureReading.degreesF);
  delay(15000); // Delay for 1 second to avoid flooding the logs
  Particle.publish("training-data", temperatureReading.degreesF);
}
