//Header File
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class ticTacToe
{
public:
	void printBoard();
	//Function to display and update the playing space

	void changePlayer();
	//Function to toggle player turns

	void getMove();
	//Function for players to choose a space

	char checkWinner();
	//Function to check the squares for a winner


private:
	char board[3][3] = { {'1','2','3' }, {'4', '5', '6'}, {'7', '8', '9'} };
	int row, column, userChoice;
	char player = 'X';

};

//Implementation File
void ticTacToe::printBoard()
{
	system("cls");

	cout << "Tic-Tac-Toe" << endl;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			cout << board[row][column] << " ";
		}
		cout << endl;
	}
}

void ticTacToe::changePlayer()
{
	if (player == 'X')
	{
		player = 'O';
	}
	else
	{
		player = 'X';
	}
}

void ticTacToe::getMove()
{
    try{
        cout << "Select your square: ";
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            if (board[0][0] == '1')
            {
                board[0][0] = player;
            }
            else
            {
                cout << "That is not a valid move." << endl;
                getMove();
                changePlayer();
            }
            break;
        case 2:
            if (board[0][1] == '2')
            {
                board[0][1] = player;
            }
            else
            {
                cout << "That is not a valid move." << endl;
                getMove();
                changePlayer();
            }
            break;
        case 3:
            if (board[0][2] == '3')
            {
                board[0][2] = player;
            }
            else
            {
                cout << "That is not a valid move." << endl;
                getMove();
                changePlayer();
            }
            break;
        case 4:
            if (board[1][0] == '4')
            {
                board[1][0] = player;
            }
            else
            {
                cout << "That is not a valid move." << endl;
                getMove();
                changePlayer();
            }
            break;
        case 5:
            if (board[1][1] == '5')
            {
                board[1][1] = player;
            }
            else
            {
                cout << "That is not a valid move." << endl;
                getMove();
                changePlayer();
            }
            break;
        case 6:
            if (board[1][2] == '6')
            {
                board[1][2] = player;
            }
            else
            {
                cout << "That is not a valid move." << endl;
                getMove();
                changePlayer();
            }
            break;
        case 7:
            if (board[2][0] == '7')
            {
                board[2][0] = player;
            }
            else
            {
                cout << "That is not a valid move." << endl;
                getMove();
                changePlayer();
            }
            break;
        case 8:
            if (board[2][1] == '8')
            {
                board[2][1] = player;
            }
            else
            {
                cout << "That is not a valid move." << endl;
                getMove();
                changePlayer();
            }
            break;
        case 9:
            if (board[2][2] == '9')
            {
                board[2][2] = player;
            }
            else
            {
                cout << "That is not a valid move." << endl;
                getMove();
                changePlayer();
            }
            break;
        };
        printBoard();
        changePlayer();
    }

}

char ticTacToe::checkWinner()
{
	//Checking the first player rows
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		return 'X';
	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
		return 'X';
	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
		return 'X';
	//Checking the first player columns
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
		return 'X';
	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
		return 'X';
	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
		return 'X';

	//Checking the first player diagonals
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		return 'X';
	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
		return 'X';

	//Checking the second player rows
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		return 'O';
	if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
		return 'O';
	if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
		return 'O';

	//Checking the second player columns
	if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
		return 'O';
	if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
		return 'O';
	if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
		return 'O';

	//Checking the second player diagonals
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		return 'O';
	if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
		return 'O';

	return '*';
}

//Test File
int main()
{
	bool winner = false;
	int turnCounter = 0;
	ticTacToe ticTacToeObject;
	ticTacToeObject.printBoard();

	while(!winner && turnCounter != 9)
	{
		ticTacToeObject.getMove();
		if (ticTacToeObject.checkWinner() == 'X')
		{
			cout << "Player X wins!" << endl;
			winner = true;
		}
		else if (ticTacToeObject.checkWinner() == 'O')
		{
			cout << "Player O wins!" << endl;
			winner = true;
		}
		else if (ticTacToeObject.checkWinner() == '*' && turnCounter == 9)
		{
			cout << "It's a draw!" << endl;
		}

		turnCounter++;
	};

	system("PAUSE");
	return 0;
}
