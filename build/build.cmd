set output=../bin/purgatory.exe
set engine=../engine/timer.cpp ../engine/game.cpp ../engine/imagehandler.cpp
set engine=%engine% ../engine/main.cpp  ../engine/world.cpp ../engine/statemachine.cpp
set engine=%engine% ../engine/music_player.cpp
set entities=../entities/creature.cpp ../entities/player.cpp ../entities/box.cpp
set flags= -lmingw32 -lSDLmain -lSDL -lSDL_mixer -DDEBUG -Wall
set includes=-I../includes

g++ -o %output% %engine% %entities% %flags% %includes%
