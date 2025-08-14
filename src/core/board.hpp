#ifndef CORE_BOARD_HPP_
#define CORE_BOARD_HPP_

#include <array>

namespace core {

	class Board {
	public:
		Board();
		bool PlaceMove(int row, int col, char symnol);
		bool IsCellEmpty(int row, int col) const;
		bool CheckWin(char symbol) const;
		bool IsFull() const;
		void Reset();

		char GetCell(int row, int col) const;
	private:
		std::array<std::array<char, 3>, 3> grid_;
	};
}

#endif // CORE_BOARD_HPP_