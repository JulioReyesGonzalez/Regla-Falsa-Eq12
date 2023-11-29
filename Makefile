# Makefile para compilar y ejecutar el juego Tetris con SDL2

CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -L"C:\msys64\mingw64\lib" -lmingw32 -lSDL2main -lSDL2

SRC_DIR = src
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SOURCES))
EXECUTABLE = $(BIN_DIR)/tutorial1

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -I"C:\msys64\mingw64\include\SDL2" -o $@ $^ $(LDFLAGS) -mconsole

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I"C:\msys64\mingw64\include\SDL2" -c -o $@ $<

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

