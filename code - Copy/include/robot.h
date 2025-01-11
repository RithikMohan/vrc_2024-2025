// robot.h
#pragma once

#include "lemlib/api.hpp"
#include "pros/imu.h"
#include "pros/motors.h"

// Controller and drivetrain declarations
extern pros::Controller controller;
extern lemlib::Chassis chassis;
extern pros::MotorGroup intake_motors;
extern pros::ADIDigitalOut clamp;
