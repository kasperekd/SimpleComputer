CC = gcc
CFLAGS = -Wall -g
BUILD_DIR = build

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR)/libmyTerm.a

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I../include

$(BUILD_DIR)/libmyTerm.a: $(OBJS) | $(BUILD_DIR)
	ar rcs $@ $(OBJS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)