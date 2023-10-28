.PHONY: build run test-diamond test-point test-pentagon test-hexagon test-vector clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all


run:
	./build/*_exe


test-vector:
	./build/*test_vector


test-pentagon:
	./build/*test_diamond


test-point:
	./build/*test_diamond


test-diamond:
	./build/*test_diamond


test-hexagon:
	./build/*test_diamond


clean:
	rm -rf ./build/