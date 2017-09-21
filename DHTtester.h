#ifndef DHTTESTER_H
#define DHTTESTER_H

#include <DHT.h>

// START OMIT
template <class DHTImpl>
class DHTtester {
private:
  DHTImpl* dht;
public:
  DHTtester(DHTImpl* d) : dht(d) {}
  void setup();
  void loop();
};

template <class DHTImpl>
void DHTtester<DHTImpl>::setup() {
  {
    Serial.begin(9600);
    Serial.println("DHTxx test!");

    dht->begin();
  }
}
// END OMIT

template <class DHTImpl>
void DHTtester<DHTImpl>::loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht->readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht->readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht->readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht->computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht->computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
}

#endif
