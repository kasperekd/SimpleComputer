CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
LIBS = ../mySimpleComputer/build/libmySimpleComputer.a ../myTerm/build/libmyTerm.a  

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(filter-out pr01.c, $(SRCS)))

all: $(BUILD_DIR)/pr01

$(BUILD_DIR)/pr01: $(BUILD_DIR)/pr01.o $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/pr01.o: pr01.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)