CC = gcc
CFLAGS = -Wall -g
BUILD_DIR = build

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(BUILD_DIR)/main.o $(OBJS) | $(BUILD_DIR) $(BUILD_DIR)/libmySimpleComputer.a
	$(CC) -o $@ $^ -L$(BUILD_DIR) -lmySimpleComputer

$(BUILD_DIR)/main.o: main.c ../include/mySimpleComputer.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ main.c -I../include

$(BUILD_DIR)/%.o: %.c ../include/mySimpleComputer.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I../include

$(BUILD_DIR)/libmySimpleComputer.a: $(OBJS) | $(BUILD_DIR)
	ar rcs $@ $(OBJS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)