TARGET = main

CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./lib

SRC_DIR = .
LIB_DIR = ./lib
OBJ_DIR = ./obj

SRCS = $(SRC_DIR)/main.cpp \
       $(LIB_DIR)/Manager.cpp \
       $(LIB_DIR)/classes.cpp \
       $(LIB_DIR)/util.cpp

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "🔧 Enlazando $(TARGET)..."
	$(CXX) $(OBJS) -o $(TARGET)
	@echo "✅ Compilación finalizada."

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "📦 Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "🧹 Limpiando archivos objeto..."
	rm -rf $(OBJ_DIR) $(TARGET)

run: all
	@echo "🚀 Ejecutando..."
	./$(TARGET)
