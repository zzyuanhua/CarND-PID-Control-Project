#ifndef PID_H
#define PID_H

#include<vector>


class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  int pos;
  double params[3];
  double dp[3];
  int step[3];
  double best_err;
  double err;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  std::vector<double> vctes;
  std::vector<double> mctes;

  bool update;
 
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);


  /*
  * Calculate the total PID error.
  */
  double TotalError();

  double calcErr();

  void twiddle(double cte);
};

#endif /* PID_H */
