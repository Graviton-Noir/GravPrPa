CXX=g++
CXXFLAGS= -g -Wall -Wextra -Werror -pedantic -std=c++14
OPENCVLIBS= -lopencv_core -lopencv_videoio -lopencv_highgui
OBJ=src/vid_reader.o

all: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OPENCVLIBS) $^ -o bin

check:

clean:
	rm -f bin $(OBJ)
