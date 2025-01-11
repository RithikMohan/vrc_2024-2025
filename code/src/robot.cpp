#include "robot.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_motors({-13, -15, 12}, pros::MotorGearset::blue); 
pros::MotorGroup right_motors({10, 2, -9}, pros::MotorGearset::blue); 
pros::Motor intake_motor_front(4, pros::MotorGearset::blue);
pros::Motor intake_motor_back(3, pros::MotorGearset::blue);
pros::Motor arm_motor_right(20, pros::MotorGearset::blue);
pros::Motor arm_motor_left(19, pros::MotorGearset::blue);
pros::Rotation rotational_sensor (21);

pros::ADIDigitalOut clamp ('B');
pros::ADIDigitalOut intake ('H');
pros::ADIDigitalOut doinker ('A');


lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                              &right_motors, // right motor group
                              10.5, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 4" omnis
                              360, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

pros::Imu imu(18);

lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(30, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              8, // derivative gain (kD)
                                              3, // anti windu
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(35, // proportional gain (kP)
                                              20, // integral gain (kI)
                                              100, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in degrees
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in degrees
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors
);
