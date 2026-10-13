ifeq ($(HOSTTYPE), )
	HOSTTYPE:=$(shell uname -m)_$(shell uname -s)
endif

TARGET = libstruct_$(HOSTTYPE).so
SOFTLINK = libstruct.so
OBJ_PATH = obj
SRC_PATH = src
INC_PATH = inc

CC = gcc
FLAGS = -Wall -Wextra -pedantic
OBJS = $(addprefix obj/, Heap.o LinkedList.o DoublyLinked.o)

.PHONY: all clean

all: $(TARGET)



$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -shared -o $(TARGET)
	@rm -f $(SOFTLINK)
	@ln -s $(TARGET) $(SOFTLINK)
	@echo "Zavrsen .so objekat"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c -I $(INC_PATH) $<  $(FLAGS) -fPIC -o $@ 
	@echo "Zavrsen $@ "

