#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

class DHTSensor {

public:

    void begin();
    void update();

    float getTemperature();
    float getHumidity();

    bool hasError();

};

#endif