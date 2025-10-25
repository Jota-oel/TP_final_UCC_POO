CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Ilib

SRC = main.cpp lib/classes.cpp lib/util.cpp

TARGET = main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o lib/*.o

