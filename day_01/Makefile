CXXFLAGS = -std=c++11 -O2 -Wall -Wextra -Werror -pedantic

binaries = \
	top_total \

objects = $(binaries:=.o)

.PHONY: all
all: $(binaries)

$(binaries): %: %.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: %.cc
	$(CXX) -c $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(binaries) $(objects)
