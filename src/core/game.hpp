#pragma once


class player {
public:
	int player_id;
	bool is_online;
	bool players_turn;

	player() {};

	~player() {};

private:
};
void gameloop();