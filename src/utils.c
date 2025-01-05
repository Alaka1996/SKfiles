#include <stdint.h>

// cppcheck-suppress unusedFunction
int calculate_average(uint16_t *data, int size) {
    if (size <= 0) {
        return -1; // Error: Invalid size
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }

    return sum / size;
}
