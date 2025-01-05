// test_sensor.c
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "utils.h"  

void test_average_basic() {
    uint16_t data[] = {100, 200, 300, 400, 500};
    int avg = calculate_average(data, 5);  // Use the function from utils.c
    assert(avg == 300);
    printf("Test 1 passed: Basic average calculation\n");
}

// other test cases remain the same...

int main() {
    test_average_basic();
    // other tests...
    return 0;
}

