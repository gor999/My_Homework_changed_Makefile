all:create_directories main
src_files = src/encoder.cpp src/decoder.cpp
obj_files = $(patsubst src/%.cpp, obj/%.o, $(src_files))
lib_files = $(patsubst obj/%.o, lib/lib%.so, $(obj_files))
src_test  = src/test/unit_test.cpp
obj_test = $(patsubst src/test/%.cpp, obj/%.o,$(src_test))
lib_test = $(patsubst obj/%.o, lib/lib%.a, $(obj_test))

create_directories:
	mkdir -p obj/  bin/  lib/
obj/%.o:src/%.cpp
	g++ -c -I./inc/ -fPIC $^ -o $@ 
lib/lib%.so:obj/%.o 
	g++ -fPIC -shared $^ -o $@
obj/%.o:src/test/%.cpp 
	g++ -c -I./inc/ -fPIC $^ -o $@
lib/lib%.a:obj/%.o
	ar -cvq $@ $^

main:$(lib_files) $(obj_files) $(obj_test) $(lib_test)
	g++ src/main/main.cpp -L./lib -I./inc/ -ldecoder -lencoder -lunit_test -o bin/main
	export LD_LIBRARY_PATH=`pwd`/lib/
	./bin/main

remove:
	rm -rf obj bin lib
