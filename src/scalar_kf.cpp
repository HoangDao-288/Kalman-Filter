#include "../include/scalar_kf.hpp"

namespace KalmanFilter {    

void ScalarKF::predict(double& control_input) {
    // Prediction step
    state_estimate_ += control_input;
    variance_estimate_ += motion_variance_;
}

void ScalarKF::update(double& measurement) {
    // Measurement update step
    double K = variance_estimate_ / (variance_estimate_ + measurement_variance_); // Kalman gain
    state_estimate_ += K * (measurement - state_estimate_); // Update estimate with measurement
    variance_estimate_ *= (1 - K); // Update error covariance
}

} // namespace KalmanFilter