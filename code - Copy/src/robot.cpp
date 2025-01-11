#include "robot.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_motors({-19, -13, -2}, pros::MotorGearset::blue); 
pros::MotorGroup right_motors({16, 15, 14}, pros::MotorGearset::blue); 
pros::MotorGroup intake_motors({10, -4}, pros::MotorGearset::blue);
pros::ADIDigitalOut clamp ('A');


lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                              &right_motors, // right motor group
                              12.25, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 4" omnis
                              360, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

pros::Imu imu(10);

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
lemlib::ControllerSettings angular_controller(11.5, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              6.8, // derivative gain (kD)
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
