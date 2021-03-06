#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    ,               sensorAnalog)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,            ,             tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,            ,             tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,            ,             tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,            ,             tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port9,            ,             tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Setings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

int clk[3]; //clock
int lawnchair[2];
int lawnswap;
int ideal;
void intake()
{
	motor[port6] = vexRT[Btn5D]*90 + vexRT[Btn6D] * -90;
	motor[port7] = vexRT[Btn5D]*90 + vexRT[Btn6D] * -90;
}
// 2 front left
// 3 back left
// 4 front right
// 5 back right
void wheels()
{
	motor[port2] = vexRT[Ch3] /*+ vexRT[Btn7U]*80*/ + vexRT[Btn6U]*80 + vexRT[Btn5U]*-80;
	motor[port3] = vexRT[Ch3] /*+ vexRT[Btn7D]*-80*/ + vexRT[Btn6U]*-80 +vexRT[Btn5U]*80;
	motor[port4] = vexRT[Ch2] /*+ vexRT[Btn7U]*80*/ + vexRT[Btn6U]*-80 + vexRT[Btn5U]*80;
	motor[port5] = vexRT[Ch2] /*+ vexRT[Btn7D]*-80*/  + vexRT[Btn6U]*80  + vexRT[Btn5U]*-80;
}

void launcher()
{
	if(vexRT[Btn7U] == 1)
	{
	lawnswap = 	1;
}
if(vexRT[Btn7D] == 1)
	{
	lawnswap = 	0;
}
	//l 50, d 100, u 127, r 0
	//swish
	if(vexRT[Btn8L] == 1 && lawnswap == 0)
	{
		ideal = 90/1.4;
	}
	//Midfield
	if(vexRT[Btn8D] == 1 && lawnswap == 0)
	{
		ideal = 80/1.4;
	}
	//Crossfield
	if(vexRT[Btn8U] == 1 && lawnswap == 0)
	{
		ideal = 73/1.4;
	}
	//Stop
	if(vexRT[Btn8R] == 1 && lawnswap == 0)
	{
		ideal = 0;
		lawnchair[0] = 0;
	}
	//tacshot
	if(vexRT[Btn8L] == 1 && lawnswap == 1)
	{
		lawnchair[1] = lawnchair[1] - 5;
	waitUntil(vexRT[Btn8L] == 0);
		}
	//Midfield
	if(vexRT[Btn8D] == 1 && lawnswap == 1)
	{
		lawnchair[1] = lawnchair[1] - 10;
	waitUntil(vexRT[Btn8D] == 0);
		}
	//Crossfield
	if(vexRT[Btn8U] == 1 && lawnswap == 1)
	{
		lawnchair[1] = lawnchair[1] + 10;
		waitUntil(vexRT[Btn8U] == 0);
	}
	//Stop
	if(vexRT[Btn8R] == 1 && lawnswap == 1)
	{
		lawnchair[1] = 0;
		waitUntil(vexRT[Btn8R] == 0);
	}
	//motor[port8] = lawnchair[lawnswap];
	//motor[port9] = lawnchair[lawnswap];
	motor[port9] = lawnchair[lawnswap];
	motor[port8] = lawnchair[lawnswap];
}

void rollers()
{
	if(vexRT[Btn7R] == 1)
	{
		motor[port1] = -127;
	}
	if(vexRT[Btn7L] == 1)
	{
		motor[port1] = 0;
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
	int loops;
	/*
	// 2 front left
	// 3 back left
	// 4 front right
	// 5 back right
	wait1Msec(6000);
	//motor[port3] = 0;
	//motor[port5] = 0;
	motor[port2] = 100;
	motor[port4] = 100;
	wait1Msec(7300);
	motor[port2] = 0;
	motor[port4] = 0;
	motor[port8] = 27;
	motor[port9] = 27;
	motor[port6] = -127;
	motor[port7] = -127;

	motor[port2] = 100;
	motor[port4] = 100;
	wait1Msec(750);
	motor[port2] = 0;
	motor[port4] = 0;
	int loops;
	motor[port2] = 0;
	motor[port4] = 0;
	wait1Msec(500);
	motor[port2] = 0;
	motor[port4] = 0;
	*/
	motor[port8] = 60;
	motor[port9] = 60;
	for(loops=0; loops<20; loops++)
	{
		motor[port9] = 100;
		motor[port8] = 100;
		wait1Msec(1000);
		motor[port9] = 70;
		motor[port8] = 70;
		wait1Msec(2300);
		motor[port6] = -90;
		motor[port7] = -90;
		wait1Msec(330);
		motor[port6] = -0;
		motor[port7] = -0;
	}


}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////
// 1 rollers
// 2 front left
// 3 back left
// 4 front right
// 5 back right
// 6 7 intake
// 8 9 flywheels


task usercontrol()
{
	lawnswap = 0;
	lawnchair[0] = 0;
	lawnchair[1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
	motor[port9] = 0;

	//////////////////////////make this less stupid///////

	int past1;
	int past2;
	int enc; //encoder
	string Battery;
	string battery;
	Battery = "Bat: ";
		bLCDBacklight = true;
		clk[0] = 0;
		enc = nMotorEncoder[port8];
		int batdivk[2]; //batterydividedby
		string line1; //line1 of lcd
		string line2; //line2 of lcd

	while(true)
	{
		battery = Battery + batdivk[0];
		batdivk[0] = nImmediateBatteryLevel;
		batdivk[1] = SensorValue[in1];
		line1 = lawnchair[0]; //or Battery or batdivk[0];
		line2 = enc;  //enc
		if(nPgmTime - clk[0] >= 100)
		{
	clk[0] = nPgmTime;
	past2 = past1;
	past1 = nMotorEncoder[port8];

	enc = nMotorEncoder[port8] - past2;
	}
	if(nPgmTime - clk[1] >= 300)
		{
	clk[1] = nPgmTime;
		if(enc < ideal)
			{
			lawnchair[0] ++;
			}
		}
		if(nPgmTime - clk[2] >= 600)
		{
			clk[2] = nPgmTime;
			if(enc > ideal)
			{
			lawnchair[0] --;
			}
	}
	displayLCDCenteredString(0, line1);
	displayLCDCenteredString(1, line2);
	//////////////////////////////////////////////////////
		intake();
		wheels();
		launcher();
		rollers();
	}
}
