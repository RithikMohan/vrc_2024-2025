// main.cpp
#include "main.h"
#include "robot.h"
#include "utils.h"


void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    pros::Task screen_task([&]() {
        while (true) {
            \
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            pros::delay(20);
        }
    });
}

void disabled() {}

void competition_initialize() {}

void opcontrol() {
    bool intake_running = false; 
 
    bool last_button_R1_state = false;
    bool intake_reversed = false;
    bool last_button_R2_state = false;
    bool last_button_down_state = false;
    bool clamp_state = HIGH; 
    while (true) {
        
        // hello
        bool current_button_R1_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
        bool current_button_R2_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
        bool current_button_down_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);

        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        chassis.tank(leftY, rightY);


        bool intakeStarted = false;

        if (current_button_R1_state && !last_button_R1_state) {
            intake_running = !intake_running;

            if (intake_running) {
                intake_motors.move(127);
            } else {
                intake_motors.move(0);
                bool intake_running = true;
            }
        }

        if (current_button_R2_state && !last_button_R2_state) {
            intake_running = !intake_running;

            if (intake_running) {
                intake_motors.move(-127);
            } else {
                intake_motors.move(0);
                bool intake_running = true;

            }
        }

        if (current_button_down_state && !last_button_down_state) {
            clamp_state = !clamp_state; // Toggle the state
           
            if(clamp_state) {
                clamp.set_value(LOW);
                controller.print(1, 5, "  LOCK");
            } else {
                clamp.set_value(HIGH);
                controller.print(1, 5, "NO-LOCK");
            }
        }

        last_button_R1_state = current_button_R1_state;
        last_button_R2_state = current_button_R2_state;
        last_button_down_state = current_button_down_state;

        pros::delay(25);

    }
    
}

