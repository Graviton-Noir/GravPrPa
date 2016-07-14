CXX=g++
CXXFLAGS= -g -Wall -Wextra -Werror -pedantic -std=c++14
CVLIBS= -lopencv_core -lopencv_videoio -lopencv_highgui -lopencv_imgproc
OBJ=src/vid_reader.o

all: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o bin $(CVLIBS)

check:

clean:
	rm -f bin $(OBJ)
	rm -f output.mp4

run:	clean all
	./bin chaton.mp4
