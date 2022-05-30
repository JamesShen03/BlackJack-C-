#ifndef _CARDDECK_H__
#define _CARDDECK_H__

#include<string>
#include<array>

using namespace std;

struct Card {
	string face;
	string suit;

};

class CardDeck {
public:
	static const int numberOfCards = 312;
	static const int faces = 13;
	static const int suits = 4;
	CardDeck();
	void shuffle();
	Card deal(int&);
private:
	array<Card, numberOfCards>deck;

};

#endif