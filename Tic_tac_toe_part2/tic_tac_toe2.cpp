/* "I pledge my honor that I have abided by the Stevens Honor System." 
Nesar Ahmed
Date: 27 February 2016 */

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdexcept>
#include <fstream>
#include "windows.h"
using namespace std;

class TicTacToe {
private:

	
	int player_number = 0; //number of players
	char player_sign = 0;
	string players = "XOABCDEFGHIJKLMNPQRSTUVWYZ";
	int win_sequence; //sequence needed to win
	int board_size = 2; 
	char sign[50];
	vector<vector<char>> vect;
	int xinput, yinput; //get user xinput and yinput
	char win_; 

public:
	
	string resume_gameChoice = ""; //user's choice for start a new game or resume last game
	TicTacToe();
	void make_board(int board_size); //make board according to size
	void save_file(char sign, int xinput, int yinput); //save user sign and couple of position(x,y) to file state_saved.txt
	void user_options(ofstream& fileout); //row and column number or quit or quit and save
	void setup_state(); //read setup and state from state_saved.txt
	void game_setup(); //player # and sign for each 
	bool win_chances(); //check for winning chances
	bool result_even(); //even result
	bool empty(int i, int j);
	bool search_winner();
	void print_result();
	void time_delay(long long use_time);
	void save_exit();
	bool state_saved(); //check if first time playing this game by checking if the state_saved.txt is null
	bool resume_choice(string resume_gameChoice); //ask if user wants to start new game or resume previous state
	void new_game();//start a new game
	void resumeGame(); //resume last game

};

void main() {
	TicTacToe Test;
	//state_saved is the name of the saved state of game
	if (Test.state_saved() == 0) {//if new game, the file should be 0 byte
		Test.new_game();
	}
	else {//ask if the user wants to start a new game or resume last game.
		cout << "Do you want to load/resume last game?[yes for resume, no for restart]";
		cin >> Test.resume_gameChoice;
		if (Test.resume_choice(Test.resume_gameChoice) == 0) {//start new game
			Test.new_game();
		}
		else if (Test.resume_choice(Test.resume_gameChoice) == 1) {//resume last game
			Test.resumeGame();
		}
	}
}


TicTacToe::TicTacToe() {
}

bool TicTacToe::state_saved() {
	ifstream inside("state_saved.txt");
	string str;
	inside >> str;
	inside.close();
	if (str.empty()) {//str.empty() == 1
		if (str.empty()) {
			return 0;
		}
	}
	else {
		return 1;
	}
}
bool TicTacToe::resume_choice(string resume_gameChoice) {
	if (resume_gameChoice == "no" || resume_gameChoice == "n") {
		//if no, start new game
		return 0;
	}
	else if (resume_gameChoice == "yes" || resume_gameChoice == "y") {
		return 1;
	}
	return 0;
}

void TicTacToe::new_game() {

	game_setup();
	//check winning chances
	while (win_chances() == 0) {//0 means no one was able to win
		cout << "No one will win, please set up the game again" << endl;
		game_setup();
	}

	make_board(board_size);
	ofstream fileout2("state_saved.txt");
	do {
		user_options(fileout2);
	} while (1);
	fileout2.close();
	save_exit();
}

void TicTacToe::resumeGame() {
	setup_state();
	make_board(board_size);
}

void TicTacToe::game_setup() {
	cout << "Please input the number of players:";
	cin >> player_number;
	while (cin.fail() || player_number<2 || player_number > 26) {
		cout << "Input should be between 2 and 26, please input the number of players: " << endl;
		cin.clear();
		cin.sync();
		cin >> player_number;
	}
	for (int i = 0; i < player_number; i++) {
		sign[i] = players.at(i);
	}
	cout << "Please input the win sequence: ";
	cin >> win_sequence;
	while (cin.fail()) {
		cout << "Please try again. Input winning sequence number: " << endl;
		cin.clear();
		cin.sync();
		cin >> win_sequence;
	}
	cout << "How large is the board: ";
	cin >> board_size;
	while (cin.fail()) {
		cout << "Please input board size: " << endl;
		cin.clear();
		cin.sync();
		cin >> win_sequence;
	}
	ofstream fileout1("savedSetup.txt");
	fileout1 << player_number << " " << win_sequence << " "
		<< board_size << " ";
	fileout1.close();
	vect.resize(board_size);
	for (int i = 0; i < vect.size(); i++) {
		vect[i].resize(board_size);
	}
	for (int i = 0; i < vect.size(); i++) {
		for (int j = 0; j < vect.size(); j++) {
			vect[i][j] = '   ';
		}
	}
}

