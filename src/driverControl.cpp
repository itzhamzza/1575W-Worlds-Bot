#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "autons.hpp"

void clamping(){

    if(master.get_digital(DIGITAL_Y)){
        //clamps on
        clamper.set_value(true);
        

    }
    else if(master.get_digital(DIGITAL_RIGHT)){
        //clamps off
        
        clamper.set_value(false);
        
        
    }

}
bool sortering = false;
bool intakeInProcess = false;
void intaking(){
    if(master.get_digital(DIGITAL_R2) && sortering == false){

        //intakes in
        intake.move_velocity(-1200);
        intakeInProcess = true;
        
    }
    else if(master.get_digital(DIGITAL_R1)){

        //intakes out
        intake.move_velocity(600);
        
    }
    else if (sortering == false){
        intake.move_velocity(0);
        intakeInProcess = false;
        //intake.set_brake_mode(MOTOR_BRAKE_COAST);
        

    }
}
int intakeSpeed = -1;
void antiJam(){
    while (true){
        intakeSpeed = intake.get_actual_velocity();
        if (intakeInProcess == true){
            if (intakeSpeed == 0) {
                sortering = true;
                intake.move(127);
                pros::delay(200);
                intake.move(-127);
                sortering = false;
            }
            
        }
        pros::delay(10);
    }
}
void colorSortRed(){
    while(true){
         // //THIS THORWS OUT RED
       
        if (color_sens.get_hue() < 13 && color_sens.get_hue() > 8){
            
            while (!(distance_sens.get_distance() < 50)){
             pros::delay(10);
            }
            sortering = true;
             intake.move_velocity(1200);
             pros::delay(700);
             sortering = false;
        }
          pros::delay(50);
    }
}
void colorSortBlue(){
     //THIS THROWS OUT BLUE
       while(true) {
             if (color_sens.get_hue() < 230 && color_sens.get_hue() > 210){
                while (!(distance_sens.get_distance() < 50)){
                    pros::delay(5);
                   }
                   sortering = true;
                    intake.move_velocity(1200);
                    pros::delay(700);
                    sortering = false;
          }
        
        pros::delay(50);
        }
}


void autoFlipping(){

    while (true){
        if (autoSelector.get_new_press()){
            //pros::delay(500);
            ez::as::page_up();
            
        }
        pros::delay(50);
    }
    pros::delay(50);
}
int stage = 0;

void ladybrownMovement(){
    

        if(master.get_digital_new_press(DIGITAL_L1)){
            //arm up
            if (stage == 0){
                ladyBrown.set_brake_mode(MOTOR_BRAKE_HOLD);
                intake.set_brake_mode(MOTOR_BRAKE_HOLD);
            
                ladyBrown.move_absolute(-230, 200);
               
                stage++;
            }
            else if(stage == 1){
                intake.move_relative(1000,200);
                ladyBrown.move_absolute(-1200, 200);
                
            
               stage++;
            }
            else if(stage == 2){
                ladyBrown.move_absolute(-1600, 200);
               stage++;
            }

            
        }
        else if(master.get_digital_new_press(DIGITAL_L2)){
            //arm down
        
            ladyBrown.move_absolute(7, 200);
            ladyBrown.set_brake_mode(MOTOR_BRAKE_COAST);
            intake.set_brake_mode(MOTOR_BRAKE_COAST);
            
            stage = 0;
        }
        pros::delay(100);
}

int toggle = 0;
void goalClamper(){
    if(master.get_digital(DIGITAL_LEFT) && toggle ==0){
      goalClamp.set_value(true);
      toggle++;
      pros::delay(100);
    }
    else if(master.get_digital(DIGITAL_LEFT) && toggle ==1){
        goalClamp.set_value(false);
      toggle--;
      pros::delay(100);
    }

}
void intakeExtender(){
    if(master.get_digital_new_press(DIGITAL_X)){
        //Arm Extender
        armPiston.set_value(true);
       
    }
    else if(master.get_digital_new_press(DIGITAL_A)){
        //Arm Extender Off
        armPiston.set_value(false);
        
    }
}
int toggle2 = 0;
void doinkerLeft(){

    if(master.get_digital(DIGITAL_LEFT) && toggle2 == 0){
        //clamps on
      doinkLeft.set_value(true);
        toggle2++;
        pros::delay(100);

    }
    else if(master.get_digital(DIGITAL_LEFT) && toggle2 == 1){
        //clamps off
        doinkLeft.set_value(false);
        toggle2--;
        pros::delay(100);
    }

}
int toggle3 = 0;
void doinkerRight(){

    if(master.get_digital(DIGITAL_DOWN) && toggle3 == 0){
        //clamps on
      doinkRight.set_value(true);
        toggle3++;
        pros::delay(100);

    }
    else if(master.get_digital(DIGITAL_DOWN) && toggle3 == 1){
        //clamps off
        doinkRight.set_value(false);
        toggle3--;
        pros::delay(100);
    }

}