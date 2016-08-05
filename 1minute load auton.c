// 2 front left
// 3 back left
// 4 front right
// 5 back right
int count;
task main
{
	count = 7;
while(count >= 1)
{
motor[port3] = 0;
motor[port5] = 0;
motor[port2] = 100;
motor[port4] = 100;
wait1Msec(6500);
motor[port2] = 0;
motor[port4] = 0;
motor[port8] = 127;
motor[port9] = 127;
motor[port6] = -127;
motor[port7] = -127;
wait1Msec(2000);
motor[port3] = 0;
motor[port5] = 0;
motor[port3] = -100;
motor[port5] = -100;
motor[port8] = 0;
motor[port9] = 0;
motor[port6] = 0;
motor[port7] = 0;
wait1Msec(6500);
count --;
}
}
