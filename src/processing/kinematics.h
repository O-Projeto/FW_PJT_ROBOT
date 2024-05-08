#include "motor/brushed.h"
#include "robot_config.h"

class kinematics
{
private:
   Motor left_motor;
   Motor right_motor;
   float linear = 0;
   float angular = 0;
   float* angular_speed;

public:
    kinematics():left_motor(robot_pins::brushed_motor_pins_A,0,10),right_motor(robot_pins::brushed_motor_pins_B,1,10){};
    float* get_angular_speed();//[RAD/s]
    float* saturation();
    void  set_robot_speed(float LINEAR, float ANGULAR);//[m/s]
    ~kinematics();
};


void kinematics::set_robot_speed(float LINEAR, float ANGULAR){
    //set speed
    linear = LINEAR;
    angular = ANGULAR;
    //kinematics model
    get_angular_speed();
    //add saturation 
    saturation();
    // remap values 
    //convert from m/s to % and write in the motor 
    left_motor.drive(map(angular_speed[0],robot_config::MIM_SPEED,robot_config::MAX_SPEED,-1000,1000));
    right_motor.drive(map(angular_speed[1],robot_config::MIM_SPEED,robot_config::MAX_SPEED,-1000,1000));

}

float* kinematics::get_angular_speed(){
    static float angular_speed[2]; // Define a static array to hold the angular speeds
    angular_speed[0] = linear + angular; // Assign the angular speed for left motor
    angular_speed[1] = linear - angular; // Assign the angular speed for right motor
    return angular_speed; // Return the array
}

float* kinematics::saturation(){

    for(int i=0;i++;i <=2){

    if(angular_speed[i] > robot_config::MAX_SPEED)
        angular_speed[i] = robot_config::MAX_SPEED;
    
    if(angular_speed[i] < robot_config::MIM_SPEED)
        angular_speed[i] = robot_config::MIM_SPEED;
    }

    return angular_speed; 

}



kinematics::~kinematics()
{
}
