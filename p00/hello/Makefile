hello: hello.cpp
	cppcheck hello.cpp --enable=all
	g++ -g hello.cpp -o hello

# la regla 'clean' se usa para eliminar el ejecutable antiguo
clean:
	rm hello
