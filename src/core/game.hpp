#ifndef	CORE_GAME_HPP_
#define CORE_GAME_HPP_

#include "board.hpp"
#include "player.hpp"
#include "move.hpp"

namespace core {
	enum class GameState {kOngoing, kWin, kDraw};

	class Game {
		public:
			Game(const Player& player1, const Player& player2);

			GameState GetState() const;
			const Player& GetCurrentPlayer() const;
			bool MakeMove(const Move& move);
			void Reset();

			const Board& board() const;

		private:
			Board board_;
			Player player1_;
			Player player2_;
			Player current_player_;
			GameState state_;

			void SwitchTurn();
			void UpdateState(char symbol);
	};
}

#endif // CORE_GAME_HPP_