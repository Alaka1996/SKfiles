#include <gtest/gtest.h>
#include "sensor.h"  // Include your header files for testing

// Example test case
TEST(SensorTest, TestCalculateAverage) {
    uint16_t data[] = {1, 2, 3, 4, 5};
    int size = 5;
    int expected_average = 3;

    int result = calculate_average(data, size);

    EXPECT_EQ(result, expected_average);
}

// main function to run all the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
