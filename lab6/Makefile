.PHONY: build

build:
	mkdir -p build
	cd ./build; cmake ..; cmake --build .

run: build
	./build/*_exe

clean:
	rm -rf ./build

test-factory:
	./build/test/*_factory_test

test-npc:
	./build/test/*_npc_test

test-robber:
	./build/test/*_robber_test

test-bear:
	./build/test/*_bear_test

test-werewolf:
	./build/test/*_werewolf_test