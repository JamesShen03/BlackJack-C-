#include "Definitions.h"
#include "Sprite.h"
#include "CardDeck.h"
#include"Game.h"
#include"Player.h"
#include "Ai.h"









/*
12/14/2016

Xu Nan Shen

Programming Fundamentals 1
Professor: Domenic Caronzo

Blackjack(SDL)_ Version 3
VGP122A3_Shen_XuNan


*/
Game game;


int cardPos = -1;
int* cardPosition = &cardPos;
CardDeck deckOfCards;
Card card;
Player player1;
Ai ai1;
int playValue = 0;
int aValue = 0;
int secValue = 0;
bool split = false;
bool dDown = false;
Card aiHole;
int deckHand = 52;


void firstDeal();
void playNew();
void normalPlay();
void aiPlay();
void doubleDown();
void splitting();
void renderpCards(Card);
void renderaCards(Card);
void cleanUp();
void renderholeCard(Card);


/** Inialize Game Variables */
bool enter = false;
bool			done = false;
SDL_Window		*window = NULL;
SDL_Renderer	*renderer = NULL;

/** Initialize Event Variables */
SDL_Event		event;

/** Initialize timer variables */
int				deltaT = 75;			// defines delay in time for updating game loop
int				updatedTime = 0;			// used to determine if frame rate interval has elapse

											/** Initialize true type font variables.
											For text to be drawn, define
											- color of text
											- destination rect of location text will be drawn
											- font used
											- text surface to draw from
											*/
SDL_Color		color = { 0, 0, 0 };
SDL_Rect		dest = { 200 , 50 };	// height and width are dependant on whats being rendered
TTF_Font		*font = NULL;
SDL_Surface		*text = NULL;
SDL_Texture		*scoreTexture = NULL;



/** Initialize sprite variables */
Sprite			*background = NULL;
Sprite			*title = NULL;
Sprite			*h1 = NULL;
Sprite			*h2 = NULL;
Sprite			*h3 = NULL;
Sprite			*h4 = NULL;
Sprite			*h5 = NULL;
Sprite			*h6 = NULL;
Sprite			*h7 = NULL;
Sprite			*h8 = NULL;
Sprite			*h9 = NULL;
Sprite			*h10 = NULL;
Sprite			*hj= NULL;
Sprite			*hq = NULL;
Sprite			*hk = NULL;
Sprite			*c1 = NULL;
Sprite			*c2 = NULL;
Sprite			*c3 = NULL;
Sprite			*c4 = NULL;
Sprite			*c5 = NULL;
Sprite			*c6 = NULL;
Sprite			*c7 = NULL;
Sprite			*c8 = NULL;
Sprite			*c9 = NULL;
Sprite			*c10 = NULL;
Sprite			*cj = NULL;
Sprite			*cq = NULL;
Sprite			*ck = NULL;
Sprite			*s1 = NULL;
Sprite			*s2 = NULL;
Sprite			*s3 = NULL;
Sprite			*s4 = NULL;
Sprite			*s6 = NULL;
Sprite			*s5= NULL;
Sprite			*s7 = NULL;
Sprite			*s8 = NULL;
Sprite			*s9 = NULL;
Sprite			*s10 = NULL;
Sprite			*sj = NULL;
Sprite			*sq = NULL;
Sprite			*sk = NULL;
Sprite			*d1 = NULL;
Sprite			*d2 = NULL;
Sprite			*d3 = NULL;
Sprite			*d4 = NULL;
Sprite			*d6 = NULL;
Sprite			*d5 = NULL;
Sprite			*d7 = NULL;
Sprite			*d8 = NULL;
Sprite			*d9 = NULL;
Sprite			*d10 = NULL;
Sprite			*dj = NULL;
Sprite			*dq = NULL;
Sprite			*dk = NULL;
Sprite			*chipOne= NULL;
Sprite			*chipFive = NULL;
Sprite			*chipFifty = NULL;
Sprite			*chipHundred = NULL;
Sprite			*hole = NULL;
Sprite			*cardBack = NULL;
Sprite			*stern = NULL;
Sprite			*norm = NULL;
Sprite			*hap = NULL;
Sprite			*mil = NULL;


/** Initialize music and sound effect variables */
Mix_Music		*music = NULL;
Mix_Chunk		*blackjack = NULL;
Mix_Chunk		*deal = NULL;
Mix_Chunk		*deck = NULL;
Mix_Chunk		*doubledown = NULL;
Mix_Chunk		*hit = NULL;
Mix_Chunk		*leave = NULL;
Mix_Chunk		*splitS = NULL;
Mix_Chunk		*youlose = NULL;	

