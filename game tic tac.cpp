#include <iostream>
using namespace std;


void displayBoard(char board[3][3])
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---" << endl;
    }
    cout << "\n";
}


bool checkWin(char board[3][3], char player)
{
    
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }

    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}


bool checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    return true;
}


void playGame()
{
    char board[3][3];
    int num = 1;

    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++ + '0';

    char player = 'X';
    int choice;

    while (true)
    {
        displayBoard(board);

        cout << "Player " << player << ", choose position (1-9): ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "? Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = player;

        
        if (checkWin(board, player))
        {
            displayBoard(board);
            cout << "?? Player " << player << " WINS!\n";
            break;
        }

        
        if (checkDraw(board))
        {
            displayBoard(board);
            cout << "?? It's a DRAW!\n";
            break;
        }

        
        player = (player == 'X') ? 'O' : 'X';
    }
}


int main()
{
    int choice;

    do
    {
        cout << "\n===== TIC TAC TOE MENU =====\n";
        cout << "1. Play Game\n";
        cout << "2. Instructions\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            playGame();
            break;

        case 2:
            cout << "\n?? Instructions:\n";
            cout << "- Choose numbers from 1 to 9\n";
            cout << "- Player X goes first\n";
            cout << "- First to align 3 wins\n";
            break;

        case 3:
            cout << "?? Exiting game...\n";
            break;

        default:
            cout << "? Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}

