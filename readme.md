# Unit Test All the Things
Git repo and slides for talk at Yow Connect! Sep 2017

run `install.sh` to get Google Test, Google Mock, and arduino-mock, and run the tests
`git checkout .` to put back our local changes
`./build.sh` to run the tests with our local changes

`DHTtester.ino` and `DHTtester.h` are the Adafruit DHT tester app, refactored to allow for mock injection.
besides that, this repo contains a mock for the DHT library, and unit tests for the sample app (look at what build.sh does)

`talk.slide` are the sources for the slides in go `present` format. To view them install go `present`
`go get -u -v golang.org/x/tools/cmd/present`
and run `present` in this directory

or visit [[ https://go-talks.appspot.com/github.com/charles-haynes/unit-test-all-the-things/talk.slide#1]]
