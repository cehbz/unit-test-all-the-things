#include "gtest/gtest.h"
#include "arduino-mock/DHT.h"
#include "arduino-mock/Arduino.h"


using ::testing::Return;
TEST(DHTTest, access) {
  bool S = true;
  bool force = true;
  float tempC = 22.0;
  float tempF = 78.0;
  float pctH = 10.0;
  bool isFahrenheit = false;

  DHTMock* mock = DHTMockInstance();

  EXPECT_CALL(*mock, begin());
  EXPECT_CALL(*mock, readTemperatureImpl(S, force));
  EXPECT_CALL(*mock, readTemperatureImpl(S, false));
  EXPECT_CALL(*mock, readTemperatureImpl(false, false));
  EXPECT_CALL(*mock, convertCtoF(tempC));
  EXPECT_CALL(*mock, convertFtoC(tempF));
  EXPECT_CALL(*mock, computeHeatIndexImpl(tempC, pctH, isFahrenheit));
  EXPECT_CALL(*mock, computeHeatIndexImpl(tempF, pctH, true));
  EXPECT_CALL(*mock, readHumidityImpl(force));
  EXPECT_CALL(*mock, readHumidityImpl(false));
  EXPECT_CALL(*mock, readImpl(force));
  EXPECT_CALL(*mock, readImpl(false));

  DHT.begin();
  DHT.readTemperature(S, force);
  DHT.readTemperature(S);
  DHT.readTemperature();
  DHT.convertCtoF(tempC);
  DHT.convertFtoC(tempF);
  DHT.computeHeatIndex(tempC, pctH, isFahrenheit);
  DHT.computeHeatIndex(tempF, pctH);
  DHT.readHumidity(force);
  DHT.readHumidity();
  DHT.read(force);
  DHT.read();

  releaseDHTMock();
}