int main(int argc, char** argv)
{
	
	/** Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		cerr << "Unable to init SDL: " << SDL_GetError() << endl;
		return 1;
	}
	/** Close SDL at program end */
	atexit(SDL_Quit);

	/** Create Window for Project */
	window = SDL_CreateWindow("BlackJack", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (!window)
	{
		cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
		return 1;
	}

	/** Create Renderer to draw to */
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
		return 1;
	}

	/** Initialize TTF_Font */
	if (TTF_Init() < 0)
	{
		cerr << "TTF_Init Error: " << TTF_GetError() << endl;
		return 1;
	}
	/** Close TTF_Font at program end */
	atexit(TTF_Quit);

	/** Initialize SDL_Mixer */
	if (Mix_OpenAudio(AUDIO_RATE, AUDIO_FORMAT, AUDIO_CHANNELS, AUDIO_BUFFERS) < 0)
	{
		cerr << "Mix_OpenAudio Error: " << Mix_GetError() << endl;
		return 1;
	}
	/** Close SDL_Mixer at program end */
	atexit(Mix_CloseAudio);

	/** Initialize sprite properties */
	background	= new Sprite("Images/blackjack_table.jpg", 0, 0, 640, 480, renderer);
	title = new Sprite("Images/blackjack_title.png", 0, 0, 640, 480, renderer);

	h1 = new Sprite("Images/ace_of_hearts.jpg", 0, 220, 62, 90, renderer);
	h2 = new Sprite("Images/2_of_hearts.jpg", 0, 220, 62, 90, renderer);
	h3 = new Sprite("Images/3_of_hearts.jpg", 0, 220, 62, 90, renderer);
	h4 = new Sprite("Images/4_of_hearts.jpg", 0, 220, 62, 90, renderer);
	h5 = new Sprite("Images/5_of_hearts.jpg", 0, 220, 62, 90, renderer);
	h6 = new Sprite("Images/6_of_hearts.jpg", 0, 220, 62, 90, renderer);
	h7 = new Sprite("Images/7_of_hearts.jpg", 0, 220, 62, 90, renderer);
	h8 = new Sprite("Images/8_of_hearts.jpg", 0, 220, 62, 90, renderer);
	h9 = new Sprite("Images/9_of_hearts.jpg", 0, 220, 62, 90, renderer);
	h10 = new Sprite("Images/10_of_hearts.jpg", 0, 220, 62, 90, renderer);
	hj= new Sprite("Images/jack_of_hearts.jpg", 0, 220, 62, 90, renderer);
	hq = new Sprite("Images/queen_of_hearts.jpg", 0, 220, 62, 90, renderer);
	hk = new Sprite("Images/king_of_hearts.jpg", 0, 220, 62, 90, renderer);
	c1 = new Sprite("Images/ace_of_clubs.jpg", 0, 220, 62, 90, renderer);
	c2 = new Sprite("Images/2_of_clubs.jpg", 0, 220, 62, 90, renderer);
	c3 = new Sprite("Images/3_of_clubs.jpg", 0, 220, 62, 90, renderer);
	c4 = new Sprite("Images/4_of_clubs.jpg", 0, 220, 62, 90, renderer);
	c5 = new Sprite("Images/5_of_clubs.jpg", 0, 220, 62, 90, renderer);
	c6 = new Sprite("Images/6_of_clubs.jpg", 0, 220, 62, 90, renderer);
	c7 = new Sprite("Images/7_of_clubs.jpg", 0, 220, 62, 90, renderer);
	c8 = new Sprite("Images/8_of_clubs.jpg", 0, 220, 62, 90, renderer);
	c9 = new Sprite("Images/9_of_clubs.jpg", 0, 220, 62, 90, renderer);
	c10 = new Sprite("Images/10_of_clubs.jpg", 0, 220, 62, 90, renderer);
	cj = new Sprite("Images/jack_of_clubs.jpg", 0, 220, 62, 90, renderer);
	cq = new Sprite("Images/queen_of_clubs.jpg", 0, 220, 62, 90, renderer);
	ck = new Sprite("Images/king_of_clubs.jpg", 0, 220, 62, 90, renderer);
	d1 = new Sprite("Images/ace_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	d2 = new Sprite("Images/2_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	d3 = new Sprite("Images/3_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	d4 = new Sprite("Images/4_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	d5 = new Sprite("Images/5_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	d6 = new Sprite("Images/6_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	d7 = new Sprite("Images/7_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	d8 = new Sprite("Images/8_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	d9 = new Sprite("Images/9_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	d10 = new Sprite("Images/10_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	dj = new Sprite("Images/jack_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	dq = new Sprite("Images/queen_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	dk = new Sprite("Images/king_of_diamonds.jpg", 0, 220, 62, 90, renderer);
	s1 = new Sprite("Images/ace_of_spades.jpg", 0, 220, 62, 90, renderer);
	s2 = new Sprite("Images/2_of_spades.jpg", 0, 220, 62, 90, renderer);
	s3 = new Sprite("Images/3_of_spades.jpg", 0, 220, 62, 90, renderer);
	s4 = new Sprite("Images/4_of_spades.jpg", 0, 220, 62, 90, renderer);
	s5 = new Sprite("Images/5_of_spades.jpg", 0, 220, 62, 90, renderer);
	s6 = new Sprite("Images/6_of_spades.jpg", 0, 220, 62, 90, renderer);
	s7 = new Sprite("Images/7_of_spades.jpg", 0, 220, 62, 90, renderer);
	s8 = new Sprite("Images/8_of_spades.jpg", 0, 220, 62, 90, renderer);
	s9 = new Sprite("Images/9_of_spades.jpg", 0, 220, 62, 90, renderer);
	s10 = new Sprite("Images/10_of_spades.jpg", 0, 220, 62, 90, renderer);
	sj = new Sprite("Images/jack_of_spades.jpg", 0, 220, 62, 90, renderer);
	sq = new Sprite("Images/queen_of_spades.jpg", 0, 220, 62, 90, renderer);
	sk = new Sprite("Images/king_of_spades.jpg", 0, 220, 62, 90, renderer);
	chipOne = new Sprite("Images/1chip.jpg", 0, 220, 54, 57, renderer);
	chipFive = new Sprite("Images/5chip.jpg", 0, 220, 53, 59, renderer);
	chipFifty = new Sprite("Images/50chip.jpg", 0, 220, 56, 57, renderer);
	chipHundred = new Sprite("Images/100chip.jpg", 0, 220, 55, 57, renderer);
	hole = new Sprite("Images/holeCard.jpg", 80, 110, 62, 90, renderer);
	cardBack = new Sprite("Images/cardBack.jpg", 480, 110, 62, 90, renderer);
	stern = new Sprite("Images/avatarStern.png", 500, 340, 128, 128, renderer);
	norm = new Sprite("Images/avatarNorm.png", 500, 340, 128, 128, renderer);
	hap = new Sprite("Images/avatarHap.png", 500, 340, 128, 128, renderer);
	mil = new Sprite("Images/avatarMil.png", 500, 340, 128, 128, renderer);

	/** Open a font to use when rendering text */
	font = TTF_OpenFont("Fonts/arial.ttf", 20);
	if (!font)
	{
		cerr << "TTF_OpenFont Error: " << TTF_GetError() << endl;
		return 1;
	}

	/** Set style for text, if needed */
	TTF_SetFontStyle(font, TTF_STYLE_BOLD | TTF_STYLE_ITALIC);

	/** Set message for text */
	text = TTF_RenderText_Blended(font, to_string(game.getCredit()).c_str(), color);
	scoreTexture = SDL_CreateTextureFromSurface(renderer, text);
	
	/** Update width and height of destination to fit text */
	dest.w = text->w;
	dest.h = text->h;




	/** Load music sound file */
	music = Mix_LoadMUS("Sounds/theme.mid");
	
	/** Check if audio file was opened */
	if (!music)
		cerr << "Mix_LoadMUS Error: " << Mix_GetError() << endl;


	blackjack = Mix_LoadWAV("Sounds/blackjack.wav");
	deal = Mix_LoadWAV("Sounds/deal.wav");
	deck = Mix_LoadWAV("Sounds/deck.wav");
	doubledown = Mix_LoadWAV("Sounds/doubledown.wav");
	hit = Mix_LoadWAV("Sounds/hit.wav");
	leave = Mix_LoadWAV("Sounds/leave.wav");
	splitS = Mix_LoadWAV("Sounds/split.wav");
	youlose = Mix_LoadWAV("Sounds/youlose.wav");



	/** Begin music */
	Mix_PlayMusic(music, -1);

	/** Keep game running until done is 'true' */
	while (!done)
	{
		while (!enter)
		{			/** Update game loop */
			if (SDL_GetTicks() - updatedTime >= deltaT)
			{
				/** Poll for Events */
				while (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
						/** Check if user tries to quit the window */
					case SDL_QUIT:
						done = true;		// Break out of loop to end game
						break;

						/**	Check if the ESC key was pressed */
					case SDL_KEYDOWN:

						/**	Check if 'ESC' was pressed */
						if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
							done = true;	// Break out of loop to end game

											/**	Check if 'SPACE' was pressed */
						if (event.key.keysym.scancode == SDL_SCANCODE_RETURN)
							enter = true;

					}
					break;
				}
				title->draw(renderer);
				/** Update display */
				SDL_RenderPresent(renderer);

				/** update time */
				updatedTime = SDL_GetTicks();
			}
		}


			/** Poll for Events */
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
					/** Check if user tries to quit the window */
				case SDL_QUIT:
					done = true;		// Break out of loop to end game
					break;
					
					/**	Check if a key was pressed */
				case SDL_KEYDOWN:
					
					/**	Check if 'ESC' was pressed */
					if (event.key.keysym.sym == SDLK_ESCAPE)
						done = true;	// Break out of loop to end game
					break;
				}


			

			/** Draw all sprites */
			background->draw(renderer);


			/** Draw text to renderer*/
			SDL_RenderCopy(renderer, scoreTexture, NULL, &dest);


			/** Update display */
			SDL_RenderPresent(renderer);

			/** update time */
			updatedTime = SDL_GetTicks();

			deckOfCards.shuffle();

			playNew();



		}



	}

	/** Free memory used for sprites */
	delete background;


	/** Stop and free music. Free all sound effects */
	Mix_HaltMusic();
	Mix_FreeMusic(music);


	/** Free text surfaces */
	SDL_FreeSurface(text); 
	SDL_DestroyTexture(scoreTexture);
	TTF_CloseFont(font);

	return 0;
}


void playNew() {


	
	player1.reset();
	split = false;
	dDown = false;
	ai1.reset();
	if (game.getCredit() > 0) {
		int decision = 0;
		bool decided1 = false;

		cout << "Please left click in game window to start a game, right click to end program!" << endl;

		while (!decided1)
		{			/** Update game loop */
			if (SDL_GetTicks() - updatedTime >= deltaT)
			{
				/** Poll for Events */
				while (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
						/** Check if user tries to quit the window */
					case SDL_QUIT:
						done = true;		// Break out of loop to end game
						break;

						/**	Check if the ESC key was pressed */
					case SDL_MOUSEBUTTONDOWN:

						/**	Check if 'ESC' was pressed */
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							decided1 = true;
							decision = 1;
						}
						else if (event.button.button == SDL_BUTTON_RIGHT)
						{
							decided1 = true;
							decision = 2;
						}

					}
					break;
				}

				updatedTime = SDL_GetTicks();
			}
		}



		if (decision == 1) {		
			
			background->draw(renderer);

			/** Set message for text */
			text = TTF_RenderText_Blended(font, to_string(game.getCredit()).c_str(), color);
			scoreTexture = SDL_CreateTextureFromSurface(renderer, text);

			/** Update width and height of destination to fit text */
			dest.w = text->w;
			dest.h = text->h;

			/** Draw text to renderer*/
			SDL_RenderCopy(renderer, scoreTexture, NULL, &dest);

			norm->draw(renderer);

			SDL_RenderPresent(renderer);
			deckHand -= 1;
			if (deckHand < 1) {
				deckOfCards.shuffle();
				deckHand = 52;
			}
			Mix_PlayChannel(-1, deck, 0);

			cardBack->setXPos(480);
			for (int i = 0; i < deckHand; i++) {
				cardBack->draw(renderer);
				cardBack->move(1, 0);
				SDL_RenderPresent(renderer);
			}

			game.bet();
			mil->draw(renderer);

			SDL_RenderPresent(renderer);

			for (int i = 0; i < ((game.getBet()) / 100); i++) {
				chipHundred->setXPos(rand()%319+160);
				chipHundred->setYPos(rand() % 160 + 160);
				chipHundred->draw(renderer);
				SDL_RenderPresent(renderer);
			}
			for (int j = 0; j < ((game.getBet()) % 100)/50; j++) {
				chipFifty->setXPos(rand() % 319 + 160);
				chipFifty->setYPos(rand() % 160 + 160);
				chipFifty->draw(renderer);
				SDL_RenderPresent(renderer);
			}
			for (int j = 0; j < (game.getBet()%100%50/5); j++) {
				chipFive->setXPos(rand() % 319 + 160);
				chipFive->setYPos(rand() % 160 + 160);
				chipFive->draw(renderer);
				SDL_RenderPresent(renderer);
			}
			for (int j = 0; j < (game.getBet() % 100 % 50 % 5/1); j++) {
				chipOne->setXPos(rand() % 319 + 160);
				chipOne->setYPos(rand() % 160 + 160);
				chipOne->draw(renderer);
				SDL_RenderPresent(renderer);
			}
			firstDeal();

			if (ai1.aceShowing() == true) {
				stern->draw(renderer);

				SDL_RenderPresent(renderer);
				int decision;
				bool decided1 = false;
				cout << "The Dealer has 'Ace' showing. Do you want to surrender your hand this turn; you will lose half of your main bet. Left click for yes, Right click for no." << endl;
				while (!decided1)
				{			/** Update game loop */
					if (SDL_GetTicks() - updatedTime >= deltaT)
					{
						/** Poll for Events */
						while (SDL_PollEvent(&event))
						{
							switch (event.type)
							{
								/** Check if user tries to quit the window */
							case SDL_QUIT:
								done = true;		// Break out of loop to end game
								break;

								/**	Check if the ESC key was pressed */
							case SDL_MOUSEBUTTONDOWN:

								/**	Check if 'ESC' was pressed */
								if (event.button.button == SDL_BUTTON_LEFT)
								{
									decided1 = true;
									decision = 1;
								}
								else if (event.button.button == SDL_BUTTON_RIGHT)
								{
									decided1 = true;
									decision = 2;
								}

							}
							break;
						}

						updatedTime = SDL_GetTicks();
					}
				}
				game.surrender(decision);

				if (decision == 1) {
					playNew();
				}
				else
				{
					game.natural(playValue, aValue);

					mil->draw(renderer);

					SDL_RenderPresent(renderer);

					int decision2;
					bool decided2 = false;
					cout << "Dealer's face-up card is an ace. Would you like to take insurance? Left Click for yes, Right Click for no." << endl;

					while (!decided2)
					{			/** Update game loop */
						if (SDL_GetTicks() - updatedTime >= deltaT)
						{
							/** Poll for Events */
							while (SDL_PollEvent(&event))
							{
								switch (event.type)
								{
									/** Check if user tries to quit the window */
								case SDL_QUIT:
									done = true;		// Break out of loop to end game
									break;

									/**	Check if the ESC key was pressed */
								case SDL_MOUSEBUTTONDOWN:

									/**	Check if 'ESC' was pressed */
									if (event.button.button == SDL_BUTTON_LEFT)
									{
										decided2 = true;
										decision2 = 1;
									}
									else if (event.button.button == SDL_BUTTON_RIGHT)
									{
										decided2 = true;
										decision2 = 2;
									}

								}
								break;
							}

							updatedTime = SDL_GetTicks();
						}
					}

					bool insurDecision = game.insurance(decision2);
					if (insurDecision == true) {
						playNew();
					}
				}
			}
			bool naturalEnd = game.checkNatural();
			norm->draw(renderer);

			SDL_RenderPresent(renderer);
			if (naturalEnd == true) {
				Mix_PlayChannel(-1, blackjack, 0);
				playNew();
			}

			splitting();
			if (split == false) {
				doubleDown();
			}
			if (split == false && dDown == false)
			{
				normalPlay();
			}
			aiPlay();

			player1.value();
			playValue = player1.returnValue();
			ai1.value();
			aValue = ai1.returnValue();
			player1.secondValue();
			secValue = player1.returnSecondValue();
			game.resolution(playValue, secValue, aValue);
			playNew();
		}
		else if(decision == 2) {
			cout << "Thank You for playing!" << endl;
			SDL_RenderPresent(renderer);
			int leavedecision = 0;
			bool leavedecided = false;
			cout << "Left Click To leave Game now." << endl;
			Mix_PlayChannel(-1, leave, 0);
			while (!leavedecided)
			{			/** Update game loop */
				if (SDL_GetTicks() - updatedTime >= deltaT)
				{
					/** Poll for Events */
					while (SDL_PollEvent(&event))
					{
						switch (event.type)
						{
							/** Check if user tries to quit the window */
						case SDL_QUIT:
							done = true;		// Break out of loop to end game
							break;

							/**	Check if the ESC key was pressed */
						case SDL_MOUSEBUTTONDOWN:

							/**	Check if 'ESC' was pressed */
							if (event.button.button == SDL_BUTTON_LEFT)
							{
								leavedecided = true;
								leavedecision = 1;
							}


						}
						break;
					}

					updatedTime = SDL_GetTicks();
				}
			}

			if (leavedecision == 1) {
				cleanUp();
				exit(0);
				
			}
		}
	}
	else {
		cout << "You have ran out of credits to play!" << endl;
		int leavedecision = 0;
		bool leavedecided = false;
		cout << "Left Click To leave Game now." << endl;
		Mix_PlayChannel(-1, leave, 0);
		while (!leavedecided)
		{			/** Update game loop */
			if (SDL_GetTicks() - updatedTime >= deltaT)
			{
				/** Poll for Events */
				while (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
						/** Check if user tries to quit the window */
					case SDL_QUIT:
						done = true;		// Break out of loop to end game
						break;

						/**	Check if the ESC key was pressed */
					case SDL_MOUSEBUTTONDOWN:

						/**	Check if 'ESC' was pressed */
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							leavedecided = true;
							leavedecision = 1;
						}


					}
					break;
				}

				updatedTime = SDL_GetTicks();
			}
		}

		if (leavedecision == 1) {
			cleanUp();
			exit(0);
			
		}
		
	}

}

