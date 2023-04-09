CC = g++
LANGUAGE_STANDARD = -std=c++17
COMPILER_FLAGS =  -Wall -Wfatal-errors -static-libstdc++
SRC_FILES = ./src/*.cpp
INCLUDE_PATHS = -Iinclude/ -Ilibs/sdl/x86_64-w64-mingw32/include/SDL2
LIBRARY_PATHS = -L./libs/sdl/x86_64-w64-mingw32/lib
LINKER_FLAGS = -lmingw32 -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf
OBJ_NAME = "Image Processing"

build : 
	$(CC) $(COMPILER_FLAGS) $(LANGUAGE_STANDARD) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)
run:
	./$(OBJ_NAME)

clean:
	rm $(OBJ_NAME)