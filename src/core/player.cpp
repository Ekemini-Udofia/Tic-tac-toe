#include <string>
#include "player.hpp"

namespace core {

	Player::Player(std::string name, char symbol) : name_(std::move(name)), symbol_(symbol) {}

	const std::string& Player::name() const {
		return name_;
	}
		
	char Player::symbol() const {
		return symbol_;
	}
} // namespace core


