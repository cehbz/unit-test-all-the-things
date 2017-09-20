#include "arduino-mock/DHT.h"

static DHTMock* p_DHTMock = NULL;
DHTMock* DHTMockInstance() {
  if (!p_DHTMock) {
    p_DHTMock = new DHTMock();
  }
  return p_DHTMock;
}

void releaseDHTMock() {
  if (p_DHTMock) {
    delete p_DHTMock;
    p_DHTMock = NULL;
  }
}

void DHT_::begin() {
  p_DHTMock->begin();
}

float DHT_::readTemperature(bool S, bool force) {
  return p_DHTMock->readTemperature(S, force);
};

float DHT_::convertCtoF(float C) {
  return p_DHTMock->convertCtoF(C);
};

float DHT_::convertFtoC(float F) {
  return p_DHTMock->convertFtoC(F);
};

float DHT_::computeHeatIndex(float temperature, float percentHumidity, bool isFahrenheit) {
  return p_DHTMock->computeHeatIndex(temperature, percentHumidity, isFahrenheit);
};

float DHT_::readHumidity(bool force) {
  return p_DHTMock->readHumidity(force);
};

boolean DHT_::read(bool force) {
  return p_DHTMock->read(force);
};

// Preinstantiate Objects
DHT_ DHT;
