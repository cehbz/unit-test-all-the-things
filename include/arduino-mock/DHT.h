// Header for DHT Mock

#ifndef DHT_H
#define DHT_H

#include <gmock/gmock.h>

// Define types of sensors.
#define DHT11 11
#define DHT22 22
#define DHT21 21
#define AM2301 21


class DHT_ {
public:
  void begin();
  float readTemperature(bool S=false, bool force=false);
  float convertCtoF(float);
  float convertFtoC(float);
  float computeHeatIndex(float temperature, float percentHumidity, bool isFahrenheit=true);
  float readHumidity(bool force=false);
  boolean read(bool force=false);
};

extern DHT_ DHT;

class DHTMock : public DHT_ {
public:
  MOCK_METHOD0(begin, void());
  MOCK_METHOD2(readTemperatureImpl, float(bool, bool));
  virtual float readTemperature(bool S=false, bool force=false) { return readTemperatureImpl(S, force); }
  MOCK_METHOD1(convertCtoF, float(float));
  MOCK_METHOD1(convertFtoC, float(float));
  MOCK_METHOD3(computeHeatIndexImpl, float(float, float, bool));
  virtual float computeHeatIndex(float temperature, float percentHumidity, bool isFahrenheit=true) { return computeHeatIndexImpl(temperature, percentHumidity, isFahrenheit); };
  MOCK_METHOD1(readHumidityImpl, float(bool));
  virtual float readHumidity(bool force=false) { return readHumidityImpl(force); }
  MOCK_METHOD1(readImpl, boolean(bool));
  virtual boolean read(bool force=false) { return readImpl(force); };
};

DHTMock* DHTMockInstance();
void releaseDHTMock();

#endif
