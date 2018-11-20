CC=g++
TARGET = cfour
all: 
	$(CC) -Wall -std=c++11 connect_four.cpp -o $(TARGET)
clean:
	$(RM) $(TARGET)
