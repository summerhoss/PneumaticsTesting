#ifndef VELOCITYCONTROLLER_H
#define VELOCITYCONTROLLER_H

class VelocityController {
public:
	VelocityController(double setPoint);
	double Tick(double measuredValue, double time);
	void SetSetPoint(double setPoint);
	double GetSetPoint();
	double GetError();
	double GetVelocity();
	double GetAcceleration1();
	double GetAcceleration2();
	void setVelocity();

private:
	double VELOCITY_MAX = 3000;
	double VELOCITY_MIN = 1000;
	double setPoint;
	double velocity;
	double error;
	double acceleration1;
	double acceleration2;
	double distance1;
	double distance2;
	double distance3;
	double time1;
	double time2;
	double time3;
	double time_total;
};

#endif
