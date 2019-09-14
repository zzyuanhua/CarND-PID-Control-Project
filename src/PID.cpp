#include "PID.h"
#include <iostream>
#include <math.h>


using namespace std;

/*
* TODO: Complete the PID class.
*/



PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
	/*
	pos = 1;
	params[0] = Kp;
	params[1] = Kd;
	params[2] = Ki;
	step[0] = 0;
	step[1] = 0;
	step[2] = 0;
	dp[0] = 0.1*params[0];
	dp[1] = 0.1*params[1];
	dp[2] = 0.1*params[2];

	best_err = 0.0;
	err = 0.0;
	*/
}

void PID::UpdateError(double cte) {

	d_error = cte - p_error;
	p_error = cte;
	vctes.push_back(fabs(cte));
	while (vctes.size() > 22)
	{
		vctes.erase(vctes.begin());
	}
	for (int i; i < vctes.size(); i++)
	{
		i_error += vctes[i];
	}

	//mctes.push_back(fabs(cte));
	
	
}

double PID::calcErr()
{
	double err = 0;
	for (int i; i < mctes.size(); i++)
	{
		err += mctes[i]* mctes[i];
	}
	return err /= mctes.size();
}

double PID::TotalError() {
	return  -Kp * p_error - Kd * d_error - Ki * i_error;
	//return  -params[0] * p_error - params[1] * d_error - params[2] * i_error;
}



void PID::twiddle(double cte) {
/*	UpdateError(cte);
	if (mctes.size() < 25) return;
	
	
	err = calcErr(); 
	mctes.clear();

	if (err < best_err)
	{
		dp[pos] *= 1.1;
		params[pos] += dp[pos];
		step[pos] = 0;
		best_err = err;

		pos = (pos + 1) % 3;
	}
	else
	{
		if (step[pos] == 0)
		{
			params[pos] += dp[pos];
			step[pos] = (step[pos] + 1) % 3;
		}
		else if (step[pos] == 1)
		{
			params[pos] -= 2 * dp[pos];
			step[pos] = (step[pos] + 1) % 3;
		}
		else
		{
			params[pos] += dp[pos];
			dp[pos] *= 0.9;
			step[pos] = 0;

			pos = (pos + 1) % 3;
		}

	}
	std::cout << "cte:" << cte << "  pid[0]: " << params[0] << "  pid[1]: " << params[1] << "  pid[2]: " << params[2] << std::endl;
	std::cout << "dp[0]: " << dp[0] << "  dp[1]: " << dp[1] << "  dp[2]: " << dp[2] << std::endl;
	//double steering = -params[0] * p_error - params[1] * d_error - params[2] * i_error;
	//if (steering < -1.0)steering = -1.0;
	//if (steering > 1.0)steering = 1.0;
	return ;*/


}


