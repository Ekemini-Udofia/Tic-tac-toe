#ifndef CORE_PLAYER_HPP_
#define CORE_PLAYER_HPP_

#include <string>

namespace core {

	class Player {
		public:
			Player(std::string name, char symbol);

			const std::string& name() const;
			char symbol() const;

		private:
			std::string name_;
			char symbol_;
	};
}


#endif // CORE_PLAYER_HPP_