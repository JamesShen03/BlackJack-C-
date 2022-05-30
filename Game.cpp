#include "Game.h"

Game::Game() {
	credit = 500;
	betAmount = 0;
	playerNatural = false;
	aiNatural = false;
	insuranceBet = 0;
}
void Game::bet() {
	cout << "You have a total credit of: " << credit << "." << endl;
	cout << "How much would you like to bet?" << endl;
	cin >> betAmount;
	while (betAmount > credit || betAmount <= 0)
	{
		cout << "You do not have enough credit or amount entered is invalid! Enter new bet amount." << endl;
		cin >> betAmount;
		cin.clear();
		cin.ignore();
	}
	credit -= betAmount;
}

int Game::getCredit() {
	return credit;
}

void Game::natural(int a, int b) {
	if (a == 21) {
		playerNatural = true;
	}
	if (b == 21) {
		aiNatural = false;
	}

}
void Game::surrender(int a) {

	if (a == 1) {
		cout << "You have lost half of your main bet." << endl;
		credit += (betAmount / 2);
	}
}
bool Game::insurance(int a) {


	if (a == 1)
	{
		cout << "How much credit would you like to wager, (up to half of your original bet.)" << endl;
		cin >> insuranceBet;
		while ((betAmount / 2) < insuranceBet || insuranceBet <= 0 || insuranceBet > credit) {
			cout << "The amount that you have put down is too high or is invalid, Please Enter New Amount." << endl;
			cin >> insuranceBet;
			cin.clear();
			cin.ignore();
		}
		if (aiNatural == true && playerNatural == true) {
			cout << "Both you and the dealer have 'BlackJack'. You will get your original bet back. And get 2-1 payout on the insurance." << endl;
			credit = credit + betAmount + insuranceBet * 2;
			return true;

		}
		else if (aiNatural == true && playerNatural == false) {
			cout << "The dealer has 'BlackJack'. You will get a 2-1 payout on the insurance, but lose your main bet." << endl;
			credit = credit + insuranceBet * 2;
			return true;

		}
		else if (aiNatural == false && playerNatural == true) {
			cout << "The dealer does not have a 'BlackJack'. You will get a 3-1 payout on your main, but lose your insurance." << endl;
			credit = credit + betAmount * 3 - insuranceBet;
			return true;

		}
		else if (aiNatural == false && playerNatural == false) {
			cout << "The dealer does not have a 'BlackJack'. You have lost your insurance." << endl;
			credit -= insuranceBet;
			return false;
		}

	}
	else
		return false;
}

bool Game::checkNatural() {
	if (aiNatural == true && playerNatural == true) {
		cout << "Both you and the dealer have 'BlackJack'. You will get your original bet back." << endl;
		credit += betAmount;
		return true;
	}
	else if (aiNatural == true && playerNatural == false) {
		cout << "The dealer has 'BlackJack'. You have lost your main bet." << endl;
		return true;
	}
	else if (aiNatural == false && playerNatural == true) {
		cout << "The dealer does not have a 'BlackJack'. You will get a 3-1 payout on your main." << endl;
		credit = credit + betAmount * 3;
		return true;
	}
	else
		return false;
}

bool Game::checkDBust(int a) {
	if (a > 21) {
		cout << "'Bust for the dealer, you will now receive a 2-1 payout on your main." << endl;
		credit = credit + betAmount * 2;
		return true;
	}
	else
		return false;

}

void Game::doubleDown() {
	cout << "You have doubled down this round. you will now draw one additional card for the round." << endl;
	credit -= betAmount;
	betAmount = betAmount * 2;
}

bool Game::playerSplit(int a) {

	if (a == 1) {
		cout << "You have chosen to split this round." << endl << "You have put down an equal amount of bet for your new hand." << endl;
		credit -= betAmount;
		cout << "You will now play your first hand." << endl;
		return true;
	}
	else
		return false;
}

void Game::resolution(int a, int b, int c) {
	if (b == 0)
	{
		if (a > c) {
			cout << "You have won this round with a hand value of: " << a << endl << "to the dealer's: " << c << "." << endl;
			cout << "You will now be rewarded a 2-1 payout." << endl;
			credit = credit + betAmount * 2;
		}
		else if (a == c) {
			cout << "You and the dealer are tied at: " << a << endl;
			cout << "You will now get your main bet back." << endl;
			credit += betAmount;
		}
		else if (a < c) {
			cout << "You have lost this round with a hand value of: " << a << endl << "to the dealer's: " << c << "." << endl;
			cout << "You have lost your main bet." << endl;
		}
	}
	else if (b > 0) {
		if (a <= 21 && b <= 21) {
			if (a > c) {
				cout << "You have won your first hand  with a value of: " << a << endl << "to the dealer's: " << c << "." << endl;
				cout << "You will now be rewarded a 2-1 payout." << endl;
				credit = credit + betAmount * 2;

			}
			else if (a == c) {
				cout << "You and the dealer are tied at: " << a << endl;
				cout << "You will now get your main bet back." << endl;
				credit += betAmount;

			}
			else {
				cout << "You have lost your first hand with a hand value of: " << a << endl << "to the dealer's: " << c << "." << endl;
				cout << "You have lost your main bet." << endl;

			}
			if (b > c) {
				cout << "You have won your second hand  with a value of: " << b << endl << "to the dealer's: " << c << "." << endl;
				cout << "You will now be rewarded a 2-1 payout." << endl;
				credit = credit + betAmount * 2;
			}
			else if (b == c) {
				cout << "You and the dealer are tied at: " << b << endl;
				cout << "You will now get your main bet back." << endl;
				credit += betAmount;
			}
			else if (b < c) {
				cout << "You have lost your second hand with a hand value of: " << b << endl << "to the dealer's: " << c << "." << endl;
				cout << "You have lost your main bet." << endl;
			}
		}
		else if (a <= 21 && b > 21) {
			if (a > c) {
				cout << "You have won your first hand  with a value of: " << a << endl << "to the dealer's: " << c << "." << endl;
				cout << "You will now be rewarded a 2-1 payout." << endl;
				credit = credit + betAmount * 2;
			}
			else if (a == c) {
				cout << "You and the dealer are tied at: " << a << endl;
				cout << "You will now get your main bet back." << endl;
				credit += betAmount;
			}
			else if (a < c) {
				cout << "You have lost your first hand with a hand value of: " << a << endl << "to the dealer's: " << c << "." << endl;
				cout << "You have lost your main bet." << endl;
			}

		}
		else if (b <= 21 && a > 21) {
			if (b > c) {
				cout << "You have won your second hand  with a value of: " << b << endl << "to the dealer's: " << c << "." << endl;
				cout << "You will now be rewarded a 2-1 payout." << endl;
				credit = credit + betAmount * 2;

			}
			else if (b == c) {
				cout << "You and the dealer are tied at: " << b << endl;
				cout << "You will now get your main bet back." << endl;
				credit += betAmount;
			}
			else if (b < c) {
				cout << "You have lost your second hand with a hand value of: " << b << endl << "to the dealer's: " << c << "." << endl;
				cout << "You have lost your main bet." << endl;
			}
		}
	}
}

int Game::getBet() {
	return betAmount;
}