void normalPlay() {
	int decision = 0;
	bool decided = false;
	player1.value();
	playValue = player1.returnValue();
	cout << "You currently have a hand value of: " << playValue << endl << "Would you like to hit or stand. Left Click for hit or Right click to stand." << endl;
	hap->draw(renderer);

	SDL_RenderPresent(renderer);
	while (!decided)
	{			/** Update game loop */
		if (SDL_GetTicks() - updatedTime >= deltaT)
		{
			/** Poll for Events */
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
					/** Check if user tries to quit the window */
				case SDL_QUIT:
					done = true;		// Break out of loop to end game
					break;

					/**	Check if the ESC key was pressed */
				case SDL_MOUSEBUTTONDOWN:

					/**	Check if 'ESC' was pressed */
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						decided = true;
						decision = 1;
					}
					else if (event.button.button == SDL_BUTTON_RIGHT)
					{
						decided = true;
						decision = 2;
					}

				}
				break;
			}

			updatedTime = SDL_GetTicks();
		}
	}



	while (decision != 2 && playValue <= 21)
	{
		Mix_PlayChannel(-1, hit, 0);
		card = deckOfCards.deal(*cardPosition);
		player1.deal(card);
		renderpCards(card);
		cout << endl;
		player1.value();
		playValue = player1.returnValue();
		if (playValue > 21)
		{
			cout << "BUST! You have lost this round of play." << playValue << endl;
			Mix_PlayChannel(-1, youlose, 0);

			playNew();
		}
		else if (playValue <= 21)
		{
			decided = false;
			cout << "You currently have a hand value of: " << playValue << endl << "Would you like to hit or stand. Left Click for hit or Right click to stand." << endl;

			while (!decided)
			{			/** Update game loop */
				if (SDL_GetTicks() - updatedTime >= deltaT)
				{
					/** Poll for Events */
					while (SDL_PollEvent(&event))
					{
						switch (event.type)
						{
							/** Check if user tries to quit the window */
						case SDL_QUIT:
							done = true;		// Break out of loop to end game
							break;

							/**	Check if the ESC key was pressed */
						case SDL_MOUSEBUTTONDOWN:

							/**	Check if 'ESC' was pressed */
							if (event.button.button == SDL_BUTTON_LEFT)
							{
								decided = true;
								decision = 1;
							}
							else if (event.button.button == SDL_BUTTON_RIGHT)
							{
								decided = true;
								decision = 2;
							}

						}
						break;
					}

					updatedTime = SDL_GetTicks();
				}
			}
		}
	}

}