void TicTacToe::make_board(int board_size) {
	
	cout << "  1";
	for (int i = 2; i <= board_size; i++) {
		cout << "   " << i;
	}
	cout << endl;

	for (int i = 1; i <= board_size; i++) {
		cout << i;
		for (int j = 1; j <= board_size; j++) {
			cout << " " << vect[i - 1][j - 1] << " ";
			if (j != board_size) {
				cout << "|";
			}
		}
		cout << endl;
		if (i != board_size) {
			cout << " ";
			for (int j = 0; j < board_size - 1; j++) {
				cout << "---+";
			}
			cout << "---" << endl;
		}
	}
}


void TicTacToe::save_file(char sign, int xinput, int yinput) {
}

void TicTacToe::setup_state() {
	ifstream fileinside("savedSetup.txt");
	ifstream filein2("state_saved.txt");

	if (fileinside.good()) {
		fileinside >> player_number >> win_sequence >> board_size;
	}
	else {
		cout << "File not found." << endl;
	}
	for (int i = 0; i < player_number; i++) {
		sign[i] = players.at(i);
	}
	vect.resize(board_size + 1);
	for (int i = 0; i < vect.size(); i++) {
		vect[i].resize(board_size + 1);
	}
	for (int i = 0; i < vect.size(); i++) {
		for (int j = 0; j < vect.size(); j++) {
			vect[i][j] = '   ';
		}
	}
	int k = 0, s = 0;
	char sign = 0;
	long time_span = 0.0;

	while (filein2 >> k >> s >> sign >> time_span) {
		xinput = k + 1;
		yinput = s + 1;
		player_sign = sign;
		if (search_winner() == true) {
			print_result();
			cout << "restart game:" << endl;
		}
		vect[k][s] = sign;
		time_delay(time_span);
		make_board(board_size);
	}
	if (search_winner() == true) {
		game_setup();
	}

	while (win_chances() == false) {
		cout << "No one won the game, restart game:" << endl;
		game_setup();
	}

	cout << "Continue last game:" << endl;
	
	ofstream fileout2("state_saved.txt");
	do {
		user_options(fileout2);
	} while (xinput != 'q' || xinput != 'qw');
	fileout2.close();
	save_exit();
}

void TicTacToe::user_options(ofstream& fileout2) {
	
	for (int i = 0; i < player_number; i++) {
		cout << "Player " << sign[i] << ": It is your turn, please type your next move (e.g. 1 1): type -1 to exit:" << endl;
		//get user input
		int insert;
		time_t begin = clock();
		cin >> insert;
		if (insert != -1) {
			while (insert > board_size || insert < 1) {
				cout << "Invalid row. Please input again: " << endl;
				cin >> insert;
			}
		}
		if (1 <= insert && insert <= board_size)
		{
			xinput = insert;
			cin >> yinput;
		
			while (cin.fail() || yinput > board_size || yinput < 1) {
				cout << "Invalid column input. Please input again: " << endl;
				cin.clear();
				cin.sync();
		
				cin >> yinput;
			}
			while (empty(xinput - 1, yinput - 1) == false) {
				cin >> xinput >> yinput;
			}
			time_t end = clock();
			long time_span = end - begin;
			
			vect[xinput - 1][yinput - 1] = sign[i];
			player_sign = sign[i];
			//re-make the board
			system("cls");
			make_board(board_size);
			fileout2 << xinput - 1 << " " << yinput - 1 << " " << player_sign << " " << time_span << "\n";
		}
		else if (insert == -1) {
			exit(1);
		}


		if (search_winner() == true) {
			print_result();
			fileout2.close();
			exit(1);
		}
		else if (win_chances() == false) {
			print_result();
			fileout2.close();
			exit(1);
		}
	}
}

void TicTacToe::time_delay(long long use_time)
{

	long long time = clock();
	clock_t start_time = clock();
	clock_t end_time = use_time + start_time;
	while (clock() <= end_time);
}

void TicTacToe::save_exit() {

}

bool TicTacToe::empty(int i, int j) {
	if (vect[i][j] == ' ') {
		return true;
	}
	else {
		cout << "This spot is taken, please try again." << endl;
		return false;
	}
}

bool TicTacToe::win_chances() {
	if (player_number > 26 || player_number < 2) {
		return 0;
	}
	if (board_size < 0) {
		return 0;
	}
	if (board_size == 1) {
		return 0;
	}
	if (board_size > 1 && board_size * board_size < player_number) {
		return 0;
	}
	if (win_sequence < 0) {
		return 0;
	}
	if (win_sequence == 1) {
		return 0;
	}
	if (win_sequence > 1 && win_sequence > board_size) {
		return 0;
	}

	if (win_sequence > 1 && win_sequence * player_number >= board_size * board_size) {
		return 0;
	}

	if (result_even() == false) {
		return false;
	}

	return true;
}

