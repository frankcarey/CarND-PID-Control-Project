#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd) {

  /*
   * Errors
   */
  p_error = 0;
  i_error = 0;
  d_error = 0;

  Kp = _Kp;
  Ki = _Ki;
  Kd = _Kd;

}

void PID::UpdateError(double cte) {
  double last_p_error = p_error;
  p_error = cte;
  d_error = p_error - last_p_error;
  i_error += p_error;
  //std::cout << "\tPartial  Err: last_p: " << last_p_error << " p: " << p_error << " i: " << i_error << " d: " << d_error << std::endl;
}

double PID::TotalError() {
  //std::cout << "\tAdjusted Err:    p:" << Kp * p_error  << " i:" << Ki * i_error << " d:" << Kd * d_error << std::endl;

  return (Kp * p_error) + (Kd * d_error) + (Ki * i_error);
}

