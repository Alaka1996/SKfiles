extern "C" {
    #include "utils.h"
}

TEST(SensorTest, TestCalculateAverage) {
    uint16_t data[] = {10, 20, 30};
    int size = 3;
    int result = calculate_average(data, size);
    EXPECT_EQ(result, 20);
}
