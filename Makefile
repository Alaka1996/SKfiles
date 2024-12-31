# Variables
CC = g++
CFLAGS = -Wall -Iinclude -Iexternal/googletest/googletest/include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test
GTEST_DIR = external/googletest/googletest

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
MAIN_OBJ = $(OBJ_DIR)/main.o
TEST_OBJ = $(OBJ_DIR)/test_sensor.o
GTEST_OBJ = $(GTEST_DIR)/src/gtest-all.o

# Targets
all: dirs $(BIN_DIR)/sensor_program $(BIN_DIR)/test_sensor

# Create directories
dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Build the main program
$(BIN_DIR)/sensor_program: $(MAIN_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Build the test binary (Link with Google Test)
$(BIN_DIR)/test_sensor: $(TEST_OBJ) $(OBJ) $(GTEST_OBJ)
	$(CC) $(CFLAGS) $^ -lgtest -lgtest_main -pthread -o $@

# Compile main source file
$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test file
$(OBJ_DIR)/test_sensor.o: test_sensor.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Compile other source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run Cppcheck
lint:
	cppcheck --enable=all --inconclusive --std=c++17 -Iinclude -I/usr/include src/*.c

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: clean all

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all dirs clean lint debug
