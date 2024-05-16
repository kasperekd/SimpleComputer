CC = gcc
CFLAGS = -Wall -g
BUILD_DIR = build
LIBS = ../mySimpleComputer/build/libmySimpleComputer.a
INCLUDE = -I../include/

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(filter-out sat.c, $(SRCS)))

all: $(BUILD_DIR)/sat $(BUILD_DIR)/sbt

$(BUILD_DIR)/sat: $(BUILD_DIR)/sat.o $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/sat.o: sat.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

$(BUILD_DIR)/sbt: $(BUILD_DIR)/sbt.o $(BUILD_DIR)/rpn.o $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/sbt.o: sbt.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

$(BUILD_DIR)/rpn.o: rpn.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(INCLUDE) $(LIBS) $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)