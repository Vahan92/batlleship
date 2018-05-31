SOURCES := $(wildcard ./src/*.cpp)
OBJECTS := $(patsubst src/%.cpp, ./obj/%.o, $(SOURCE))
TARGET := test1.exe test2.exe
CC := g++

$(TARGET) : $(OBJECTS)
	@mkdir -p bin
	@$(CC) $^ -o bin/$@

obj/%.o : src/%.cpp 
	@mkdir -p obj	
	$(CC) -c $< -o $@

battleship.o: $(SOURCES)
	@$(CC) -c ../src/ battleship.cpp -o obj/battleship.obj

.PHONY: clean
clean:
	@rm -rf bin
	@rm -rf obj 