// autonomous.cpp
#include "main.h"
#include "robot.h"


void intake_front(int speed){
    intake_motor_front.move(127);
}

void intake_back(){
    intake_motor_back.move(-100);
}

void intakeStop_back(){
    intake_motor_back.move(0);
}

void intakeStop_front(){
    intake_motor_front.move(0);
}

void doinkerOut(){
    doinker.set_value(HIGH);

} 

void doinkerIN(){
    doinker.set_value(LOW);
}

void clampOut(){
    clamp.set_value(HIGH);
}

void clampIn(){
    clamp.set_value(LOW);
}

void autonomous3() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 15, 1000, {.maxSpeed = 70}, false);
    chassis.turnToPoint(-10, 16, 1000, {.maxSpeed = 70}, false);
    // intakeForward(80);
    pros::delay(200);
    chassis.moveToPoint(4, 15, 1000, {.maxSpeed = 5});
    pros::delay(1000);
    //at team stake
    chassis.moveToPoint(4.5, 14, 1000, {.maxSpeed = 80}, false);
    chassis.moveToPoint(5, 14, 1000, {.maxSpeed = 80}, false);
    pros::delay(100);
    // intakeStop();

    //moving away from the team stake
    chassis.moveToPoint(-6, 14, 1000, {.maxSpeed = 60}, false);
    pros::delay(100);
    


    clampOut();
    chassis.moveToPoint(-6, -12, 1000,{.forwards = false, .maxSpeed = 80}, false);

    //going to yellow stake
    chassis.turnToPoint(-28, -5, 1000, {.forwards = false, .maxSpeed = 60}, false);
    chassis.moveToPoint(-34, -7, 2000,{.forwards = false, .maxSpeed = 60}, false);

    
    //clamping yellow stake
    clampIn();
    pros::delay(100);

    // intakeForward(127);

    //going to intaked ring
    chassis.turnToPoint(-38, -20, 1000, {.maxSpeed = 60}, false);
    chassis.moveToPoint(-38, -26, 1000, {.maxSpeed = 80}, false);


    //chassis.moveToPoint(-40, -30, 1000, {.maxSpeed = 60}, false);

    chassis.turnToPoint(-50, -24, 1000);
    chassis.moveToPoint(-50, -24, 1000, {.maxSpeed = 80}, false);
    pros::delay(500);

    chassis.turnToPoint(-48, 16, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(-48, 16, 1000, {.forwards = false, .maxSpeed = 80});
    clampOut();
    chassis.moveToPoint(-48, 6, 1000, {.forwards = false, .maxSpeed = 80});
}

void autonomous_old(){
    chassis.setPose(0, 0, 0);
    pros::delay(7000);
    chassis.moveToPoint(0, 15, 1000, {.maxSpeed = 70}, false);
    chassis.turnToPoint(-10, 16, 1000, {.maxSpeed = 70}, false);
    // intakeForward(80);
    pros::delay(200);
    chassis.moveToPoint(4, 15, 1000, {.maxSpeed = 5});
    pros::delay(1000);
    //at team stake
    chassis.moveToPoint(4.5, 14, 1000, {.maxSpeed = 80}, false);
    chassis.moveToPoint(5, 14, 1000, {.maxSpeed = 80}, false);
    pros::delay(100);
    // intakeStop();

    //moving away from the team stake
    chassis.moveToPoint(-6, 14, 1000, {.maxSpeed = 60}, false);
    pros::delay(100);
}

void autonomous2() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 15, 1000, {.maxSpeed = 70}, false);
    chassis.turnToPoint(10, 16, 1000, {.maxSpeed = 70}, false);
    // intakeForward(80);
    pros::delay(200);
    chassis.moveToPoint(-4, 15, 1000, {.maxSpeed = 5});
    pros::delay(1000);
    //at team stake
    chassis.moveToPoint(-4.5, 14, 1000, {.maxSpeed = 80}, false);
    chassis.moveToPoint(-5, 14, 1000, {.maxSpeed = 80}, false);
    pros::delay(100);
    // intakeStop();

    //moving away from the team stake
    chassis.moveToPoint(6, 14, 1000, {.maxSpeed = 60}, false);
    pros::delay(100);
    


    clampOut();
    chassis.moveToPoint(6, -12, 1000,{.forwards = false, .maxSpeed = 80}, false);

    //going to yellow stake
    chassis.turnToPoint(28, -5, 1000, {.forwards = false, .maxSpeed = 60}, false);
    chassis.moveToPoint(34, -9, 2000,{.forwards = false, .maxSpeed = 60}, false);

    
    //clamping yellow stake
    clampIn();
    pros::delay(100);

    // intakeForward(127);

    //going to intaked ring
    chassis.turnToPoint(38, -28, 1000, {.maxSpeed = 60}, false);
    chassis.moveToPoint(38, -28, 1000, {.maxSpeed = 80}, false);


    //chassis.moveToPoint(-40, -30, 1000, {.maxSpeed = 60}, false);

    chassis.turnToPoint(50, -26, 1000);
    chassis.moveToPoint(44, -26, 1000, {.maxSpeed = 80}, false);
    pros::delay(500);

    chassis.turnToPoint(48, 14, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(48, 14, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(48, 6, 1000, {.forwards = false, .maxSpeed = 80});
}

void autonomous1(){
    // intakeForward(127);
}




// AUTON CODE FOR COMP 2


void autonomous(){
    // intakeForward(127);
    chassis.setPose(0, 0, 0);
    chassis.turnToPoint(76, 163, 1000);

}

