#ifndef _AI_H__
#define _AI_H__
#include "CardDeck.h"
#include<string>
#include<iostream>
using namespace std;

class Ai {
public:
	Ai();
	void deal(Card);
	void value();
	int returnValue();
	static const int maxHandSize = 21;
	void reset();
	bool aceShowing();
	void revealHole();
	int returnCardNumber();
private:
	int aiValue;
	array <int, maxHandSize>aiHand;
	int cardNumber;

};

#endif
