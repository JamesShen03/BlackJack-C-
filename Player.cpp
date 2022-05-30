#include "Player.h"
Player::Player() {
	playerValue = 0;
	cardNumber = 0;
	secondCardNumber = 0;
	for (int i = 0; i < maxHandSize; i++) {
		playerHand[i] = 0;
		playerFaces[i] = 0;
		secondHand[i] = 0;
	}
	secondHandValue = 0;
}
void Player::deal(Card dealt) {
	cout << "Player has been dealt the card: " << dealt.face << " of " << dealt.suit << endl;
	if (dealt.face == "Ace") {
		playerHand[cardNumber] = 1;
		playerFaces[cardNumber] = 1;
		cardNumber += 1;
	}
	else if (dealt.face == "Two") {
		playerHand[cardNumber] = 2;
		playerFaces[cardNumber] = 2;
		cardNumber += 1;
	}
	else if (dealt.face == "Three") {
		playerHand[cardNumber] = 3;
		playerFaces[cardNumber] = 3;
		cardNumber += 1;
	}
	else if (dealt.face == "Four") {
		playerHand[cardNumber] = 4;
		playerFaces[cardNumber] = 4;
		cardNumber += 1;
	}
	else if (dealt.face == "Five") {
		playerHand[cardNumber] = 5;
		playerFaces[cardNumber] = 5;
		cardNumber += 1;
	}
	else if (dealt.face == "Six") {
		playerHand[cardNumber] = 6;
		playerFaces[cardNumber] = 6;
		cardNumber += 1;
	}
	else if (dealt.face == "Seven") {
		playerHand[cardNumber] = 7;
		playerFaces[cardNumber] = 7;
		cardNumber += 1;
	}
	else if (dealt.face == "Eight") {
		playerHand[cardNumber] = 8;
		playerFaces[cardNumber] = 8;
		cardNumber += 1;
	}
	else if (dealt.face == "Nine") {
		playerHand[cardNumber] = 9;
		playerFaces[cardNumber] = 9;
		cardNumber += 1;
	}
	else if (dealt.face == "Ten") {
		playerHand[cardNumber] = 10;
		playerFaces[cardNumber] = 10;
		cardNumber += 1;
	}
	else if (dealt.face == "Jack") {
		playerHand[cardNumber] = 10;
		playerFaces[cardNumber] = 11;
		cardNumber += 1;
	}
	else if (dealt.face == "Queen") {
		playerHand[cardNumber] = 10;
		playerFaces[cardNumber] = 12;
		cardNumber += 1;
	}
	else if (dealt.face == "King") {
		playerHand[cardNumber] = 10;
		playerFaces[cardNumber] = 13;
		cardNumber += 1;
	}
};
void Player::value() {
	playerValue = 0;

	bool numberOfA = false;
	for (int j = 0; j < maxHandSize; j++)
	{
		if (playerHand[j] == 1)
		{
			numberOfA = true;
		}
	}
	if (numberOfA == false)
	{
		for (int i = 0; i < maxHandSize; i++)
		{
			playerValue += playerHand[i];
		}
	}
	else if (numberOfA == true)
	{
		for (int m = 0; m < maxHandSize; m++)
		{
			playerValue += playerHand[m];
		}
		if (playerValue + 10 <= 21)
		{
			playerValue = playerValue + 10;
		}
		else if (playerValue + 10 > 21)
		{
			playerValue = playerValue;
		}
	}
};
int Player::returnValue() {
	return playerValue;
};

void Player::reset() {
	for (int i = 0; i < maxHandSize; i++) {
		playerHand[i] = 0;
		playerFaces[i] = 0;
		secondHand[i] = 0;
	}
	cardNumber = 0;
	secondCardNumber = 0;
}

bool Player::doubleDown(int a) {
	
	if (a == 1)
		return true;
	else
		return false;
}

bool Player::canSplit() {
	if (playerFaces[0] == playerFaces[1])
	{
		return true;
	}
	else
		return false;
}

void Player::splitted() {

	secondHand[secondCardNumber] = playerHand[1];
	secondCardNumber += 1;
	playerHand[1] = 0;
}

void Player::secondValue() {
	secondHandValue = 0;

	bool numberOfA = false;
	for (int j = 0; j < maxHandSize; j++)
	{
		if (secondHand[j] == 1)
		{
			numberOfA = true;
		}
	}
	if (numberOfA == false)
	{
		for (int i = 0; i < maxHandSize; i++)
		{
			secondHandValue += secondHand[i];
		}
	}
	else if (numberOfA == true)
	{
		for (int m = 0; m < maxHandSize; m++)
		{
			secondHandValue += secondHand[m];
		}
		if (secondHandValue + 10 <= 21)
		{
			secondHandValue = secondHandValue + 10;
		}
		else if (secondHandValue + 10 > 21)
		{
			secondHandValue = secondHandValue;
		}
	}
}

int Player::returnSecondValue() {
	return secondHandValue;
}

void Player::secondDeal(Card dealt) {
	cout << "Player has been dealt the card: " << dealt.face << " of " << dealt.suit << endl;
	if (dealt.face == "Ace") {
		secondHand[secondCardNumber] = 1;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Two") {
		secondHand[secondCardNumber] = 2;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Three") {
		secondHand[secondCardNumber] = 3;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Four") {
		secondHand[secondCardNumber] = 4;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Five") {
		secondHand[secondCardNumber] = 5;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Six") {
		secondHand[secondCardNumber] = 6;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Seven") {
		secondHand[secondCardNumber] = 7;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Eight") {
		secondHand[secondCardNumber] = 8;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Nine") {
		secondHand[secondCardNumber] = 9;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Ten") {
		secondHand[secondCardNumber] = 10;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Jack") {
		secondHand[secondCardNumber] = 10;
		secondCardNumber += 1;
	}
	else if (dealt.face == "Queen") {
		secondHand[secondCardNumber] = 10;
		secondCardNumber += 1;
	}
	else if (dealt.face == "King") {
		secondHand[secondCardNumber] = 10;
		secondCardNumber += 1;
	}

}

int Player:: returnCardNumber() {
	return cardNumber;
}