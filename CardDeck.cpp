#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include"CardDeck.h"

CardDeck::CardDeck() {
	static string suit[suits]{ "Hearts","Diamonds","Clubs","Spades"
	};
	static string face[faces]{ "Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
	for (int i = 0; i < deck.size(); ++i) {
		deck[i].face = face[i%faces];
		if (i<52)
		{
			deck[i].suit = suit[i / faces];
		}
		else if (i > 51 & i < 104)
		{
			deck[i].suit = suit[(i - 52) / faces];
		}
		else if (i > 103 & i < 156)
		{
			deck[i].suit = suit[(i - 104) / faces];
		}
		else if (i > 155 & i < 208)
		{
			deck[i].suit = suit[(i - 156) / faces];
		}
		else if (i > 207 & i < 260)
		{
			deck[i].suit = suit[(i - 208) / faces];
		}
		else if (i > 259 & i < 312)
		{
			deck[i].suit = suit[(i - 260) / faces];
		}
	}
	srand(static_cast<size_t>(time(nullptr)));

}

void CardDeck::shuffle() {
	for (size_t i = 0; i < deck.size(); i++) {
		int j{ rand() % numberOfCards };
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

Card CardDeck::deal(int &tracker) {
	tracker += 1;
	return deck[tracker];

}