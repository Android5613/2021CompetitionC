#include "Robot.h"

void Robot::userControl() {
  // For spinning the flywheel. It takes a second or two to get full speed.
  if (DriveStick.GetRawButton(1)) {
    Flywheel.Set(0.9);
  }
  // Else set to 0
  else {
    Flywheel.Set(0);
  }
  // Spin the intake roller.
  if (Buttons.GetRawButton(10)) {
    Grabber.Set(-1);
  }
  // Spin it in reverse to release the power cell.
  else if (Buttons.GetRawButton(7)) {
    Grabber.Set(1);
  }
  // Else set to 0.
  else {
    Grabber.Set(0);
  }
  // Pop the grabber arm out.
  if (Buttons.GetRawButton(3)) {
    Grabber_Arm.Set(1);
  }
  // Move it back.
  else if (Buttons.GetRawButton(6)) {
    Grabber_Arm.Set(-1);
  }
  // Else set to 0
  else {
    Grabber_Arm.Set(0);
  }
  // Set the conveyor forwards.
  if (Buttons.GetRawButton(12)) {
    High_Conveyor.Set(-1);
    Low_Conveyor.Set(1);
  }
  // Set it backwards.
  else if (Buttons.GetRawButton(9)) {
    High_Conveyor.Set(1);
    Low_Conveyor.Set(-1);
  }
  // Else set to 0
  else {
    Low_Conveyor.Set(0);
    High_Conveyor.Set(0);
  }
  // Set the transition wheel to forwards.
  if (Buttons.GetRawButton(11)) {
    Transition.Set(-0.7);
  }
  // Set it to backwards.
  else if (Buttons.GetRawButton(8)) {
    Transition.Set(0.7);
  }
  // Else set to 0
  else {
    Transition.Set(0);
  }
  // If button one is pressed, give the limelight control of the drive.
/*  if (Buttons.GetRawButton(1)) {
    limelight();
  }
  // Else give it to the driver.
  else {
    arcade_drive();
  }*/
}

