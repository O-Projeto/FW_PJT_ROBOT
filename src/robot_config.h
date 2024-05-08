
#define A1
#define A2
#define PWMA

#define B1
#define B2
#define PWMB

#define  ESC_L
#define  ESC_R  

#define QTR_1
#define QTR_2
#define QTR_3
#define QTR_4
#define QTR_5
#define QTR_6
#define QTR_7
#define QTR_8
  



namespace robot_config{
    float const MAX_SPEED = 10;
    float const MIM_SPEED = -10;
}

namespace robot_pins
{
  int brushed_motor_pins_A[3] = {A1,A2,PWMA};
  int brushed_motor_pins_B[3] = {B1,B2,PWMB};
  const int brushless_motor_pins[2] = {ESC_L,ESC_R};

  const uint8_t line_follower_qtr[8] = {QTR_1,QTR_2,QTR_3,QTR_4,QTR_5,QTR_6,QTR_7,QTR_8};
//   const int side_sensor[2] = {L,R};

//   const int mini_sumo_qtr[2] = {QTR_FRONT_L,QTR_FRONT_R};
//   const int mini_sumo_xshut[3] = {XSHUT_1,XSHUT_2,XSHUT_3};

//   const int mini_sumo_IR = IR_PIN; 

//   const int encoder[2] = {ENCODER_L,ENCODER_R};
  
} // namespace robot_pins

namespace robot_mec
{
    const int radios = 0.15; //[m]
    const int lenght = 0.1; // [m]
}
