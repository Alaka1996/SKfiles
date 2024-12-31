// test_sensor.cpp
#include <gtest/gtest.h>
#include "utils.h"  // Include the header file for calculate_average

class SensorTest_TestCalculateAverage_Test : public ::testing::Test {
protected:
    uint16_t data[5] = {10, 20, 30, 40, 50};
    int size = 5;
};

TEST_F(SensorTest_TestCalculateAverage_Test, TestCalculateAverage) {
    int result = calculate_average(data, size);
    EXPECT_EQ(result, 30);  // Assuming the average of the data is 30
}
