# Compiler
CC = g++

# Debugging
DEBUG = -g

# Compiler Flags
CFLAGS = -c -Wall $(DEBUG)

# Target
TARGET = BST

$(TARGET): main.o binary_search_tree.o
	$(CC) main.o binary_search_tree.o -o BST

main.o: main.cpp binary_search_tree.h
	$(CC) $(CFLAGS) main.cpp
  
binary_search_tree.o: binary_search_tree.cpp binary_search_tree.h Node.h
  $(CC) $(CFLAGS) binary_search_tree.cpp

clean:
	rm *.o *~ $(TARGET)
