extern "C" {
    #include "utils.h"  // Include the C header for your C function
}

#include <gtest/gtest.h>  // Include the Google Test header

// Your test case
TEST(SensorTest, TestCalculateAverage) {
    uint16_t data[] = {10, 20, 30};
    int size = 3;
    int result = calculate_average(data, size);
    EXPECT_EQ(result, 20);
}
