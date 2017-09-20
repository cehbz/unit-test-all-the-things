#ifndef DHTTESTER_H
#define DHTTESTER_H

#include <DHT.h>

template <class DHTImpl>
class DHTtester {
private:
  DHTImpl* dht;
public:
  DHTtester(DHTImpl* d) : dht(d) {}
  void setup() {
    Serial.begin(9600);
    Serial.println("DHTxx test!");

    dht.begin();
  }
}

#endif
