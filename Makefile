CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wa,-mbig-obj
INC_DIR = -I include
SRC_DIR = src
OBJ_DIR = bin
TARGET = bin/ReglaFalsa

# Lista de archivos fuente
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INC_DIR) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
