#include <iostream>
#include "src/network/network.hpp"


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

}

bool make_move(int row, int col, char symbol) 
{
	// Pseudo-code
	/*  get player input
		check wether player is x or o
		fill corresponding square in renderer.cpp with the players symbol

	*/

}

bool check_winner(char symbol)
{

}

bool is_draw()
{

}


void make_move(row, col, id)
{

}



void gameloop()
{

}