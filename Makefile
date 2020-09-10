all: add-nbo

add-nbo: add-nbo.cpp
	g++ -g -o add-nbo add-nbo.cpp

clean:
	rm add-nbo
