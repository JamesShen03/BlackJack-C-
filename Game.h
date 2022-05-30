#ifndef _GAME_H__
#define _GAME_H__

#include<string>
#include<iostream>
using namespace std;

class Game {
public:
	Game();
	void bet();
	int getCredit();
	void surrender(int);
	bool insurance(int);
	void natural(int, int);
	bool checkNatural();
	bool checkDBust(int);
	void doubleDown();
	bool playerSplit(int);
	void resolution(int, int, int);
	int getBet();

private:
	int credit;
	int betAmount;
	bool playerNatural;
	bool aiNatural;
	int insuranceBet;

};

#endif

