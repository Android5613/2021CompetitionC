#include "Robot.h"

void Robot::userControl() {

  // For spinning the flywheel in "shooting mode". It takes a second or two to get full speed.
  if (DriveStick.GetRawButton(1)) {
    Flywheel.Set(1);   //inverted motor
  }
  else if (DriveStick.GetRawButton(2)) {  //reverses shooter at 30% power to clear jams
    Flywheel.Set(-.3);
  }
  else {
    Flywheel.Set(0);  //else turn  off
  }
  
////////////////////////////////////////////////////////////////
  // Spin the intake roller
  if (Buttons.GetRawButton(12)) {
    Grabber.Set(-1);    //inverted motor
  }
  //reverses rollers to clear jams
  else if (Buttons.GetRawButton(9)) { 
    Grabber.Set(1);
  }
  //else turn off
  else {
    Grabber.Set(0); 
  }
////////////////////////////////////////////////////////////////
  // Deploy inatke arm
  if (Buttons.GetRawButton(10)) {
    Grabber_Arm.Set(-.5);   //inverted motor; doesn't need full speed (especially since gravity helps)
  }
  // Retract intake arm
  else if (Buttons.GetRawButton(7)) {
    Grabber_Arm.Set(.6);
  }
  // Else set to 0
  else {
    Grabber_Arm.Set(0);
  }
////////////////////////////////////////////////////////////////
  // Spin carousel ccw
  if (Buttons.GetRawButton(11)) {
    Carousel.Set(.35);   //Carousel shouldn't run full speed, might break; try 40%
  }
  // Spin carousel cw
  else if (Buttons.GetRawButton(8)) {
    Carousel.Set(-.35);
  }
  // Else set to 0
  else {
    Carousel.Set(0);
  }
////////////////////////////////////////////////////////////////
  // Set the transition wheel to forwards (intaking).
  if (DriveStick.GetRawButton(3)) {
    Transition.Set(-1);   //inverted motor
    DoubleSolenoid.Set(frc::DoubleSolenoid::Value::kReverse);
  }
  // Set it to backwards.
  else if (DriveStick.GetRawButton(4)) {
    Transition.Set(.7);    //reverse does not need full speed
  }
  // Else set to 0
  else {
    Transition.Set(0);
    DoubleSolenoid.Set(frc::DoubleSolenoid::Value::kForward);
  }
  ////////////////////////////////////////////////////////////////

  // If button one is pressed, give the limelight control of the drive.
/*  if (ButtonPad.GetRawButton(1)) {
    limelight();
  }
  // Else give it to the driver.
  else {
    arcade_drive();
  }*/
 
}

