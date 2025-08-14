#include "game.hpp"

namespace core {

	Game::Game(const Player& player1, const Player& player2)
		: board_(),
		player1_(player1),
		player2_(player2),
		current_player_(player1_),
		state_(GameState::kOngoing) {}

	GameState Game::GetState() const {
		return state_;
	}

	const Player& Game::GetCurrentPlayer() const {
		return current_player_;
	}

	bool Game::MakeMove(const Move& move) {
		if (state_ != GameState::kOngoing) {
			return false; // Because the game is not ongoing
		}

		if (move.symbol != current_player_.symbol()) {
			return false; // Move does not belong to the current player
		}

		if (!board_.PlaceMove(move.row, move.col, move.symbol)) {
			return false; // Placing move failed for some reason, maybe the place was occupied
		}

		UpdateState(move.symbol);

		if (state_ == GameState::kOngoing) {
			SwitchTurn();
		}

		return true; // Assuming Everything didn't fail
	}

	void Game::Reset() {
		board_.Reset();
		current_player_ = player1_;
		state_ = GameState::kOngoing;	
	}

	void Game::SwitchTurn() {
		current_player_ = (current_player_.symbol() == player1_.symbol()) ? player2_ : player1_;
 	}

	void Game::UpdateState(char symbol) {
		if (board_.CheckWin(symbol)) {
			state_ = GameState::kWin;
		} else if (board_.IsFull()) {
			state_ = GameState::kDraw;
		} else {
			state_ = GameState::kOngoing;
		}
	}

	const Board& Game::board() const { return board_; }

} // namespace core