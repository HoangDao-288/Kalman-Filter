cmake_minimum_required(VERSION 3.10)

project(KalmanFilter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the Kalman Filter library
add_library(kf_lib src/scalar_kf.cpp)
target_include_directories(kf_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add the test executable
add_executable(scalar_kf test/main.cpp)
target_link_libraries(scalar_kf PRIVATE kf_lib)
target_include_directories(scalar_kf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

