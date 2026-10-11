ifeq ($(HOSTTYPE),)
	HOSTTYPE:=$(shell uname -m)_$(shell uname -s)
endif

TARGET = lib_struct_$(HOSTTYPE).so
SOFTLINK = lib_struct.so
OBJS = $(addprefix obj/, linkedList.o doublyLinked.o)



PATH_SRC = src
PATH_OBJ = obj
PATH_INC = inc
CC = gcc
FLAGS = -Wall -Wextra -pedantic -fPIC

.Phony: all clean 

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) -shared -o $@ $(OBJS)  
	@rm -f $(SOFTLINK)
	ln -s $(TARGET) $(SOFTLINK)
	@echo make is done 


$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $^ $(FLAGS) -o $@ -I $(PATH_INC)
	@echo turned src file into obj file

