#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int checkWin();
void Boardprint();
void win();
string board = "0123456789";
vector <char> v;
map <int,int> Map;
int f = 0, c = 0, cnt = 0;
//main function 
int main()
{
    system("color 9f");
    bool iswin = false;
    Boardprint();
    while(1)
    {
        int p;
        cout << "   Choice for player " << (c%2)+1 << " -> ";
        cin >> p; c++;
        if (p > 9) 
        {
            cout << "Please inter value less than or equal 9" << endl;
            c--;
        }
        else if (c % 2 == 1 and Map[p] == 0)
        {
            Map[p]++;
            board[p] = 'X';
            v.push_back('x');
            win();
            Boardprint();
            iswin = checkWin();
            if (iswin == 1) 
            {
                if (v.back() == 'x')
                {
                    cout << "Player 1 win the match." << endl;
                }
                else cout << "Player 2 win the match." << endl;
                f = 1;
                break;
            }
        }
        else if (c % 2 == 1 and Map[p] == 1) 
        {
            cout << "Invalid option. Please try again." << endl;
            c--;
        }
        else if (c % 2 == 0 and Map[p] == 0)
        {
            Map[p]++;
            board[p] = 'O';
            v.push_back('o');
            win();
            Boardprint();
            iswin = checkWin();
            if (iswin == 1) 
            {
                if (v.back() == 'x')
                {
                    cout << "Player 1 win the match." << endl;
                }
                else cout << "Player 2 win the match." << endl;
                f = 1;
                break;
            }
        }
        else if (c % 2 == 0 and Map[p] == 1) 
        {
            cout << "Invalid option. Please try again." << endl;
            c--;
        }
        if (v.size() == 9) break;
    }
    if (!f) cout << "Draw the match." << endl;
}
void Boardprint() 
{
	printf("\n\n\t Tic Tac Toe \n\n");
    cout << " X -> for player 1 and O -> for player 2 " << endl;
    printf("---------------------------------------\n");
	printf("             |     |     \n");
	printf("          %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
	printf("        _____|_____|_____\n");
	printf("             |     |     \n");
	printf("          %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
	printf("        _____|_____|_____\n");
	printf("             |     |     \n");
	printf("          %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
	printf("             |     |     \n");
}
int checkWin() 
{
	if(board[1] == board[2] && board[2] == board[3])
		return 1;
	else if (board[4] == board[5] && board[5] == board[6])
		return 1;
	else if(board[7] == board[8] && board[8] == board[9])
		return 1;
	else if(board[1] == board[4] && board[4] == board[7])
		return 1;
	else if(board[2] == board[5] && board[5] == board[8])
		return 1;
	else if(board[3] == board[6] && board[6] == board[9])
		return 1;
	else if(board[1] == board[5] && board[5] == board[9])
		return 1;
	else if(board[3] == board[5] && board[5] == board[7])
		return 1;
	else
		return 0;
}
void win() 
{
    if(board[1] == board[2] && board[2] == board[3]) 
    {
        board[1] = '*'; board[2] = '*'; board[3] = '*';
    }
    if(board[4] == board[5] && board[5] == board[6]) 
    {
        board[4] = '*'; board[5] = '*'; board[6] = '*';
    }
    if(board[7] == board[8] && board[8] == board[9]) 
    {
        board[7] = '*'; board[8] = '*'; board[9] = '*';
    }
    if(board[1] == board[4] && board[4] == board[7]) 
    {
        board[1] = '*'; board[4] = '*'; board[7] = '*';
    }
    if(board[2] == board[5] && board[5] == board[8]) 
    {
        board[2] = '*'; board[5] = '*'; board[8] = '*';
    }
    if(board[3] == board[6] && board[6] == board[9]) 
    {
        board[3] = '*'; board[6] = '*'; board[9] = '*';
    }
    if(board[1] == board[5] && board[5] == board[9]) 
    {
        board[1] = '*'; board[5] = '*'; board[9] = '*';
    }
    if(board[3] == board[5] && board[5] == board[7]) 
    {
        board[3] = '*'; board[5] = '*'; board[7] = '*';
    }
}
