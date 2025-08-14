#include <array>
#include "board.hpp"

namespace core {

	constexpr char kEmptyCell = ' ';

	
	Board::Board() {
		Reset();
	}

	bool Board::PlaceMove(int row, int col, char symbol) {
		if (row < 0 || row >= 3 || col < 0 || col >= 3) {
			return false;
		}
		if (symbol == kEmptyCell) {
			return false;
		}
		if (!IsCellEmpty(row, col)) {
			return false;
		}
		grid_[row][col] = symbol;
		return true;
	}

	bool Board::IsCellEmpty(int row, int col) const {
		if (row < 0 || row >= 3 || col < 0 || col >= 3) {
			return false;
		}

		return grid_[row][col] == kEmptyCell;
	}

	bool Board::CheckWin(char symbol) const {
		// Check Row-wins
		for (int r = 0; r < 3; ++r) {
			if (grid_[r][0] == symbol && grid_[r][1] == symbol && grid_[r][2] == symbol) {
				return true;
			}
		}

		// Check Columns-wins
		for (int c = 0; c < 3; ++c) {
			if (grid_[0][c] == symbol && grid_[1][c] == symbol && grid_[2][c] == symbol) {
				return true;
			}
		}

		// Check thw two Diagonal-wins
		if (grid_[0][0] == symbol && grid_[1][1] == symbol && grid_[2][2] == symbol) {
			return true;
		}
		if (grid_[0][2] == symbol && grid_[1][1] == symbol && grid_[2][0] == symbol) {
			return true;
		}
		
		// If none of the above conditions fail, it means there's no win
		return false;
	}
		
	bool Board::IsFull() const {
		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				if (grid_[r][c] == kEmptyCell) {
					return false;
				}
			}
		}
		return true;
	}
	
	void Board::Reset() {
		for (auto& row : grid_) {
			row.fill(kEmptyCell);
		}
	}

	char Board::GetCell(int row, int col) const {
		if (row < 0 || row >= 3 || col < 0 || col >= 3) return kEmptyCell;
		return grid_[row][col];
	}

} // namespace core