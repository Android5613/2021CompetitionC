/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

// Importing code to run the robot.
// Imports from the frc wpilib library.
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Timer.h>
#include <frc/Spark.h>
#include <frc/Joystick.h>
#include <frc/Compressor.h>
#include <frc/PWMSparkMax.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Encoder.h>

// Importing camera server.
#include "cscore_cpp.h"

// Importing networktables for the limelight camera and vision processing system.
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

// Import ctre libraries. Requires the ctre libraries to be set up. Allows for CAN bus motor controllers, among other things.
#include "ctre/Phoenix.h"


class Robot : public frc::TimedRobot
{
  // everything in the public section is accessable to things outside the class.
public:
  Robot();
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

private:
  // Includes the functions in the private section so they can use the variables.

  void AutonomousPeriodic() override;
  // Drive the robot.
  void arcade_drive(void);
  // Takes user input.
  void userControl(void);
  // Targeting with the limelight.
  void limelight(void);
  // limelight customized for the autonomous.
  void limelightauto(void);

  // Defines a timer.
  frc::Timer time;

  ///////////////////////////////////////////////////////////////

  // Defines the network table that is used by the limelight.
  std::shared_ptr<NetworkTable> limelighttable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

  // A constant
  float f = 1;
  // Aiming constant affected by f
  float KpAim = -0.1f;
  // Movement constant affected by f
  float KpDistance = 0.1f;
  // The minimum commmand that can be used. May need adjustment.
  float min_command = 0.05f;

  ///////////////////////////////////////////////////////////////

  // Defines our joysticks. We have a custom controller which includes a partailly dismantled joystick
  // and an array of buttons. You should customize this to fit your controller/controllers.

  // Joystick for driving.
  frc::Joystick DriveStick{0};
  // An array of buttons.
  frc::Joystick Buttons{1};

  // Defines our Spark motor controllers.

  ///////////////////////////////////////////////////////////////

  // Wheel used to fire the power cells.
  frc::PWMSparkMax Flywheel{5};
  // Spinning tube in front to grab power cells.
  frc::Spark Grabber{1};
  // Used to move the arm the Grabber is attached to.
  frc::Spark Grabber_Arm{2};
  // Used to move the ball from the transition space imbetween the grabber and the conveyors.
  frc::Spark Transition{3};
  // The bottom portion of the conveyor.
  frc::Spark Carousel{4};
  // The top portion of the conveyor.
  frc::Spark High_Conveyor{0};

  // Basic encoder initiating statement. Data can be read of of an encoder plugged into these ports.
  frc::Encoder encoder{0, 1};
  ///////////////////////////////////////////////////////////////

  /*
  // For the elevator when we finish it.
  frc::Spark Telescope{6};
  frc::Spark Winch{7};
  */

  ///////////////////////////////////////////////////////////////

  // Defines our TalonSRX drive motor controllers from ctre.
  // ctre motor controllers cannot be put into speedcontrollergroups, so create your own drive function.
  // It is simpler than you think.
  
  // Front left
  TalonSRX FLMotor{0};
  // Rear left
  TalonSRX RLMotor{1};
  // Front Right
  TalonSRX FRMotor{2};
  // Rear Right
  TalonSRX RRMotor{3};

  ///////////////////////////////////////////////////////////////

  // Initialized the compressor object. Technically not necessary, but allows you to access certain
  // functions to query the status of the compressor.
  frc::Compressor Compressor{0};

  // Stores whether the compressor is on or off as a true/false value.
  bool enabled = Compressor.Enabled();

  ///////////////////////////////////////////////////////////////

  // Activates a double solenoid. Plug the forward channel into port 1 and the reverse into port 2.
  // Can bus Id is assumed to be 0. Unless controlled it is by default set to off.
  frc::DoubleSolenoid DoubleSolenoid{0, 0, 1};
  // Sets the starting position to the Reverse. When you want to switch the direction the doubleSolenoid is going
  // use TestSolenoid.Toggle();

  
  
};
