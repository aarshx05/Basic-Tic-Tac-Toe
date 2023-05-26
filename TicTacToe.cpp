#include<bits/stdc++.h> 
using namespace std;

char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
char currentPlayer = 'X';

void displayboard()
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}
void displayboard(char board[][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}
bool boardfull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool gamedone(char board[][3],char player)
{
    
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

   
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }

 
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
        return true;

    return false;
}

void usermove()
{
    int row, col;
    cout << "Player " << currentPlayer << ",Enter your move (row [0-2] and column [0-2]): ";
    cin >> row >> col;


    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
    {
        cout << "Invalid move! Try again." << endl;
        usermove();
        return;
    }

    board[row][col] = currentPlayer;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void computerMove(char board[][3], char computer) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = computer;
}

int main()
{
    cout << "Welcome to Tic Tac Toe!" << endl;
  l1:  cout<<"\nPvP(1) OR PvComputer(2):";
    int sw;
    cin>>sw;

    if(sw==1)
    {
    while (true)
    {
        displayboard();
        usermove();

        if (gamedone(board,currentPlayer))
        {
            displayboard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (boardfull())
        {
            displayboard();
            cout << "It's a tie!" << endl;
            break;
        }

        switchPlayer();
    }
}
else if(sw==2)
{  
      char board[3][3];
    char player, computer;

    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }

    
    srand(time(0));
    int randomNum = rand() % 2;
    if (randomNum == 0) {
        player = 'X';
        computer = 'O';
         cout << "You are X. Computer is O." << std::endl;
    } else {
        player = 'O';
        computer = 'X';
         cout << "You are O. Computer is X." << std::endl;
    }

  
    while (true) {
        displayboard(board);

        
        int row, col;
         cout << "Enter your move (row [0-2] and column [0-2]): ";
         cin >> row >> col;
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
             cout << "Invalid move. Try again." << std::endl;
            continue;
        }
        board[row][col] = player;

        
        if (gamedone(board,player)) {
            displayboard(board);
             cout << "Congratulations! You win!" << std::endl;
            break;
        }

       
        bool boardfull = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    boardfull = false;
                    break;
                }
            }
            if (!boardfull)
                break;
        }
        if (boardfull) {
            displayboard(board);
             cout << "It's a draw!" << std::endl;
            break;
        }

        
        computerMove(board, computer);

    
        if (gamedone(board,player)) {
            displayboard(board);
              cout << "Computer wins! You lose." << std::endl;
            break;
        }
    }

    return 0;
   }
   cout<<"\n\nWant To Play Again?--Yes(1)--No(0)--:";
   cin>>sw;
   if(sw==1)
   {
   	goto l1;
   }
   else
   {
   	cout<<"\nThank You";
   }
}

