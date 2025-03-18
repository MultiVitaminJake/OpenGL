# Compiler and Flags
CC = g++
CFLAGS = -Iinclude -Wall -Wextra -std=c++17

# Detect OS
ifeq ($(OS), Windows_NT)
	CFLAGS = -Iinclude -IC:/Programming/OpenGL/include -Wall -Wextra -std=c++17
	LDFLAGS = -LC:/Programming/OpenGL/lib -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32
    RM = del /Q
    MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
    TARGET = test.exe
else
    LDFLAGS = -lglfw -lGL -ldl -lpthread -lX11
    RM = rm -rf
    MKDIR = mkdir -p $(BUILD_DIR)
    TARGET = test
endif

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source and Object Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(SRC_FILES:.cpp=.o))
OBJ_FILES := $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(OBJ_FILES:.c=.o))

# Compilation Rules
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Linking
$(TARGET): $(OBJ_FILES)
	$(CC) -o $(TARGET) $(OBJ_FILES) $(LDFLAGS)

# Clean Build
clean:
	-$(RM) $(BUILD_DIR)/*.o $(TARGET)