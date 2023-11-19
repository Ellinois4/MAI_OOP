.PHONY: build 

build:
	mkdir -p build
	cd ./build; cmake ..; make all


run:
	./build/*_exe


test-vector:
	./build/*test_vector


test-pentagon:
	./build/*test_pentagon


test-point:
	./build/*test_point


test-diamond:
	./build/*test_diamond


test-hexagon:
	./build/*test_hexagon


clean:
	rm -rf ./build/