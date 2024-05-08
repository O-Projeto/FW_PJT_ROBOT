#include <Arduino.h>
#include <processing/kinematics.h>
#include <sensor/sensors.h>
#include <control/controller.h>



#define BRUSHED 
// #define BRUSHELESS

kinematics robot_move;
Sensors robot_sensors(true); 
Controller pid_angular(0,0,0);



void setup() {
  
  
}

void loop() {

  robot_move.set_robot_speed(1,pid_angular.output(3500,robot_sensors.getLinePosition()));

}