void aiPlay() {
	ai1.value();
	aValue = ai1.returnValue();
	ai1.revealHole();
	renderholeCard(aiHole);
	while (aValue < 17) {
		card = deckOfCards.deal(*cardPosition);
		ai1.deal(card);
		renderaCards(card);
		cout << endl;

		ai1.value();
		aValue = ai1.returnValue();
	}
	bool Dbust = game.checkDBust(aValue);
	if (Dbust == true)
	{
		hap->draw(renderer);

		SDL_RenderPresent(renderer);
		playNew();
	}
}

void doubleDown() {
	bool decided = false;
	int decision;
	cout << "You have the option to double down on this round. Left-Click for yes, Right Click for no." << endl;
	mil->draw(renderer);

	SDL_RenderPresent(renderer);

	while (!decided)
	{			/** Update game loop */
		if (SDL_GetTicks() - updatedTime >= deltaT)
		{
			/** Poll for Events */
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
					/** Check if user tries to quit the window */
				case SDL_QUIT:
					done = true;		// Break out of loop to end game
					break;

					/**	Check if the ESC key was pressed */
				case SDL_MOUSEBUTTONDOWN:

					/**	Check if 'ESC' was pressed */
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						decided = true;
						decision = 1;
					}
					else if (event.button.button == SDL_BUTTON_RIGHT)
					{
						decided = true;
						decision = 2;
					}

				}
				break;
			}

			updatedTime = SDL_GetTicks();
		}
	}
	bool doubleDown = player1.doubleDown(decision);
	if (doubleDown == true) {
		dDown = true;
		Mix_PlayChannel(-1, doubledown, 0);

		game.doubleDown();
		card = deckOfCards.deal(*cardPosition);
		player1.deal(card);
		renderpCards(card);
		cout << endl;
		player1.value();
		playValue = player1.returnValue();
		if (playValue > 21)
		{
			cout << "BUST! You have lost this round of play." << playValue << endl;
			Mix_PlayChannel(-1, youlose, 0);

			playNew();
		}
	}

}

