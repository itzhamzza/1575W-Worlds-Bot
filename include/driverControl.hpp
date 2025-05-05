#include "pros/rtos.hpp"

void clamping();
void intaking();
void colorSortRed();
inline pros::Task colorSortTaskRed(colorSortRed);
void colorSortBlue();
inline pros::Task colorSortTaskBlue(colorSortBlue);
void antiJam();
//inline pros::Task antiJamTask(antiJam);
void autoClamper();
void autoFlipping();
inline pros::Task colorSortTaskAutoFlip(autoFlipping);
void ladybrownMovement();
void goalClamper();
void intakeExtender();
void doinkerLeft();
void doinkerRight();
