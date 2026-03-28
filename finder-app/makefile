# Define the compiler, using CROSS_COMPILE as a prefix if provided
# If CROSS_COMPILE is empty, it defaults to 'gcc'
CC = $(CROSS_COMPILE)gcc

# Compiler flags: 
# -Wall: show all warnings 
# -g: include debugging information
CFLAGS = -Wall -g

# The final executable name
TARGET = writer

# The first rule is the default
all: $(TARGET)

# Rule to link the object file into the final executable
$(TARGET): writer.o
	$(CC) $(CFLAGS) -o $(TARGET) writer.o

# Rule to compile the .c file into a .o (object) file
writer.o: writer.c
	$(CC) $(CFLAGS) -c writer.c -o writer.o

# Clean rule to remove the application and all object files
.PHONY: clean
clean:
	rm -f $(TARGET) *.o