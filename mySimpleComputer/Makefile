CC = gcc
CFLAGS = -Wall
BUILD_DIR = build

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/sc_memory.o $(BUILD_DIR)/libmySimpleComputer.a | $(BUILD_DIR)
	$(CC) -o $@ $^ -L$(BUILD_DIR) -lmySimpleComputer

$(BUILD_DIR)/main.o: main.c ../include/mySimpleComputer.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ main.c -I../include

$(BUILD_DIR)/sc_memory.o: sc_memory.c ../include/mySimpleComputer.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ sc_memory.c -I../include

$(BUILD_DIR)/libmySimpleComputer.a: $(BUILD_DIR)/sc_memory.o | $(BUILD_DIR)
	ar rcs $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)