CC = gcc
CFLAGS = -Wall -g
BUILD_DIR = build
LIBS = ../mySimpleComputer/build/libmySimpleComputer.a
INCLUDE = -I../include/

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(filter-out sat.c sbt.c, $(SRCS)))

all: $(BUILD_DIR)/sat

$(BUILD_DIR)/sat: $(BUILD_DIR)/sat.o $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/sat.o: sat.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)