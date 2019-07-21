/* Guess the Number game


3 gamemodes

1. Player vs. Player (PvP)

	Player 1 will type in a number between 1 and 100, Player 2 will guess Player 1's number
	Player 2 has 10 guesses

2. Player vs. Computer (PvC)

	Computer will randomly select a number, Player will guess the Computer's number

3. Computer vs. Computer (CvC)

	Computer 1 will randomly select a number, Computer 2 will guess the Computer 1's number



Gamemode 1 -- PvP

	scanf for Player 1 number
	hide the number
	prompt Player 2 for guesses (10 guesses)

Gamemode 2 -- PvC

	Computer uses random number generator between 1 and 100 and select the random number
	prompt Player for guesses (10 guesses)

Gamemode 3 -- CvC

	Computer 1 uses random number generator between 1 and 100 and select the random number
	Computer 2 also uses a random generator between 1 and 100 and guesses the right number
	For this gamemode, Computer 2 will have unlimited guesses, Player can watch how many guesses
	it took for Computer 2 to guess Computer 1's number

Win condition -- correctGuesses

	Player / Computer guesses the correct number

Lose condition -- wrongGuesses

	Player guesses the incorrect number

Option to play game again -> use while loop or something


*/