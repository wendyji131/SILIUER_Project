#compile marco
CC = g++
CFLAGS = -Wall
LDFLAGS = -lm
INCLUDES = -I/usr/include

#target and objects
tetris = test
//OBJECTS = main.o UI.o UIhandler.o Domain/RegisterLogin/RegisterLoginHandler.o Domain/RegisterLogin/RegisterLogin.o Domain/GameRule/cursor.o Domain/GameRule/gameBoard.o Domain/GameRule/GameRule.o Domain/GameRule/GameRuleHandler.o Domain/GameRule/pieceShape.o Domain/GameRule/player.o Domain/GameRule/randomNumber.o Domain/GameRule/Score.o Domain/GameRule/Tetris.o  TechnicalServices/Persistence/DB.o TechnicalServices/Security/security.o
#OBJECTS = *cpp
#make target:
clean:
	rm -rf ${tetris} ${OBJECTS}

#dependence
%.o : %.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
%.o : %.cc
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
