.PHONY: all clean test

all:
	mkdir -p build
	cd build && cmake .. && make

clean:
	rm -rf build

test: all
	cd build && ctest --output-on-failure
