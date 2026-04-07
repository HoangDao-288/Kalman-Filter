#pragma once

namespace KalmanFilter {

class ScalarKF {
public:

    ScalarKF(double motion_variance, double measurement_variance, double initial_state, double initial_error_covariance)
        : motion_variance_(motion_variance), measurement_variance_(measurement_variance) {
        state_estimate_ = initial_state;
        variance_estimate_ = initial_error_covariance;
    }

    void predict(double& control_input);

    void update(double& measurement);

    double getEstimate() const {
        return state_estimate_;
    }

    double getVariance() const {
        return variance_estimate_;
    }

private:    
    double motion_variance_;
    double measurement_variance_;
    double state_estimate_;
    double variance_estimate_;

};

} // namespace KalmanFilter