# CC := gcc
# HEADERS=include
# CFLAGS := -Wall -I$(HEADERS)
# AR := ar rcs

# SRCDIR := myCache
# OUTPUT := $(SRCDIR)/build

# SOURCES := $(wildcard $(SRCDIR)/*.c) 
# OBJECTS := $(patsubst $(SRCDIR)/%.c, $(OUTPUT)/%.o, $(SOURCES))

# all: $(OUTPUT)/$(SRCDIR).a

# $(OUTPUT)/$(SRCDIR).a: $(OBJECTS)
# 	$(AR) $@ $^ mySimpleComputer/build/sc_tcounterSet.o

# $(OUTPUT)/%.o: $(SRCDIR)/%.c | $(OUTPUT)
# 	$(CC) $(CFLAGS) -c $< -o $@ 

# $(OUTPUT): 
# 	mkdir $@ 

# clean: 
# 	rm -rf ./$(OUTPUT)
CC = gcc
CFLAGS = -Wall -g
BUILD_DIR = build
LIBS = ../mySimpleComputer/build/libmySimpleComputer.a
INCLUDE = -I../include/

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR)/libmyCache.a

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

$(BUILD_DIR)/libmyCache.a: $(OBJS) | $(BUILD_DIR)
	ar rcs $@ $(OBJS) $(LIBS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)