#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

class UltrasonicSensor {
public:
    void begin();
    void update();
    float getDistance();
    bool hasError();

};

#endif // ULTRASONIC_SENSOR_H