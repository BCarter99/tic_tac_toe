#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
bool tie = false;
string p1, p2;

void printBoard()
{
    cout << "    |     |    \n";
    cout << "  " << space[0][0] << " |  " << space[0][1] << "  | " << space[0][2] << "  \n";
    cout << "____|_____|____\n";
    cout << "    |     |    \n";
    cout << "  " << space[1][0] << " |  " << space[1][1] << "  | " << space[1][2] << "  \n";
    cout << "____|_____|____\n";
    cout << "    |     |    \n";
    cout << "  " << space[2][0] << " |  " << space[2][1] << "  | " << space[2][2] << "  \n";
    cout << "    |     |    \n";
}

void positions()
{
    int digit;

    if (token == 'x')
    {
        cout << p1 << " Enter: ";
        cin >> digit;
    }

    if (token == '0')
    {
        cout << p2 << " Enter: ";
        cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        column = 0;
    }

    if (digit == 2)
    {
        row = 0;
        column = 1;
    }

    if (digit == 3)
    {
        row = 0;
        column = 2;
    }

    if (digit == 4)
    {
        row = 1;
        column = 0;
    }

    if (digit == 5)
    {
        row = 1;
        column = 1;
    }

    if (digit == 6)
    {
        row = 1;
        column = 2;
    }

    if (digit == 7)
    {
        row = 2;
        column = 0;
    }

    if (digit == 8)
    {
        row = 2;
        column = 1;
    }

    if (digit == 9)
    {
        row = 2;
        column = 2;
    }

    else if (digit < 1 || digit > 9)
    {
        cout << "Invalid entry" << endl;
    }

    if (token == 'x' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space[row][column] = 'x';
        token = '0';
    }

    else if (token == '0' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space[row][column] = '0';
        token = 'x';
    }

    else
    {
        cout << "Not an empty space" << endl;
        positions();
    }
    printBoard();
}

bool checkIfWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
        {
            return true;
        }
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    tie = true;
    return true;
}

int main()
{
    cout << "Enter player 1 name: \n";
    cin >> p1;

    cout << "Enter player 2 name: \n";
    cin >> p2;

    cout << p1 << " will play first \n";
    cout << p2 << " will play second \n";

    while (!checkIfWin())
    {
        printBoard();
        positions();
        checkIfWin();
    }

    if (token == 'x' && tie == false)
    {
        cout << p2 << " WINS" << endl;
    }

    else if (token == '0' && tie == false)
    {
        cout << p1 << " WINS" << endl;
    }

    else
    {
        cout << "It's a tie" << endl;
    }

    return 0;
}