CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
LIBS = ../mySimpleComputer/build/libmySimpleComputer.a ../myTerm/build/libmyTerm.a  

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(filter-out console.c, $(SRCS)))

all: $(BUILD_DIR)/console

$(BUILD_DIR)/console: $(BUILD_DIR)/console.o $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/console.o: console.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)