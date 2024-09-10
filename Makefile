build:
	g++ -Wall -std=c++17 -I/usr/local/Cellar/glm/1.0.1/include -I~/Develop/cpp/githubs/sol2/include -I/usr/local/Cellar/lua/5.4.7/include/lua5.4 -I~/Develop/cpp/githubs src/*.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.4 -o gameengine;
run:
	./gameengine
clean:
	rm gameengine