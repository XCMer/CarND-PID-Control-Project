#include <iostream>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    // Initialize parameters
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    // Initialize errors to be 0
    last_cte = 0;
    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double cte) {
    i_error += Ki * cte;
    p_error = Kp * cte;

    double d_cte = cte - last_cte;
    d_error = Kd * d_cte;

    last_cte = cte;
}

double PID::TotalError() {
    return p_error + i_error + d_error;
}

