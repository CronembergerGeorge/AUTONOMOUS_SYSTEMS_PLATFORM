#ifndef SENSORDATA_H
#define SENSORDATA_H

struct SensorData {
    float distance;
    float temperature;
    float humidity;
    bool ultrasonicError;
    bool dhtError;
};
#endif 