//#include "network/network.hpp"
#include <iostream>
#include <string>
#include "..//gui//renderer.hpp"


int row;
int col;
std::string id;


class player {
	public:
		int player_id{ 0 };
		bool is_online{ false };
		bool players_turn{ false };

		player(){
			// For now well cout << "Player Created";
			// We'll delete after were done with the console
			// 
			std::cout << "Player Object Created\n";
		}

		~player(){
			// Close everything
			std::cout << "Player Object Deleted\n";
		}

	private:
		//std::string player_id;
};


void init_game(){
	int a;

}

bool make_move(int row, int col, char symbol) {
	// Pseudo-code
	/*  get player input
		check wether player is x or o
		fill corresponding square in renderer.cpp with the players symbol

	*/
	return true;
}

bool check_winner(char symbol){
	return true;
}

bool is_draw(){
	return true;
}


void make_move(int row, int col, int id){
	int a;

}



void gameloop()
{
	init_gui();

	bool game_over = false;
	while (!game_over) {
		//Do some stuff

		//check_for_win();
	}
}

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
//assign each index to a particular space on the board

//Edit this function later to check for input
/*
int check_for_win()
{
	if (square[1] == square[2] && square[2] == square[3]) {
		return 1;
	}
	else if (square[4] == square[5] && square[5] == square[6])
	{
		return 1;
	}
	else if (square[7] == square[8] && square[8] == square[9])
	{
		return 1;
	}
	else if (square[1] == square[4] && square[4] == square[7])
	{
		return 1;
	}
	else if (square[2] == square[5] && square[5] == square[8])
	{
		return 1;
	}
	else if (square[3] == square[6] && square[6] == square[9])
	{
		return 1;
	}
	else if (square[3] == square[5] && square[5] == square[7])
	{
		return 1;
	}
	else if (square[1] == square[5] && square[5] == square[9])
	{
		return 1;
	}
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

*/