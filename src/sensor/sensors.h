
#include "line/QTRSensors.h"
#include "robot_config.h"


class Sensors
{
private:
    QTRSensors line_sensor;
    bool line_black; 
    uint16_t lineValues[8];
    uint16_t position;

public:
    Sensors(bool line_black):line_sensor(){};

    uint16_t getLinePosition();
    ~Sensors();
};

Sensors::Sensors(bool line_black)
{   
    this->line_black = line_black; 
    line_sensor.setTypeAnalog();
    line_sensor.setSensorPins(robot_pins::line_follower_qtr,8 );
    //calibration 
    for (uint16_t i = 0; i < 400; i++)
    {
        line_sensor.calibrate();
    }
}

uint16_t Sensors::getLinePosition( ){
    if(line_black){

        return line_sensor.readLineBlack(lineValues);

    }else{

        return line_sensor.readLineBlack(lineValues);
    }
    
}

Sensors::~Sensors()
{
}
