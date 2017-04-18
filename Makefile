# Compiler
CC = g++

# Debugging
DEBUG = -g

# Compiler Flags
CFLAGS = -c -Wall $(DEBUG)

# Target
TARGET = BST

$(TARGET): driver.o binary_search_tree.o
	$(CC) driver.o binary_search_tree.o -o BST

driver.o: driver.cpp binary_search_tree.h
	$(CC) $(CFLAGS) driver.cpp

binary_search_tree.o: binary_search_tree.cpp binary_search_tree.h Node.h
	$(CC) $(CFLAGS) binary_search_tree.cpp

clean:
	rm *.o *~ $(TARGET)
