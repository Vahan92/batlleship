SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
TARGET := bin/test1.exe bin/test2.exe
CC := g++
BAT_SOURCE := ../src/battleship.cpp
BAT_OBJECT := battleship.o
#dif:
#	@echo $(SOURCES)
#	@echo $(OBJECTS)

 
$(TARGET) : $(OBJECTS) $(BAT_OBJECT) 
	@mkdir -p bin ../test_results
#	@$(CC) $(OBJECTS) $(BAT_SOURCE) -o bin/$@
	@$(CC) obj/test1.o obj/$(BAT_OBJECT) -o bin/test1.exe
	@$(CC) obj/test2.o obj/$(BAT_OBJECT) -o bin/test2.exe

obj/%.o : src/%.cpp 
	@mkdir -p obj	
	$(CC) -c $< -o $@

$(BAT_OBJECT): $(SOURCES)
	@$(CC) -c ../src/$(BAT_SOURCE) -o obj/$(BAT_OBJECT)

.PHONY: clean
clean:
	@rm -rf bin
	@rm -rf obj 
	@rm -rf ../test_results

