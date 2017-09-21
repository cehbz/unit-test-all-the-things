#include "gtest/gtest.h"
#include "arduino-mock/Arduino.h"
#include "arduino-mock/DHT.h"
#include "arduino-mock/Serial.h"
// #include "arduino-mock/serialHelper.h"
#include "../DHTtester.h"

// https://github.com/google/googletest/blob/master/googlemock/docs/CookBook.md#knowing-when-to-expectusing ::testing::_;
using ::testing::Matcher;
// using ::testing::Invoke;

TEST(DHTtester, setup) {
  SerialMock* serialMock = serialMockInstance();
  DHTMock* dhtMock = DHTMockInstance();
  DHTtester<DHTMock> dhttester(dhtMock);

  EXPECT_CALL(*serialMock, begin(_));
  EXPECT_CALL(*dhtMock, begin());

  dhttester.setup();

  releaseDHTMock();
  releaseSerialMock();
}

TEST(DHTtester, loop) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  SerialMock* serialMock = serialMockInstance();
  DHTMock* dhtMock = DHTMockInstance();
  DHTtester<DHTMock> dhttester(dhtMock);

  float humidity = 55.5;
  float tempC = 22.2;
  float tempF = 77.7;
  float hiC = 33.3;
  float hiF = 44.4;

  EXPECT_CALL(*arduinoMock, delay(_));

  EXPECT_CALL(*dhtMock, readHumidityImpl(false)) // not forced
    .WillOnce(Return(humidity));
  EXPECT_CALL(*dhtMock, readTemperatureImpl(false, false)). // celsius, not forced
    WillOnce(Return(tempC));
  EXPECT_CALL(*dhtMock, readTemperatureImpl(true, false)). // farehnheit, not forced
    WillOnce(Return(tempF));
  EXPECT_CALL(*dhtMock, computeHeatIndexImpl(tempF, humidity, true)) // fahrenheit, humidty %, f
    .WillOnce(Return(hiF));
  EXPECT_CALL(*dhtMock, computeHeatIndexImpl(tempC, humidity, false)) // cesius, humidity %, c
    .WillOnce(Return(hiC));

  EXPECT_CALL(*serialMock, print(Matcher<double>(humidity), _));
  EXPECT_CALL(*serialMock, print(Matcher<double>(tempC), _));
  EXPECT_CALL(*serialMock, print(Matcher<double>(tempF), _));
  EXPECT_CALL(*serialMock, print(Matcher<double>(hiC), _));
  EXPECT_CALL(*serialMock, print(Matcher<double>(hiF), _));

  EXPECT_CALL(*serialMock, print(Matcher<const char*>(_)))
    .Times(AtLeast(1));
  EXPECT_CALL(*serialMock, println(Matcher<const char*>(_)))
    .Times(AtLeast(1));

  dhttester.loop();

  releaseDHTMock();
  releaseSerialMock();
  releaseArduinoMock();
}
