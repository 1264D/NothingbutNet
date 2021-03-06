#pragma config(Motor,  port1,           belt,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           LeftTop,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           LeftBack,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           FlyWheel1L,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           FlyWheel2L,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           FlyWheel3R,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           FlyWheel4R,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RightTop,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RightBack,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          belt,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
void Wheels()
{
	motor[port2] = vexRT[Ch3] + vexRT[Btn6D]*100 + vexRT[Btn5D]*-100;
	motor[port3] = vexRT[Ch3] + vexRT[Btn6D]*-100 + vexRT[Btn5D]*100;
	motor[port8] = vexRT[Ch2] + vexRT[Btn6D]*-100 + vexRT[Btn5D]*100;
	motor[port9] = vexRT[Ch2] + vexRT[Btn6D]*100 + vexRT[Btn5D]*-100;
}
void Intake()
{
	motor[port1] = vexRT[Btn5U]*127 + vexRT[Btn6U]*-127;
	motor[port10] = vexRT[Btn5U]*127 + vexRT[Btn6U]*-127;
}
void FlyWheels()
{
	if(vexRT[Btn8U] == 1)
	{
		motor[port4] = 127;
		motor[port5] = 127;
		motor[port6] = 127;
		motor[port7] = 127;
	}
	else if(vexRT[Btn8R] == 1)
	{
		motor[port4] = 0;
		motor[port5] = 0;
		motor[port6] = 0;
		motor[port7] = 0;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	motor[port2] = 127;
	motor[port3] = 127;
	motor[port4] = 127;
	motor[port5] = 127;
	wait1Msec(7000);
	motor[port4] = 127;
	motor[port5] = 127;
	motor[port6] = 127;
	motor[port7] = 127;
	wait1Msec(2000);
	motor[port1] = 127;
	motor[port10] = 127;

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	motor[port1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
	motor[port9] = 0;
	motor[port10] = 0;
	while(true)
	{
Wheels();
Intake();
FlyWheels();
	}
}
