#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  InputUltra,     sensorSONAR_inch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_5,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port3,           frontRight,    tmotorVex393_MC29, PIDControl, reversed, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port4,           backRight,     tmotorVex393_MC29, PIDControl, driveRight, encoderPort, I2C_3)
#pragma config(Motor,  port5,           frontLeft,     tmotorVex393_MC29, PIDControl, driveLeft, encoderPort, I2C_4)
#pragma config(Motor,  port6,           arms,          tmotorVex393_MC29, PIDControl, encoderPort, I2C_5)
#pragma config(Motor,  port7,           claw,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           mobileLift1,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          backLeft,      tmotorVex393_HBridge, openLoop, reversed, encoderPort, I2C_1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int p = 0;
int t = 0;
int r = 0;
int l = 0;

/*void moveForward (int p, int t, int r, int l)
{
while (p < 3)
{
motor[backLeft] = 63 + t*l;
motor [backRight] = 63 + t*r;
motor [frontLeft] = 63 + t*l;
motor [frontRight] = 63 + t*r;
wait1Msec(5000);
p++;
}
}*/


task startUltra ()
{
	while (true)
	{
		resetMotorEncoder(backLeft);
		resetMotorEncoder(frontLeft);
		resetMotorEncoder(backRight);
		resetMotorEncoder(frontRight);

		if (SensorValue[InputUltra] == 20)
		{
			t = 0;
			r = 0;
			l = 0;
//			motor[backLeft] = 63;
		}
		else if (SensorValue[InputUltra] < 20)
		{
			t = 20;
			r = 0;
			l = 1;
//			motor[backLeft] = 63 + 20;
		}
		else if(SensorValue[InputUltra] > 20 || SensorValue[InputUltra] == -1)
		{
			t = 20;
			r = 1;
			l = 0;
//			motor[backLeft] = 50;
		}
		wait1Msec (15);

	}

}



task main()
{
	//short backLeftAdjust;
	resetMotorEncoder(backLeft);
	resetMotorEncoder(frontLeft);
	resetMotorEncoder(backRight);
	resetMotorEncoder(frontRight);

	startTask (startUltra);

//	motor[backLeft] = 63;
	while (true)
	{
	motor[backLeft] = 63 + t*l;
	motor [backRight] = 63 + t*r;
	motor [frontLeft] = 63 + t*l;
	motor [frontRight] = 63 + t*r;
	wait1Msec(15);
	p++;
	}


	/*wait1Msec(2000);

	resetMotorEncoder(backLeft);
	resetMotorEncoder(frontLeft);
	resetMotorEncoder(backRight);
	resetMotorEncoder(frontRight);
	wait1Msec(2000);

	motor [backLeft] = 550;
	wait1Msec(2000);

	if(getMotorEncoder(backLeft) > 500 &&	(getMotorEncoder(backLeft) < 7000))
	{
	motor[backLeft] = 63;
	motor[frontLeft] = 63;
	motor[backRight] = 63;
	motor[frontRight] = 63;
	wait1Msec(2000);
	}
	if (SensorValue[InputUltra] < 12)
	{
	backLeftAdjust = 50;
	}
	else
	{
	backLeftAdjust = 0;
	}
	if(getMotorEncoder(backLeft) > 7000)
	{
	motor[backLeft] = 0 + backLeftAdjust;
	motor[frontLeft] = 0 + backLeftAdjust;
	motor[backRight] = 0 + backLeftAdjust;
	motor[frontRight] = 0 + backLeftAdjust;
	wait1Msec(2000);
	}*/

	//this is just a reference point for the rest of the program










}
