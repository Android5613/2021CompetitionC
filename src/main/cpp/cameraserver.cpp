#include "Robot.h"

void Robot::cameraserver() {

  frc::CameraServer::GetInstance().StartAutomaticCapture();

}