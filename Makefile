main:
	g++ Game_of_Hero.cpp hero_class.cpp screens.cpp game_engine.cpp -o game.exe
	
map_func.o: map_func.cpp
	g++ map_func.cpp
	