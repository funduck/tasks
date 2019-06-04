TARGET = main.out

SRCS = \
       main.cpp 

.PHONY: all clean

all: $(SRCS)
	$(CXX) -Wall -Wextra -Werror -o $(TARGET) $(CXXFLAGS) $(SRCS)

clean:
	rm -rf $(TARGET)

