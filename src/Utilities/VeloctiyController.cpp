#include "VelocityController.h"
#include "RobotMap.h"
#include <iostream>

VelocityController::VelocityController(double setPoint){
	if(setPoint>=100){
		VELOCITY_MAX= 3000;
		VELOCITY_MIN = 1000;
	}
	if(setPoint<100){
		VELOCITY_MAX=2000;
		VELOCITY_MIN=800;
	}
	if(setPoint<0){
		VELOCITY_MAX= -3000;
		VELOCITY_MIN = -1000;
	}
	this->setPoint = setPoint*(4096.0/(6.0*3.1415));
	this->velocity = VELOCITY_MIN;
	this->error = setPoint;
	this->distance1 = 2*(setPoint*(4096.0/(6.0*3.1415)))/10;
	this->distance2 = 5*(setPoint*(4096.0/(6.0*3.1415)))/10+distance1;
	this->distance3 = 3*(setPoint*(4096.0/(6.0*3.1415)))/10+distance2;
	this->time1=(2*(2*setPoint*(4096.0/(6.0*3.1415)))/10)/(VELOCITY_MAX+VELOCITY_MIN);
	this->time2=(2*(5*(setPoint*(4096.0/(6.0*3.1415)))/10))/(VELOCITY_MAX*2);
	this->time3=(2*(3*setPoint*(4096.0/(6.0*3.1415)))/10)/(VELOCITY_MAX+VELOCITY_MIN);
	this->time_total=time1+time2+time3;
	this->acceleration1 = (VELOCITY_MAX-VELOCITY_MIN)/time1;
	this->acceleration2 = (VELOCITY_MAX-VELOCITY_MIN)/time3;

}
void VelocityController::setVelocity(){
	this->velocity=VELOCITY_MIN;
}
double VelocityController::Tick(double measuredValue, double time) {
	/*std::cout<<"Setpoint"<<setPoint<<std::endl;
	//std::cout<<"VelocityMax"<<VELOCITY_MAX<<std::endl;
	//std::cout<<"VelocityMin"<<VELOCITY_MIN<<std::endl;
	std::cout<<"distance1: "<<distance1<<std::endl;
	std::cout<<"distance2: "<<distance2<<std::endl;
	std::cout<<"distance3: "<<distance3<<std::endl;
	std::cout<<"time1: "<<time1<<std::endl;
	std::cout<<"time3: "<<time3<<std::endl;
	std::cout<<"acceleration1: "<<acceleration1<<std::endl;
	std::cout<<"acceleration2: "<<acceleration2<<std::endl;*/
	measuredValue*=(4096.0/(6.0*3.1415));
	std::cout<<"measured value"<<measuredValue<<std::endl;
	if(measuredValue <= this->distance1){
		std::cout<<"111111111111111111"<<std::endl;
		this->velocity += acceleration1*.006;
		return velocity;
	}
	else if(measuredValue<= this->distance2){
		std::cout<<"222222222222222222"<<std::endl;
		if(velocity>VELOCITY_MAX)
			this->velocity = VELOCITY_MAX;
		else
			return velocity;
		return velocity;
	}
	else if(measuredValue<= this->distance3){
		std::cout<<"33333333333333333"<<std::endl;
		if(velocity<VELOCITY_MIN){
			return VELOCITY_MIN;
		}
		this->velocity -= acceleration2*.006;
		return velocity;
	}
	else
	{
		velocity = -VELOCITY_MIN;
		return velocity;
	}
	return 0;
}

void VelocityController::SetSetPoint(double setPoint) {
	this->setPoint = setPoint;
	error = 0;
}

double VelocityController::GetSetPoint() {
	return setPoint;
}

double VelocityController::GetError() {
	return error;
}

double VelocityController::GetVelocity() {
	return velocity;
}
double VelocityController::GetAcceleration1(){
	return acceleration1;
}
double VelocityController::GetAcceleration2(){
	return acceleration2;
}
