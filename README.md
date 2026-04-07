# Kalman Filter

A C++ implementation of the Scalar (1D) Kalman Filter algorithm with example simulation and visualization.

## Overview

The Kalman Filter is an optimal recursive algorithm for estimating the state of a linear dynamic system from noisy measurements. This project implements a simple scalar Kalman filter suitable for tracking 1D quantities (e.g., position, temperature) in the presence of process noise and measurement noise.

## Features

- **Scalar Kalman Filter Implementation**: Core KF algorithm with prediction and update steps
- **Efficient Recursive Estimation**: Real-time state tracking with minimal computational overhead
- **Dynamic Noise Handling**: Configurable process and measurement noise variances
- **Error Covariance Tracking**: Monitors uncertainty in state estimates
- **Example Simulation**: Demonstrates KF tracking of an object with noisy measurements
- **Data Logging**: Outputs estimates, measurements, and variance to CSV format
- **Python Visualization**: Includes plotting script to visualize filter performance

## Theory

The Kalman Filter operates in two phases:

### Prediction Phase
Updates the state estimate based on the system model:
$$\hat{x}_{k|k-1} = \hat{x}_{k-1|k-1} + u_k$$
$$P_{k|k-1} = P_{k-1|k-1} + Q$$

Where:
- $\hat{x}$ = state estimate
- $u$ = control input
- $P$ = error covariance
- $Q$ = process noise variance

### Update Phase
Refines the estimate using the latest measurement:
$$K_k = \frac{P_{k|k-1}}{P_{k|k-1} + R}$$ (Kalman Gain)
$$\hat{x}_{k|k} = \hat{x}_{k|k-1} + K_k(z_k - \hat{x}_{k|k-1})$$
$$P_{k|k} = (1 - K_k) \cdot P_{k|k-1}$$

Where:
- $K$ = Kalman gain
- $z$ = measurement
- $R$ = measurement noise variance

## Requirements

- C++17 or later
- CMake 3.10+
- Python 3.x (for visualization)
- pandas and matplotlib (Python packages)

## Building

### Build with CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run the Example

```bash
./scalar_kf
```

This generates `results.csv` with simulation data.

## Usage

### C++ API

```cpp
#include "scalar_kf.hpp"

// Create a Kalman Filter instance
// Parameters: motion_variance, measurement_variance, initial_state, initial_error_covariance
KalmanFilter::ScalarKF kf(0.001, 0.7, 0.0, 0.2);

// Prediction step
double control_input = 0.5;  // Velocity * time_step
kf.predict(control_input);

// Update step with measurement
double measurement = 0.48;   // Noisy observation
kf.update(measurement);

// Get results
double estimate = kf.getEstimate();
double variance = kf.getVariance();
```

### Visualization

```bash
python plot_results.py
```

This generates `kalman_filter_results.png` showing:
- Ground truth trajectory
- Noisy measurements
- Kalman filter estimates
- Error variance over time

## Project Structure

```
kalman_filter/
├── CMakeLists.txt           # Build configuration
├── README.md                # This file
├── kf.md                    # Additional documentation
├── plot_results.py          # Python visualization script
├── include/
│   └── scalar_kf.hpp        # Kalman filter class definition
├── src/
│   └── scalar_kf.cpp        # Kalman filter implementation
├── test/
│   └── main.cpp             # Example simulation
└── build/
    ├── scalar_kf            # Compiled executable
    └── results.csv          # Simulation output
```

## Example Results

The example simulation tracks an object moving at constant velocity (5 m/s) with:
- **Process Noise Variance (Q)**: 0.001 - Very low, system is predictable
- **Measurement Noise Variance (R)**: 0.7 - Higher, measurements are noisy
- **Simulation Duration**: 10 seconds (100 steps × 0.1s)

The filter effectively smooths the noisy measurements and provides accurate position estimates that converge to ground truth values.

## Key Parameters

- `motion_variance`: Process noise variance (Q) - How much the system can change unexpectedly
- `measurement_variance`: Measurement noise variance (R) - How much measurements can be off
- `initial_state`: Starting state estimate
- `initial_error_covariance`: Initial uncertainty in the estimate

## License

MIT License

## References

- Welch, G., & Bishop, G. (2006). An Introduction to the Kalman Filter
- Simon, D. (2006). Optimal State Estimation: Kalman, H∞, and Nonlinear Approaches
