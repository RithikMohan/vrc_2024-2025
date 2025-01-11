// robot.h
#pragma once

#include "lemlib/api.hpp"
#include "pros/imu.h"
#include "pros/motors.h"

// Controller and drivetrain declarations
extern pros::Controller controller;
extern lemlib::Chassis chassis;
extern pros::Motor intake_motor_front;
extern pros::Motor intake_motor_back;
extern pros::Motor arm_motor_right;
extern pros::Motor arm_motor_left;

extern pros::ADIDigitalOut intake;
extern pros::ADIDigitalOut clamp;
extern pros::ADIDigitalOut doinker;
extern pros::Rotation rotational_sensor;

extern pros::IMU inertial;