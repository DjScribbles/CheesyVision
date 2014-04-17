#include "WPILib.h"
#include "CheesyVisionServer.h"

class CheesyVisionRobot : public IterativeRobot
{
    CheesyVisionServer *server;
public:
    static const int listenPort = 1180;
	CheesyVisionRobot()
	{
	    server = CheesyVisionServer::GetInstance();
	}
	
void CheesyVisionRobot::RobotInit() {
server->SetPort(listenPort);
server->StartListening();
}

void CheesyVisionRobot::DisabledInit() {
    server->StopSamplingCounts();
}

void CheesyVisionRobot::DisabledPeriodic() {
    
}

void CheesyVisionRobot::AutonomousInit() {
    server->Reset();
    server->StartSamplingCounts();
}

void CheesyVisionRobot::AutonomousPeriodic() {
    printf("Left Status: %d\tRight Status: %d\n", server->GetLeftStatus(), server->GetRightStatus());
    printf("Left Counts: %d\tRight Counts: %d\tTotal Count: %d", server->GetLeftCount(), server->GetRightCount(), server->GetTotalCount());
}

void CheesyVisionRobot::TeleopInit() {
}

void CheesyVisionRobot::TeleopPeriodic() {
}

void CheesyVisionRobot::TestInit() {
}

void CheesyVisionRobot::TestPeriodic() {
}

};

START_ROBOT_CLASS(CheesyVisionRobot);

