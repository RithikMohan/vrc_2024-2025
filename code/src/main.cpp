// main.cpp
#include "main.h"
#include "robot.h"
#include "utils.h"


void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    rotational_sensor.set_position(0);
    intake.set_value(LOW);
    // arm_motor_right.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    // arm_motor_left.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    pros::Task screen_task([&]() {
        while (true) {
            \
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            pros::lcd::print(3, "Version:1.1.12"); // heading
            pros::delay(20);
        }
    });

    pros::Task arm_task([&]() {

        int rotationPosition = 0;

        while (true) {
            bool current_button_L1_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
            if (current_button_L1_state) {        
                
                if(rotationPosition == 0 ){

                    // arm_motor_right.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
                    // arm_motor_left.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

                    arm_motor_left.move(30);
                    arm_motor_right.move(-30);
                    int32_t position = rotational_sensor.get_position() * -1;
                    while(position < 2300){
                        pros::lcd::print(3, "POS 0: %1d", rotational_sensor.get_position()); // x
                        pros::lcd::print(4, "Angle 0: %1d", rotational_sensor.get_angle()); // x

                        pros::delay(20);
                        position = rotational_sensor.get_position() * -1;
                    }
                    arm_motor_left.move(0);//21
                    arm_motor_right.move(0);//21
                    // arm_motor_left.brake();
                    // arm_motor_right.brake();

                    rotationPosition = 1;

                }else if(rotationPosition == 1 ){
                    intake_motor_back.move(0);

                    // arm_motor_left.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
                    // arm_motor_right.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
                    
                    // arm_motor_left.brake();
                    // arm_motor_right.brake();

                    arm_motor_left.move(127);
                    arm_motor_right.move(-127);
                    int32_t position2 = rotational_sensor.get_position() * -1;
                    while(position2 < 13000){
                        pros::lcd::print(4, "POS 1: %1d", rotational_sensor.get_position()); // x
                        pros::lcd::print(4, "Angle 0: %1d", rotational_sensor.get_angle()); // x
                        pros::delay(20);
                        position2 = rotational_sensor.get_position() * -1;
                    }
                    
                    arm_motor_left.move(0);
                    arm_motor_right.move(0); 
                    
                    // arm_motor_left.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
                    // arm_motor_right.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
                    
                    // arm_motor_left.brake();
                    // arm_motor_right.brake();
                 

                    rotationPosition = 2; 
                                   
                }else if(rotationPosition == 2 ){
                    arm_motor_left.move(-60);
                    arm_motor_right.move(60);
                    int32_t position3 = rotational_sensor.get_position() * -1;
                    while(position3 > 400){
                        pros::lcd::print(4, "POS 2: %1d", rotational_sensor.get_position()); // x
                        pros::lcd::print(4, "Angle 0: %1d", rotational_sensor.get_angle()); // x
                        pros::delay(20);
                        position3 = rotational_sensor.get_position() * -1;
                    }
                    arm_motor_left.move(0);
                    arm_motor_right.move(0);
                    rotationPosition = 0;                
                }
            
        }else{
            current_button_L1_state = false;
        }
            pros::delay(20);
        }
    });
}



void disabled() {}

void competition_initialize() {}

void opcontrol() {
    bool intake_running = false; 
    bool arm_running = false;
 
    bool last_button_R1_state = false;
    bool intake_reversed = false;
    bool last_button_R2_state = false;
    bool last_button_down_state = false;
    bool last_button_B_state = false;
    bool last_button_L1_state = false;
    bool last_button_L2_state = false;
    bool last_button_up_state = false;

    bool clamp_state = LOW; 
    bool doinker_state = LOW; 

    
    while (true) {

        // hello
        bool current_button_R1_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
        bool current_button_R2_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
        bool current_button_down_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
        bool current_button_B_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);
        bool current_button_L2_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
        bool current_button_up_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);

        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        chassis.tank(leftY, rightY);


        bool armStarted = false;

        bool intakeStarted = false;

        // if (current_button_R1_state && !last_button_R1_state) {
        //     intake_running = !intake_running;

        //     if (intake_running) {
        //         intake_motor_front.move(127);
        //         intake_motor_back.move(127);
        //     } else {
        //         intake_motor_front.move(0);
        //         intake_motor_back.move(0);
        //         bool intake_running = true;
        //     }
        // }

        
        

        if (current_button_L2_state && !last_button_L2_state) {        
            arm_running = !arm_running;

            if (arm_running) {
                arm_motor_left.move_absolute(-30,5);
                arm_motor_right.move_absolute(30,5);

            } else {
                arm_motor_left.move_absolute(-100,200);
                arm_motor_right.move_absolute(100,200);

                bool arm_running = true;
            }
        }


        if (current_button_R1_state && !last_button_R1_state) {
            intake_running = !intake_running;

            if (intake_running) {
                intake_motor_back.move(75);
            } else {
                intake_motor_back.move(0);
                bool intake_running = true;
            }
        }

        if (current_button_up_state && !last_button_up_state) {
            intake_running = !intake_running;

            if (intake_running) {
                intake_motor_front.move(-127);
            } else {
                intake_motor_front.move(0);
                bool intake_running = true;
            }
        }



        if (current_button_R2_state && !last_button_R2_state) {
            intake_running = !intake_running;

            if (intake_running) {
                intake_motor_front.move(127);
            } else {
                intake_motor_front.move(0);
                bool intake_running = true;
            }
        }

        if (current_button_down_state && !last_button_down_state) {
            clamp_state = !clamp_state; // Toggle the state
           
            if(clamp_state) {
                clamp.set_value(HIGH);
                controller.print(1, 5, "  LOCK");
            } else {
                clamp.set_value(LOW);
                controller.print(1, 5, "NO-LOCK");
            }
        }

        if (current_button_B_state && !last_button_B_state) {
            doinker_state = !doinker_state; // Toggle the state
           
            if(doinker_state) {
                doinker.set_value(HIGH);
                controller.print(1, 5, "  LOCK");
            } else {
                doinker.set_value(LOW);
                controller.print(1, 5, "NO-LOCK");
            }
        }


        // if (current_button_up_state && !last_button_up_state) {
            //intake_state = !intake_state; // Toggle the state
           
            //if(intake_state) {
                //intake.set_value(LOW);
                //controller.print(1, 5, "  LOCK");
            //} else {
                //intake.set_value(HIGH);
                //controller.print(1, 5, "NO-LOCK");
           // }
        // }

        last_button_R1_state = current_button_R1_state;
        last_button_R2_state = current_button_R2_state;
        last_button_L2_state = current_button_L2_state;
        last_button_down_state = current_button_down_state;
        last_button_B_state = current_button_B_state;
        last_button_up_state = current_button_up_state;


        pros::delay(25);

    }
    
}