bool TicTacToe::search_winner() {
	int count = 1;
	for (int i = 1; i < win_sequence; i++) {
		if (yinput - i >= 1) {
			if (vect[xinput - 1][yinput - 1 - i] == player_sign) {
				count++;
			}
			else break;
		}
		else break;
	}
	for (int i = 1; i < win_sequence; i++) {
		if (yinput + i <= board_size) {
			if (vect[xinput - 1][yinput - 1 + i] == player_sign) {
				count++;
			}
			else break;
		}
		else break;
	}
	if (count >= win_sequence) { return true; }
	else { count = 1; }
	for (int i = 1; i < win_sequence; i++) {
		if (xinput + i <= board_size) {
			if (vect[xinput - 1 + i][yinput - 1] == player_sign) {
				count++;
			}
			else break;
		}
		else break;
	}
	for (int i = 1; i < win_sequence; i++) {
		if (xinput - i >= 1) {
			if (vect[xinput - 1 - i][yinput - 1] == player_sign) {
				count++;
			}
			else break;
		}
		else break;
	}
	if (count >= win_sequence) { return true; }
	else { count = 1; }
	for (int i = 1; i < win_sequence; i++) {
		if (xinput + i <= board_size && yinput + i <= board_size) {
			if (vect[xinput - 1 + i][yinput - 1 + i] == player_sign) {
				count++;
			}
			else break;
		}
		else break;
	}
	for (int i = 1; i < win_sequence; i++) {
		if (xinput - i >= 1 && yinput - i >= 1) {
			if (vect[xinput - 1 - i][yinput - 1 - i] == player_sign) {
				count++;
			}
			else break;
		}
		else break;
	}
	if (count >= win_sequence) { return true; }
	else { count = 1; }
	for (int i = 1; i < win_sequence; i++) {
		if (xinput + i <= board_size && yinput - i >= 1) {
			if (vect[xinput - 1 + i][yinput - 1 - i] == player_sign) {
				count++;
			}
			else break;
		}
		else break;
	}
	for (int i = 1; i < win_sequence; i++) {
		if (xinput - i >= 1 && yinput + i < board_size) {
			if (vect[xinput - 1 - i][yinput - 1 + i] == player_sign) {
				count++;
			}
			else break;
		}
		else break;
	}
	if (count >= win_sequence) { return true; }
	return false;
}

bool TicTacToe::result_even() {
	int count = 0;
	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			if (vect[i][j] != ' ') {
				count++;
			}
		}
	}
	if (count == board_size * board_size) {
		return false;
	}
	else { return true; }
}

void TicTacToe::print_result() {
	if (search_winner() == true) {
		cout << "Congratulation, Player " << player_sign << "! You win!" << endl;
	}
	else if (win_chances() == false) {
		cout << "Game Over! The game is even." << endl;
	}
}



/*Extend your basic tic-tac-toe game for the console. The game should now work as follows:
 
Ask if the player would like to resume a saved game. If yes, load game state from a text or binary file (your choice of file format).
1. For a new game, ask how many players are playing.
2. For a new game, ask how large the board should be.
3. For a new game, ask what the win sequence count should be (i.e. 3 in a row).
4. For a new game, check to ensure that winning is possible given the criteria specified, and display an error if not.
 
5. Output a board in the following general format: (same format as last time)
6. Ask the user for a row and column number, or if they would like to save and exit. If they choose save/exit, do so, otherwise continue.
7. Put the appropriate symbol for that player (X or O) in the specified spot. Players should be given the following symbols, in order:
XOABCDEFGHIJKLMNPQRSTUVWYZ

8. Repeat for the next player until someone has won the game.
9. If someone has won, announce which player won and exit. If the game has tied, announce that and exit.

The conditions for winning this new tic-tac-toe game are now as follows:

* n in a row/column/diagnoal, where n is the win sequence count

Extra Credit Opportunities:

1. Allow winning by a square whose side dimensions are n - 1, where n is the win sequence count. For example, the following would be a win for X in a 3x3, n = 3 game:
You may decide for yourself whether squares may be hollow or must be filled in, as long as you clearly tell the user the rules.



2. Create a "replay" save. As the game is played, save each move to a file. 
When loading the saved game, actually place each player's symbol one 
at a time with an appropriate delay. (Worth 10 points, or 20 if you 
measure and save the time passed between moves and actually replay the game 
at the same speed that it was originally played.) 
Implementation of this extra credit opportunity requires learning 
and understanding the C++ time functions, which are not covered in this 
class. It is only recommended to be approached by advanced students.


 */