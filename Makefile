
CXX = g++

CXXFLAGS = -Wall -std=c++11

LDFLAGS =

SOURCES = stupidOS_kauser.cpp FileSystem_kauser.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = stupidos

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
