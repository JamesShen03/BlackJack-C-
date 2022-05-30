#include "Ai.h"
Ai::Ai() {
	aiValue = 0;
	cardNumber = 0;
	for (int i = 0; i < maxHandSize; i++) {
		aiHand[i] = 0;
	}
}
void Ai::deal(Card dealt) {
	if (cardNumber == 1) {
		cout << "Dealer has been dealt another card." << endl;
	}
	else {
		cout << "Dealer has been dealt the card: " << dealt.face << " of " << dealt.suit << endl;
	}
	if (dealt.face == "Ace") {
		aiHand[cardNumber] = 1;
		cardNumber += 1;
	}
	else if (dealt.face == "Two") {
		aiHand[cardNumber] = 2;
		cardNumber += 1;
	}
	else if (dealt.face == "Three") {
		aiHand[cardNumber] = 3;
		cardNumber += 1;
	}
	else if (dealt.face == "Four") {
		aiHand[cardNumber] = 4;
		cardNumber += 1;
	}
	else if (dealt.face == "Five") {
		aiHand[cardNumber] = 5;
		cardNumber += 1;
	}
	else if (dealt.face == "Six") {
		aiHand[cardNumber] = 6;
		cardNumber += 1;
	}
	else if (dealt.face == "Seven") {
		aiHand[cardNumber] = 7;
		cardNumber += 1;
	}
	else if (dealt.face == "Eight") {
		aiHand[cardNumber] = 8;
		cardNumber += 1;
	}
	else if (dealt.face == "Nine") {
		aiHand[cardNumber] = 9;
		cardNumber += 1;
	}
	else if (dealt.face == "Ten") {
		aiHand[cardNumber] = 10;
		cardNumber += 1;
	}
	else if (dealt.face == "Jack") {
		aiHand[cardNumber] = 10;
		cardNumber += 1;
	}
	else if (dealt.face == "Queen") {
		aiHand[cardNumber] = 10;
		cardNumber += 1;
	}
	else if (dealt.face == "King") {
		aiHand[cardNumber] = 10;
		cardNumber += 1;
	}
};
void Ai::value() {
	aiValue = 0;

	bool numberOfA = false;
	for (int j = 0; j < maxHandSize; j++)
	{
		if (aiHand[j] == 1)
		{
			numberOfA = true;
		}
	}
	if (numberOfA == false)
	{
		for (int i = 0; i < maxHandSize; i++)
		{
			aiValue += aiHand[i];
		}
	}
	else if (numberOfA == true)
	{
		for (int m = 0; m < maxHandSize; m++)
		{
			aiValue += aiHand[m];
		}
		if (aiValue + 10 <= 21)
		{
			aiValue = aiValue + 10;
		}
		else if (aiValue + 10 > 21)
		{
			aiValue = aiValue;
		}
	}
};
int Ai::returnValue() {
	return aiValue;
};

void Ai::reset() {
	for (int i = 0; i < maxHandSize; i++) {
		aiHand[i] = 0;
	}
	cardNumber = 0;
}

bool Ai::aceShowing() {
	if (aiHand[0] == 1)
	{
		return true;
	}
	else
		return false;
}

void Ai::revealHole() {
	cout << "The dealer's hole card is worth: " << aiHand[1] << endl;
}
int Ai::returnCardNumber() {
	return cardNumber;
}