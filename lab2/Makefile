.PHONY: build run test-vector test-three clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/*_exe

test-three:
	./build/*_test_three

test-vector:
	./build/*_test_vector

clean:
	rm -rf ./build/
