#include <iostream>
//#include "network/network.hpp"


int row;
int col;
std::string id;


class player {
	public:
		int player_name;
		bool is_online;
		bool players_turn;

		player()
		{
			int player_name = NULL;
			bool is_online = false;
		}

		~player()
		{
			// Close everything
		}

	private:
		std::string player_id;

};


void init_game()
{
	int a;

}

bool make_move(int row, int col, char symbol) 
{
	// Pseudo-code
	/*  get player input
		check wether player is x or o
		fill corresponding square in renderer.cpp with the players symbol

	*/
	return true;
}

bool check_winner(char symbol)
{
	return true;
}

bool is_draw()
{
	return true;
}


void make_move(int row, int col, int id)
{
	int a;

}



void gameloop()
{
	int a;
}