#ifndef GAME_H_
#define GAME_H_

#include "graph.h"
#include "rand.h"
#include "score.h"

enum MARK{
	GAME_STOP = -1,
	GAME_PAUSE = 0,
	GAME_RUN = 1
};

//void PLAY();

class Game
{
public:
    int x;
    int y;
	Game();
	~Game();
	void gameInit();
	void createCube();
	void move(int dir);
	void roll();
	void stop();
	void erase();
	void down(int level);
	MARK getMark();
	void setMark( MARK );
	void printHelep();
	void printNextCube(Context* m_graph);
private:
    Score s;
    bool recoverPenal();
    bool isAttachBottom();
    bool isAttachLeft();
    bool isAttachRight();
    char getShape();
    bool setPenal();
    bool erasePenal();
    int m_penal[24][17];
	color m_color[24][17];///////////////////////
	Context* m_graph;

	Context* nextGraph;/////////////////
	MARK mark;//////////////////////////

    friend class player;

};

#endif