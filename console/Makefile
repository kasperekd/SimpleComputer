CC = gcc
CFLAGS = -Wall
BUILD_DIR = build

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/hello.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/main.o: main.c hello.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/hello.o: hello.c hello.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)