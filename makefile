CC=g++
TARGET = cfour
CFLAGS = -Wall -std=c++11
all: 
	$(CC) $(CFLAGS) connect_four.cpp -o $(TARGET)
clean:
	$(RM) $(TARGET)
