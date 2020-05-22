#include "PID.h"
#include "math.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, double forget_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_; Ki = Ki_; Kd = Kd_; forget = forget_;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error = cte - p_error;
  i_error = forget*i_error + cte;
  p_error = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  totalerror = Kp*p_error + Ki*i_error + Kd*d_error;

  return totalerror;  // TODO: Add your total error calc here!
}