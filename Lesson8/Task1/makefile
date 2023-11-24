# Makefile for the program

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = my_program

# Source files
SRCS = main.cc

# Header files
HDRS = main.hh

# Object files
OBJS = $(SRCS:.cc=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Rule to build object files from source files
%.o: %.cc $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)

