# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++14

# Source files
SRCS = $(wildcard *.cpp)

# Object files
OBJS = $(SRCS:%.cpp=obj/%.o)

# Executable name
EXEC = chess

# Default target
all: $(EXEC)

# Create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile source files to object files
obj/%.o: %.cpp
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(EXEC)
	@rmdir obj 2>/dev/null || true
