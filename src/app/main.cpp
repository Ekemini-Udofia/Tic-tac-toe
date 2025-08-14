#include <iostream>
#include "..//core//game.hpp"
#include "..//core//player.hpp"
#include "..//core//move.hpp"

using core::Game;
using core::GameState;
using core::Move;
using core::Player;

static void PrintBoard(const Game& game) {
	const core::Board& b = game.board();
	std::cout << "   0     1     2\n";
	
	for (int r = 0; r < 3; ++r) {
		std::cout << r << " ";
		for (int c = 0; c < 3; ++c) {
			char cell = b.GetCell(r, c);
			if (cell == ' ') cell = '.';
			std::cout << " " << cell << " ";
			if (c < 2) std::cout << " | ";
		}
		std::cout << "\n";
		if (r < 2) std::cout << " -----+-----+-----\n";
	}

	std::cout << std::endl;
}

int main(void) {
	Player player1("Player1", 'x');
	Player player2("Player2", 'O');
	Game game(player1, player2);

	PrintBoard(game);

	while (game.GetState() == GameState::kOngoing) {

		const Player& current = game.GetCurrentPlayer();
		std::cout << current.name() << " (" << current.symbol() << "), enter a row and column : ";

		int row = -1, col = -1;
		//if (!std::cin >> row >> col) {
			//std::cerr << "\nInput Error! Exiting\n";
			//return 1;
		//}

		std::cin >> row >> col;

		Move move(row, col, current.symbol());


		if (!game.MakeMove(move)) {
			std::cout << "Invalid move. Try Again!\n";
		}

		PrintBoard(game);
	}

	if (game.GetState() == GameState::kWin) {
		std::cout << game.GetCurrentPlayer().name() << " wins!\n";
	}
	else {
		std::cout << "It's a draw!\n";
	}

	return 0;
}