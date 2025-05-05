#pragma once

// #include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');


inline pros::Motor ladyBrown(20, pros::v5::MotorGears::green);

inline pros::MotorGroup intake({-11,-14}, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);

inline pros::Distance distance_sens(18);

inline pros::Rotation rotation_sens(18);

inline pros::Optical color_sens(10);

inline pros::adi::DigitalOut clamper('B', 0);

inline pros::adi::DigitalOut goalClamp('C', 0);

inline pros::adi::DigitalOut armPiston('A', 0);

inline pros::adi::DigitalOut doinkLeft('D', 0);
inline pros::adi::DigitalOut doinkRight('C', 0);

inline pros::adi::DigitalIn limitSwitchColorSort('A');

inline pros::adi::DigitalIn autoSelector('E');