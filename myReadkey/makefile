CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
INCLUDE = -I../include/

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR)/libmyReadkey.a

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

$(BUILD_DIR)/libmyReadkey.a: $(OBJS) | $(BUILD_DIR)
	ar rcs $@ $(OBJS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)