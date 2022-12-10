CXXFLAGS = -std=c++11 -O2 -Wall -Wextra -Werror -pedantic

binaries = \
	swindow \

objects = $(binaries:=.o)

.PHONY: all
all: $(binaries)

$(binaries): %: %.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: %.cc
	$(CXX) -c $(CXXFLAGS) $^ -o $@

.PHONY: test
test: $(binaries) input tests.tush
	tush-check tests.tush

.PHONY: clean
clean:
	rm -f $(binaries) $(objects) tush-output
