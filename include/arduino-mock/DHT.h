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

class DHTMock {
public:
  MOCK_METHOD0(begin, void());
  MOCK_METHOD2(readTemperature, float(bool, bool));
  MOCK_METHOD1(convertCtoF, float(float));
  MOCK_METHOD1(convertFtoC, float(float));
  MOCK_METHOD3(computeHeatIndex, float(float, float, bool));
  MOCK_METHOD1(readHumidity, float(bool));
  MOCK_METHOD1(read, boolean(bool));
};

DHTMock* DHTMockInstance();
void releaseDHTMock();

#endif
