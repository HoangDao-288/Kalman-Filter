#include "../include/scalar_kf.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>

int main() {

    // Example usage of the Scalar Kalman Filter
    double distance_variance = 0.001; // Variance of the process noise
    double measurement_variance = 0.7; // Variance of the measurement noise
    double initial_state = 0.0; // Initial state estimate
    double initial_error_covariance = 0.2; // Initial error covariance

    KalmanFilter::ScalarKF kf(distance_variance, measurement_variance, initial_state, initial_error_covariance);

    std::ofstream file("results.csv");

    if (file.is_open()) {
        file << "Time\tGround Truth\tMeasurement\tEstimate\tVariance\n";
    } else {
        std::cout << "Cannot open file\n";
        return 0;
    }

    for (int i = 1; i < 101; ++i) {

        double velocity = 5; // Simulated velocity
        double delta_time = 0.1; // Time step

        // Predict the next state
        double control_input = velocity * delta_time;
        kf.predict(control_input); 

        // Add some noise to the measurement
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine noise_generator(seed);
        std::normal_distribution<double> noise(0.0, 0.5);

        // Simulated and update measurement with noise
        double measurement = initial_state + control_input * i + noise(noise_generator); 
        kf.update(measurement);

        // Log results to file
        if (file.is_open()) {
            file << i * delta_time << "\t" << initial_state + control_input * i << "\t" << measurement << "\t" << kf.getEstimate() << "\t" << kf.getVariance() << "\n";
        }
    }

    std::cout << "Done!"<< std::endl;
    return 0;
}