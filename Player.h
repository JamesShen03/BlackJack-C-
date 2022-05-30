#ifndef _PLAYER_H__
#define _PLAYER_H__
#include "CardDeck.h"
#include<string>
#include<iostream>
using namespace std;

class Player {
public:
	Player();
	void deal(Card);
	void value();
	int returnValue();
	static const int maxHandSize = 21;
	void reset();
	bool doubleDown(int);
	bool canSplit();
	void splitted();
	void secondValue();
	int returnSecondValue();
	void secondDeal(Card);
	int returnCardNumber();

private:
	int playerValue;
	array <int, maxHandSize>playerHand;
	array <int, maxHandSize>playerFaces;
	array<int, maxHandSize>secondHand;
	int cardNumber;
	int secondCardNumber;
	int secondHandValue;

};

#endif