void firstDeal() {
	hap->draw(renderer);

	SDL_RenderPresent(renderer);
	card = deckOfCards.deal(*cardPosition);
	player1.deal(card);
	renderpCards(card);
	cout << endl;

	card = deckOfCards.deal(*cardPosition);
	ai1.deal(card);
	renderaCards(card);
	cout << endl;

	card = deckOfCards.deal(*cardPosition);
	player1.deal(card);
	renderpCards(card);
	cout << endl;

	card = deckOfCards.deal(*cardPosition);
	aiHole = card;
	ai1.deal(card);
	hole->draw(renderer);
	SDL_RenderPresent(renderer);

	cout << endl;
	player1.value();
	ai1.value();
	playValue = player1.returnValue();
	aValue = ai1.returnValue();

}

void splitting() {

	if (player1.canSplit() == true) {
		SDL_RenderPresent(renderer);
	
		bool decided = false;
		int decision;
		cout << "You have the option to split your hand this round. Left Click for yes, right click for no." << endl;
		while (!decided)
		{			/** Update game loop */
			if (SDL_GetTicks() - updatedTime >= deltaT)
			{
				/** Poll for Events */
				while (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
						/** Check if user tries to quit the window */
					case SDL_QUIT:
						done = true;		// Break out of loop to end game
						break;

						/**	Check if the ESC key was pressed */
					case SDL_MOUSEBUTTONDOWN:

						/**	Check if 'ESC' was pressed */
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							decided = true;
							decision = 1;
						}
						else if (event.button.button == SDL_BUTTON_RIGHT)
						{
							decided = true;
							decision = 2;
						}

					}
					break;
				}

				updatedTime = SDL_GetTicks();
			}
		}

		bool splitON = game.playerSplit(decision);
		if (splitON == true) {
			Mix_PlayChannel(-1, splitS, 0);
			split = true;
			player1.splitted();
			char decision = 'h';
			player1.value();
			playValue = player1.returnValue();

			int decision2 = 0;
			bool decided2 = false;
			player1.value();
			playValue = player1.returnValue();
			cout << "You currently have a hand value of: " << playValue << endl << "Would you like to hit or stand. Left Click for hit or Right click to stand." << endl;

			while (!decided2)
			{			/** Update game loop */
				if (SDL_GetTicks() - updatedTime >= deltaT)
				{
					/** Poll for Events */
					while (SDL_PollEvent(&event))
					{
						switch (event.type)
						{
							/** Check if user tries to quit the window */
						case SDL_QUIT:
							done = true;		// Break out of loop to end game
							break;

							/**	Check if the ESC key was pressed */
						case SDL_MOUSEBUTTONDOWN:

							/**	Check if 'ESC' was pressed */
							if (event.button.button == SDL_BUTTON_LEFT)
							{
								decided2 = true;
								decision2 = 1;
							}
							else if (event.button.button == SDL_BUTTON_RIGHT)
							{
								decided2 = true;
								decision2 = 2;
							}

						}
						break;
					}

					updatedTime = SDL_GetTicks();
				}
			}
			while (decision != 2 && playValue <= 21)
			{
				

				Mix_PlayChannel(-1, hit, 0);
				card = deckOfCards.deal(*cardPosition);
				player1.deal(card);
				renderpCards(card);
				cout << endl;
				player1.value();
				playValue = player1.returnValue();
				if (playValue > 21)
				{
					cout << "BUST! You have lost this hand." << playValue << endl;
				}
				else if (playValue <= 21)
				{
					decided2 = false;
					cout << "You currently have a hand value of: " << playValue << endl << "Would you like to hit or stand. Left Click for hit or Right click to stand." << endl;

					while (!decided2)
					{			/** Update game loop */
						if (SDL_GetTicks() - updatedTime >= deltaT)
						{
							/** Poll for Events */
							while (SDL_PollEvent(&event))
							{
								switch (event.type)
								{
									/** Check if user tries to quit the window */
								case SDL_QUIT:
									done = true;		// Break out of loop to end game
									break;

									/**	Check if the ESC key was pressed */
								case SDL_MOUSEBUTTONDOWN:

									/**	Check if 'ESC' was pressed */
									if (event.button.button == SDL_BUTTON_LEFT)
									{
										decided2 = true;
										decision = 1;
									}
									else if (event.button.button == SDL_BUTTON_RIGHT)
									{
										decided2 = true;
										decision = 2;
									}

								}
								break;
							}

							updatedTime = SDL_GetTicks();
						}
					}
				}
			}
			cout << "You will now play your second hand." << endl;
			int decision3 = 0;
			bool decided3 = false;
			player1.secondValue();
			secValue = player1.returnSecondValue();
			cout << "You currently have a hand value of: " << secValue << endl << "Would you like to hit or stand. Left Click to hit or Right Click to stand.";

			while (!decided3)
			{			/** Update game loop */
				if (SDL_GetTicks() - updatedTime >= deltaT)
				{
					/** Poll for Events */
					while (SDL_PollEvent(&event))
					{
						switch (event.type)
						{
							/** Check if user tries to quit the window */
						case SDL_QUIT:
							done = true;		// Break out of loop to end game
							break;

							/**	Check if the ESC key was pressed */
						case SDL_MOUSEBUTTONDOWN:

							/**	Check if 'ESC' was pressed */
							if (event.button.button == SDL_BUTTON_LEFT)
							{
								decided3 = true;
								decision3 = 1;
							}
							else if (event.button.button == SDL_BUTTON_RIGHT)
							{
								decided3 = true;
								decision3 = 2;
							}

						}
						break;
					}

					updatedTime = SDL_GetTicks();
				}
			}
			while (decision3 != 2 && secValue <= 21)
			{
				Mix_PlayChannel(-1, hit, 0);
				card = deckOfCards.deal(*cardPosition);
				player1.secondDeal(card);
				renderpCards(card);
				cout << endl;
				player1.secondValue();
				secValue = player1.returnSecondValue();
				if (secValue > 21)
				{
					cout << "BUST! You have lost this hand." << secValue << endl;
				}
				else if (secValue <= 21)
				{
					decided3 = false;
					cout << "You currently have a hand value of: " << secValue << endl << "Would you like to hit or stand. Left Click for hit or Right click to stand." << endl;

					while (!decided3)
					{			/** Update game loop */
						if (SDL_GetTicks() - updatedTime >= deltaT)
						{
							/** Poll for Events */
							while (SDL_PollEvent(&event))
							{
								switch (event.type)
								{
									/** Check if user tries to quit the window */
								case SDL_QUIT:
									done = true;		// Break out of loop to end game
									break;

									/**	Check if the ESC key was pressed */
								case SDL_MOUSEBUTTONDOWN:

									/**	Check if 'ESC' was pressed */
									if (event.button.button == SDL_BUTTON_LEFT)
									{
										decided3 = true;
										decision3 = 1;
									}
									else if (event.button.button == SDL_BUTTON_RIGHT)
									{
										decided3 = true;
										decision3 = 2;
									}

								}
								break;
							}

							updatedTime = SDL_GetTicks();
						}
					}
				}
			}

			if (secValue > 21 && playValue > 21)
			{
				cout << "'Bust' for both of your hands! you have lost this round of play!" << endl;
				Mix_PlayChannel(-1, youlose, 0);
				playNew();
			}
		}
	}

}

