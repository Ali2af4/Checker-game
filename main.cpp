#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#define EMPTY 0
#define WHITE 1
#define WHITEKING 2
#define BLACK 3
#define BLACKKING 4

#define PLAYER1 1
#define PLAYER2 2

using namespace std;

int board[8][8];
int whiteCount = 12;
int blackCount = 12;

void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((j % 2 + i % 2) % 2)
            {
                board[i][j] = WHITE;
            }
        }
    }

    for (int i = 5; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!((j % 2 + i + 1 % 2) % 2))
            {
                board[i][j] = BLACK;
            }
        }
    }
}

string visualize(int part)
{
    switch (part)
    {
    case 0:
        return "    ";
        break;
    case 1:
        return " ⚪ ";
        break;
    case 2:
        return " 🫅🏻 ";
        break;
    case 3:
        return " 🔴 ";
        break;
    case 4:
        return " 🫅🏿 ";
        break;
    default:
        return "";
        break;
    }
    return "";
}

int charToInt(char input)
{
    int ret;
    switch (input)
    {
    case 'a':
        ret = 0;
        break;
    case 'b':
        ret = 1;
        break;
    case 'c':
        ret = 2;
        break;
    case 'd':
        ret = 3;
        break;
    case 'e':
        ret = 4;
        break;
    case 'f':
        ret = 5;
        break;
    case 'g':
        ret = 6;
        break;
    case 'h':
        ret = 7;
        break;

    default:
        break;
    }
    return ret;
}

void returnPieceToBoard(int turn)
{
    if (turn == WHITE)
    {
        if (whiteCount < 12)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (board[i][j] == EMPTY)
                    {
                        board[i][j] = WHITE;
                        whiteCount++;
                        return;
                    }
                }
            }
        }
    }
    else
    {
        if (blackCount < 12)
        {
            for (int i = 8; i > 0; i--)
            {
                for (int j = 8; j > 0; j++)
                {
                    if (board[i][j] == EMPTY)
                    {
                        board[i][j] = BLACK;
                        blackCount++;
                        return;
                    }
                }
            }
        }
    }
}

void printBoard()
{
    int rr, cc, pp;
    cout << "  +----+----+----+----+----+----+----+----+" << endl;

    for (rr = 0; rr < 8; ++rr)
    {
        cout << rr + 1 << " |";
        for (cc = 0; cc < 8; ++cc)
        {
            cout << visualize(board[rr][cc]) << "|";
        }
        cout << endl
             << "  +----+----+----+----+----+----+----+----+" << endl;
    }

    cout << "    a    b    c    d    e    f    g    h" << endl;
}

bool areEnemy(int piece1, int piece2)
{
    if (!piece1 || !piece2)
        return false;
    return abs((piece1 - 1) / 2 - (piece2 - 1) / 2) >= 1;
}

bool isEnemyNearby(int x, int y, bool isKing, int turn)
{
    int piece = board[x][y];
    if (!isKing)
    {

        int piece1 = board[x + (1 * int(pow(-1, ((turn - 1) % 2))))][y + 1];
        int piece2 = board[x + (2 * int(pow(-1, ((turn - 1) % 2))))][y + 2];

        if (x + (1 * int(pow(-1, ((turn - 1) % 2)))) + 1 < 8 && y + 1 < 8 && x + (2 * int(pow(-1, ((turn - 1) % 2)))) < 8 && y + 2 < 8 && piece2 == EMPTY && areEnemy(piece, piece1))
            return true;

        piece1 = board[x + (1 * int(pow(-1, ((turn - 1) % 2))))][y - 1];
        piece2 = board[x + (2 * int(pow(-1, ((turn - 1) % 2))))][y - 2];

        if (x + (1 * int(pow(-1, ((turn - 1) % 2)))) + 1 < 8 && y - 1 > 0 && x + (2 * int(pow(-1, ((turn - 1) % 2)))) < 8 && y - 2 >= 0 && piece2 == EMPTY && areEnemy(piece, piece1))
            return true;
    }
    else
    {
        int piece1 = board[x + 1][y + 1];

        if (x + 1 < 8 && y + 1 < 8 && areEnemy(piece, piece1))
            return true;

        piece1 = board[x + 1][y - 1];
        if (x + 1 < 8 && y - 1 >= 0 && areEnemy(piece, piece1))
            return true;

        piece1 = board[x - 1][y - 1];
        if (x - 1 >= 0 && y - 1 >= 0 && areEnemy(piece, piece1))
            return true;

        piece1 = board[x - 1][y + 1];
        if (x - 1 >= 0 && y + 1 < 8 && areEnemy(piece, piece1))
            return true;
    }

    return false;
}

