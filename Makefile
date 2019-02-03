CXXFLAGS = -O2 -Wall -Wno-deprecated -g

all: hello

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
