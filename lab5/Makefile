.PHONY: build

build:
	mkdir -p build
	cd ./build; cmake ..; cmake --build .

run:
	./build/*_exe

clean:
	rm -rf ./build

test-queue:
	./build/test/*_test_queue

test-allocator:
	./build/test/*_test_allocator