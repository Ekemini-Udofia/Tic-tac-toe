#ifndef CORE_MOVE_HPP_
#define CORE_MOVE_HPP_

namespace core {

	struct Move {
		int row;
		int col;
		char symbol;

		Move(int r, int c, char s) : row(r), col(c), symbol(s) {}
	};
}

#endif // CORE_MOVE_HPP_