CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
LIBS = ../mySimpleComputer/build/libmySimpleComputer.a ../myTerm/build/libmyTerm.a  

all: $(BUILD_DIR)/main $(BUILD_DIR)/pr01

$(BUILD_DIR)/pr01: $(BUILD_DIR)/pr01.o $(BUILD_DIR)/sc_print.o $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/pr01.o: pr01.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/sc_print.o: sc_print.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

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