void renderpCards(Card a) {
	Mix_PlayChannel(-1, deal, 0);

	if (a.suit == "Diamonds") {
		if (a.face == "Ace") {
			d1->setXPos((player1.returnCardNumber()) * 40);
			d1->setYPos(360);
			d1->draw(renderer);
			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			d2->setXPos((player1.returnCardNumber()) * 40);
			d2->setYPos(360);
			d2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			d3->setXPos((player1.returnCardNumber()) * 40);
			d3->setYPos(360);
			d3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			d4->setXPos((player1.returnCardNumber()) * 40);
			d4->setYPos(360);
			
			d4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			d5->setXPos((player1.returnCardNumber()) * 40);
			d5->setYPos(360);
			d5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			d6->setXPos((player1.returnCardNumber()) * 40);
			d6->setYPos(360);
			d6->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			d7->setXPos((player1.returnCardNumber()) * 40);
			d7->setYPos(360);
			d7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			d8->setXPos((player1.returnCardNumber()) * 40);
			d8->setYPos(360);
			d8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			d9->setXPos((player1.returnCardNumber()) * 40);
			d9->setYPos(360);
			d9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			d10->setXPos((player1.returnCardNumber()) * 40);
			d10->setYPos(360);
			d10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			dj->setXPos((player1.returnCardNumber()) * 40);
			dj->setYPos(360);
			dj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			dq->setXPos((player1.returnCardNumber()) * 40);
			dq->setYPos(360);
			dq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			dk->setXPos((player1.returnCardNumber()) * 40);
			dk->setYPos(360);
			dk->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}
	else if (a.suit == "Clubs") {
		if (a.face == "Ace") {
			c1->setXPos((player1.returnCardNumber()) * 40);
			c1->setYPos(360);
			c1->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			c2->setXPos((player1.returnCardNumber()) * 40);
			c2->setYPos(360);
			c2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			c3->setXPos((player1.returnCardNumber()) * 40);
			c3->setYPos(360);
			c3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			c4->setXPos((player1.returnCardNumber()) * 40);
			c4->setYPos(360);
			c4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			c5->setXPos((player1.returnCardNumber()) * 40);
			c5->setYPos(360);
			c5->draw(renderer);
			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			c6->setXPos((player1.returnCardNumber()) * 40);
			c6->setYPos(360);
			c6->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			c7->setXPos((player1.returnCardNumber()) * 40);
			c7->setYPos(360);
			c7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			c8->setXPos((player1.returnCardNumber()) * 40);
			c8->setYPos(360);
			c8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			c9->setXPos((player1.returnCardNumber()) * 40);
			c9->setYPos(360);
			c9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			c10->setXPos((player1.returnCardNumber()) * 40);
			c10->setYPos(360);
			c10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			cj->setXPos((player1.returnCardNumber()) * 40);
			cj->setYPos(360);
			cj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			cq->setXPos((player1.returnCardNumber()) * 40);
			cq->setYPos(360);
			cq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			ck->setXPos((player1.returnCardNumber()) * 40);
			ck->setYPos(360);
			ck->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}
	else if (a.suit == "Spades") {
		if (a.face == "Ace") {
			s1->setXPos((player1.returnCardNumber()) * 40);
			s1->setYPos(360);
			s1->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			s2->setXPos((player1.returnCardNumber()) * 40);
			s2->setYPos(360);
			s2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			s3->setXPos((player1.returnCardNumber()) * 40);
			s3->setYPos(360);
			s3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			s4->setXPos((player1.returnCardNumber()) * 40);
			s4->setYPos(360);
			s4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			s5->setXPos((player1.returnCardNumber()) * 40);
			s5->setYPos(360);
			s5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			s6->setXPos((player1.returnCardNumber()) * 40);
			s6->setYPos(360);
			s6->draw(renderer);


			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			s7->setXPos((player1.returnCardNumber()) * 40);
			s7->setYPos(360);
			s7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			s8->setXPos((player1.returnCardNumber()) * 40);
			s8->setYPos(360);
			s8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			s9->setXPos((player1.returnCardNumber()) * 40);
			s9->setYPos(360);
			s9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			s10->setXPos((player1.returnCardNumber()) * 40);
			s10->setYPos(360);
			s10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			sj->setXPos((player1.returnCardNumber()) * 40);
			sj->setYPos(360);
			sj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			sq->setXPos((player1.returnCardNumber()) * 40);
			sq->setYPos(360);
			sq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			sk->setXPos((player1.returnCardNumber()) * 40);
			sk->setYPos(360);
			sk->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}
	else if (a.suit == "Hearts") {
		if (a.face == "Ace") {
			h1->setXPos((player1.returnCardNumber()) * 40);
			h1->setYPos(360);
			h1->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			h2->setXPos((player1.returnCardNumber()) * 40);
			h2->setYPos(360);
			h2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			h3->setXPos((player1.returnCardNumber()) * 40);
			h3->setYPos(360);
			h3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			h4->setXPos((player1.returnCardNumber()) * 40);
			h4->setYPos(360);
			h4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			h5->setXPos((player1.returnCardNumber()) * 40);
			h5->setYPos(360);
			h5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			h6->setXPos((player1.returnCardNumber()) * 40);
			h6->setYPos(360);
			h6->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			h7->setXPos((player1.returnCardNumber()) * 40);
			h7->setYPos(360);
			h7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			h8->setXPos((player1.returnCardNumber()) * 40);
			h8->setYPos(360);
			h8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			h9->setXPos((player1.returnCardNumber()) * 40);
			h9->setYPos(360);
			h9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			h10->setXPos((player1.returnCardNumber()) * 40);
			h10->setYPos(360);
			h10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			hj->setXPos((player1.returnCardNumber()) * 40);
			hj->setYPos(360);
			hj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			hq->setXPos((player1.returnCardNumber()) * 40);
			hq->setYPos(360);
			hq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			hk->setXPos((player1.returnCardNumber()) * 40);
			hk->setYPos(360);
			hk->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}


}

void renderaCards(Card a) {

	Mix_PlayChannel(-1, deal, 0);

	if (a.suit == "Diamonds") {
		if (a.face == "Ace") {
			d1->setXPos((ai1.returnCardNumber()) * 40);
			d1->setYPos(110);

			d1->draw(renderer);
			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			d2->setXPos((ai1.returnCardNumber()) * 40);
			d2->setYPos(110);
			d2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			d3->setXPos((ai1.returnCardNumber()) * 40);
			d3->setYPos(110);
			d3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			d4->setXPos((ai1.returnCardNumber()) * 40);
			d4->setYPos(110);
			d4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			d5->setXPos((ai1.returnCardNumber()) * 40);
			d5->setYPos(110);
			d5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			d6->setXPos((ai1.returnCardNumber()) * 40);
			d6->setYPos(110);
			d6->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			d7->setXPos((ai1.returnCardNumber()) * 40);
			d7->setYPos(110);
			d7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			d8->setXPos((ai1.returnCardNumber()) * 40);
			d8->setYPos(110);
			d8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			d9->setXPos((ai1.returnCardNumber()) * 40);
			d9->setYPos(110);
			d9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			d10->setXPos((ai1.returnCardNumber()) * 40);
			d10->setYPos(110);
			d10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			dj->setXPos((ai1.returnCardNumber()) * 40);
			dj->setYPos(110);
			dj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			dq->setXPos((ai1.returnCardNumber()) * 40);
			dq->setYPos(110);
			dq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			dk->setXPos((ai1.returnCardNumber()) * 40);
			dk->setYPos(110);
			dk->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}
	else if (a.suit == "Clubs") {
		if (a.face == "Ace") {
			c1->setXPos((ai1.returnCardNumber()) * 40);
			c1->setYPos(110);
			c1->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			c2->setXPos((ai1.returnCardNumber()) * 40);
			c2->setYPos(110);
			c2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			c3->setXPos((ai1.returnCardNumber()) * 40);
			c3->setYPos(110);
			c3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			c4->setXPos((ai1.returnCardNumber()) * 40);
			c4->setYPos(110);
			c4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			c5->setXPos((ai1.returnCardNumber()) * 40);
			c5->setYPos(110);
			c5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			c6->setXPos((ai1.returnCardNumber()) * 40);
			c6->setYPos(110);
			c6->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			c7->setXPos((ai1.returnCardNumber()) * 40);
			c7->setYPos(110);
			c7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			c8->setXPos((ai1.returnCardNumber()) * 40);
			c8->setYPos(110);
			c8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			c9->setXPos((ai1.returnCardNumber()) * 40);
			c9->setYPos(110);
			c9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			c10->setXPos((ai1.returnCardNumber()) * 40);
			c10->setYPos(110);
			c10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			cj->setXPos((ai1.returnCardNumber()) * 40);
			cj->setYPos(110);
			cj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			cq->setXPos((ai1.returnCardNumber()) * 40);
			cq->setYPos(110);
			cq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			ck->setXPos((ai1.returnCardNumber()) * 40);
			ck->setYPos(110);
			ck->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}
	else if (a.suit == "Spades") {
		if (a.face == "Ace") {
			s1->setXPos((ai1.returnCardNumber()) * 40);
			s1->setYPos(110);
			s1->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			s2->setXPos((ai1.returnCardNumber()) * 40);
			s2->setYPos(110);
			s2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			s3->setXPos((ai1.returnCardNumber()) * 40);
			s3->setYPos(110);
			s3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			s4->setXPos((ai1.returnCardNumber()) * 40);
			s4->setYPos(110);
			s4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			s5->setXPos((ai1.returnCardNumber()) * 40);
			s5->setYPos(110);
			s5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			s6->setXPos((ai1.returnCardNumber()) * 40);
			s6->setYPos(110);
			s6->draw(renderer);


			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			s7->setXPos((ai1.returnCardNumber()) * 40);
			s7->setYPos(110);
			s7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			s8->setXPos((ai1.returnCardNumber()) * 40);
			s8->setYPos(110);
			s8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			s9->setXPos((ai1.returnCardNumber()) * 40);
			s9->setYPos(110);
			s9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			s10->setXPos((ai1.returnCardNumber()) * 40);
			s10->setYPos(110);
			s10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			sj->setXPos((ai1.returnCardNumber()) * 40);
			sj->setYPos(110);
			sj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			sq->setXPos((ai1.returnCardNumber()) * 40);
			sq->setYPos(110);
			sq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			sk->setXPos((ai1.returnCardNumber()) * 40);
			sk->setYPos(110);
			sk->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}
	else if (a.suit == "Hearts") {
		if (a.face == "Ace") {
			h1->setXPos((ai1.returnCardNumber()) * 40);
			h1->setYPos(110);
			h1->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			h2->setXPos((ai1.returnCardNumber()) * 40);
			h2->setYPos(110);
			h2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			h3->setXPos((ai1.returnCardNumber()) * 40);
			h3->setYPos(110);
			h3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			h4->setXPos((ai1.returnCardNumber()) * 40);
			h4->setYPos(110);
			h4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			h5->setXPos((ai1.returnCardNumber()) * 40);
			h5->setYPos(110);
			h5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			h6->setXPos((ai1.returnCardNumber()) * 40);
			h6->setYPos(110);
			h6->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			h7->setXPos((ai1.returnCardNumber()) * 40);
			h7->setYPos(110);
			h7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			h8->setXPos((ai1.returnCardNumber()) * 40);
			h8->setYPos(110);
			h8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			h9->setXPos((ai1.returnCardNumber()) * 40);
			h9->setYPos(110);
			h9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			h10->setXPos((ai1.returnCardNumber()) * 40);
			h10->setYPos(110);
			h10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			hj->setXPos((ai1.returnCardNumber()) * 40);
			hj->setYPos(110);
			hj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			hq->setXPos((ai1.returnCardNumber()) * 40);
			hq->setYPos(110);
			hq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			hk->setXPos((ai1.returnCardNumber()) * 40);
			hk->setYPos(110);
			hk->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}

}

void cleanUp() {
	delete background;
	delete cardBack;
	delete hole;
	delete h1;
	delete h2;
	delete h3;
	delete h4;
	delete h5;
	delete h6;
	delete h7;
	delete h8;
	delete h9;
	delete h10;
	delete hj;
	delete hq;
	delete hk;
	delete s1;
	delete s2;
	delete s3;
	delete s4;
	delete s5;
	delete s6;
	delete s7;
	delete s8;
	delete s9;
	delete s10;
	delete sj;
	delete sq;
	delete sk;
	delete c1;
	delete c2;
	delete c3;
	delete c4;
	delete c5;
	delete c6;
	delete c7;
	delete c8;
	delete c9;
	delete c10;
	delete cj;
	delete cq;
	delete ck;
	delete d1;
	delete d2;
	delete d3;
	delete d4;
	delete d5;
	delete d6;
	delete d7;
	delete d8;
	delete d9;
	delete d10;
	delete dj;
	delete dq;
	delete dk;
	delete chipFifty;
	delete chipFive;
	delete chipHundred;
	delete chipOne;
	delete title;
	delete norm;
	delete stern;
	delete mil;
	delete hap;





	/** Stop and free music. Free all sound effects */
	Mix_HaltMusic();
	Mix_FreeMusic(music);
	Mix_FreeChunk(youlose);
	Mix_FreeChunk(deal);
	Mix_FreeChunk(deck);
	Mix_FreeChunk(splitS);
	Mix_FreeChunk(doubledown);
	Mix_FreeChunk(blackjack);
	Mix_FreeChunk(hit);
	Mix_FreeChunk(leave);



	/** Free text surfaces */
	SDL_FreeSurface(text);
	SDL_DestroyTexture(scoreTexture);
	TTF_CloseFont(font);
}



void renderholeCard(Card a) {

	Mix_PlayChannel(-1, deal, 0);

	if (a.suit == "Diamonds") {
		if (a.face == "Ace") {
			d1->setXPos(80);
			d1->setYPos(110);

			d1->draw(renderer);
			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			d2->setXPos(80);
			d2->setYPos(110);
			d2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			d3->setXPos(80);
			d3->setYPos(110);
			d3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			d4->setXPos(80);
			d4->setYPos(110);
			d4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			d5->setXPos(80);
			d5->setYPos(110);
			d5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			d6->setXPos(80);
			d6->setYPos(110);
			d6->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			d7->setXPos(80);
			d7->setYPos(110);
			d7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			d8->setXPos(80);
			d8->setYPos(110);
			d8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			d9->setXPos(80);
			d9->setYPos(110);
			d9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			d10->setXPos(80);
			d10->setYPos(110);
			d10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			dj->setXPos(80);
			dj->setYPos(110);
			dj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			dq->setXPos(80);
			dq->setYPos(110);
			dq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			dk->setXPos(80);
			dk->setYPos(110);
			dk->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}
	else if (a.suit == "Clubs") {
		if (a.face == "Ace") {
			c1->setXPos(80);
			c1->setYPos(110);
			c1->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			c2->setXPos(80);
			c2->setYPos(110);
			c2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			c3->setXPos(80);
			c3->setYPos(110);
			c3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			c4->setXPos(80);
			c4->setYPos(110);
			c4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			c5->setXPos(80);
			c5->setYPos(110);
			c5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			c6->setXPos(80);
			c6->setYPos(110);
			c6->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			c7->setXPos(80);
			c7->setYPos(110);
			c7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			c8->setXPos(80);
			c8->setYPos(110);
			c8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			c9->setXPos(80);
			c9->setYPos(110);
			c9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			c10->setXPos(80);
			c10->setYPos(110);
			c10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			cj->setXPos(80);
			cj->setYPos(110);
			cj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			cq->setXPos(80);
			cq->setYPos(110);
			cq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			ck->setXPos(80);
			ck->setYPos(110);
			ck->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}
	else if (a.suit == "Spades") {
		if (a.face == "Ace") {
			s1->setXPos(80);
			s1->setYPos(110);
			s1->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			s2->setXPos(80);
			s2->setYPos(110);
			s2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			s3->setXPos(80);
			s3->setYPos(110);
			s3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			s4->setXPos(80);
			s4->setYPos(110);
			s4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			s5->setXPos(80);
			s5->setYPos(110);
			s5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			s6->setXPos(80);
			s6->setYPos(110);
			s6->draw(renderer);


			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			s7->setXPos(80);
			s7->setYPos(110);
			s7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			s8->setXPos(80);
			s8->setYPos(110);
			s8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			s9->setXPos(80);
			s9->setYPos(110);
			s9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			s10->setXPos(80);
			s10->setYPos(110);
			s10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			sj->setXPos(80);
			sj->setYPos(110);
			sj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			sq->setXPos(80);
			sq->setYPos(110);
			sq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			sk->setXPos(80);
			sk->setYPos(110);
			sk->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}
	else if (a.suit == "Hearts") {
		if (a.face == "Ace") {
			h1->setXPos(80);
			h1->setYPos(110);
			h1->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Two") {
			h2->setXPos(80);
			h2->setYPos(110);
			h2->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Three") {
			h3->setXPos(80);
			h3->setYPos(110);
			h3->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Four") {
			h4->setXPos(80);
			h4->setYPos(110);
			h4->draw(renderer);

			SDL_RenderPresent(renderer);

		}
		else if (a.face == "Five") {
			h5->setXPos(80);
			h5->setYPos(110);
			h5->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Six") {
			h6->setXPos(80);
			h6->setYPos(110);
			h6->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Seven") {
			h7->setXPos(80);
			h7->setYPos(110);
			h7->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Eight") {
			h8->setXPos(80);
			h8->setYPos(110);
			h8->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Nine") {
			h9->setXPos(80);
			h9->setYPos(110);
			h9->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Ten") {
			h10->setXPos(80);
			h10->setYPos(110);
			h10->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Jack") {
			hj->setXPos(80);
			hj->setYPos(110);
			hj->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "Queen") {
			hq->setXPos(80);
			hq->setYPos(110);
			hq->draw(renderer);

			SDL_RenderPresent(renderer);
		}
		else if (a.face == "King") {
			hk->setXPos(80);
			hk->setYPos(110);
			hk->draw(renderer);

			SDL_RenderPresent(renderer);
		}

	}

}