bool canAttack(int turn)
{

    if (turn == WHITE)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j])
                {
                    if (board[i][j] == WHITE)
                    {
                        if (isEnemyNearby(i, j, false, turn))
                        {
                            return true;
                        }
                    }
                    else if (board[i][j] == WHITEKING)
                    {
                        if (isEnemyNearby(i, j, true, turn))
                            return true;
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j])
                {
                    if (board[i][j] == BLACK)
                    {
                        if (isEnemyNearby(i, j, false, turn))
                        {
                            return true;
                        }
                    }
                    else if (board[i][j] == BLACKKING)
                    {
                        if (isEnemyNearby(i, j, true, turn))
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

bool isMoveValid(int x1, int y1, int x2, int y2, bool isEnemyNearby, int turn)
{

    if (isEnemyNearby)
    {
        if (x2 == x1 + 2 * pow(-1, turn - 1) && y2 == y1 + 2)
            return true;
        else if (x2 == x1 + 2 * pow(-1, turn - 1) && y2 == y1 - 2)
            return true;
    }
    else if (!canAttack(turn))
    {
        if (x2 == x1 + 1 * pow(-1, turn - 1) && y2 == y1 + 1)
            return true;
        else if (x2 == x1 + 1 * pow(-1, turn - 1) && y2 == y1 - 1)
            return true;
    }

    return false;
}
bool isMoveValidForKing(int x1, int y1, int x2, int y2, bool isEnemyNearby)
{

    if (isEnemyNearby)
    {
        if (x2 == 2 + x1 && y2 == 2 + y1)
            return true;
        else if (x2 == x1 - 2 && y2 == y1 - 2)
            return true;
        else if (x2 == x1 + 2 && y2 == y1 - 2)
            return true;
        else if (x2 == x1 - 2 && y2 == y1 + 2)
            return true;
    }
    else
    {
        if (x2 == x1 + 1 && y2 == y1 + 1)
            return true;
        else if (x2 == x1 + 1 && y2 == y1 - 1)
            return true;
        else if (x2 == x1 - 1 && y2 == y2 + 1)
            return true;
        else if (x2 == x1 - 1 && y2 == y2 - 1)
            return true;
    }
    return false;
}

void clearScreen()
{
    #if __linux__
        system("clear");
    #else
        system("cls");
    #endif
}

int main()
{
    initializeBoard();
    printBoard();

    int turn = PLAYER1;

    while (true)
    {
        cout << "Player " << turn << " turn, select your piece: " << endl;
        char y1c, y2c;
        int y1, y2, x1, x2;
        cin >> y1c >> x1;
        x1--;
        y1 = charToInt(y1c);

        int piece = board[x1][y1];

        if (!piece)
        {
            cout << "There is no piece here!" << endl;
            continue;
        }

        if (piece <= (turn - 1) * 2 || piece > 2 * turn)
        {
            cout << "This Piece is not yours!" << endl;
            continue;
        }

        cout << "Where do you want to move this piece?" << endl;
        cin >> y2c >> x2;
        y2 = charToInt(y2c);
        x2--;

        bool isKing = !(piece % 2);
        bool enemyNearby = isEnemyNearby(x1, y1, isKing, turn);

        if (!isKing)
        {
            if (!isMoveValid(x1, y1, x2, y2, enemyNearby, turn))
            {
                cout << "Invalid move, try again!" << endl;
                continue;
            }
            else
            {
                if (enemyNearby)
                {
                    board[x2][y2] = piece;
                    board[x1][y1] = EMPTY;
                    board[(x1 + x2) / 2][(y1 + y2) / 2] = EMPTY;
                    if (turn == WHITE)
                    {
                        blackCount--;

                        if (!blackCount)
                        {
                            cout << "GAME OVER!, Player " << turn << " WINS!";
                            break;
                        }
                    }
                    else
                    {

                        whiteCount--;

                        if (!whiteCount)
                        {
                            cout << "GAME OVER!, Player " << turn << " WINS!";
                            break;
                        }
                    }
                    bool ik = false;
                    if (turn == WHITE && x2 == 7 || turn == BLACK && x2 == 0)
                    {
                        returnPieceToBoard(turn);
                        board[x2][y2] = (turn == WHITE ? WHITEKING : BLACKKING);
                        ik = true;
                    }

                    if (isEnemyNearby(x2, y2, ik, turn))
                    {
                        printBoard();
                        continue;
                    }
                }
                else
                {
                    board[x2][y2] = piece;
                    board[x1][y1] = EMPTY;

                    if (turn == WHITE && x2 == 7 || turn == BLACK && x2 == 0)
                    {
                        returnPieceToBoard(turn);
                        board[x2][y2] = (turn == WHITE ? WHITEKING : BLACKKING);
                    }
                }
            }
        }
        else
        {
            if (!isMoveValidForKing(x1, y1, x2, y2, enemyNearby))
            {
                cout << "Invalid move, try again!" << endl;
                continue;
            }
            else
            {
                if (enemyNearby)
                {
                    board[x2][y2] = piece;
                    board[x1][y1] = EMPTY;
                    board[(x2 + x1) / 2][(y2 + y1) / 2] = EMPTY;
                    if (turn == WHITE)
                    {
                        blackCount--;

                        if (!blackCount)
                        {
                            cout << "GAME OVER!, Player " << turn << " WINS!";
                            break;
                        }
                    }
                    else
                    {

                        whiteCount--;

                        if (!whiteCount)
                        {
                            cout << "GAME OVER!, Player " << turn << " WINS!";
                            break;
                        }
                    }
                }
                else
                {
                    board[x2][y2] = piece;
                    board[x1][y1] = EMPTY;
                }
            }
        }

        clearScreen();
        printBoard();
        turn = (turn + 1) % 2;
        if (!turn)
            turn = 2;
    }

    return 0;
}