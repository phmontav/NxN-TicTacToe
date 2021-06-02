#include <bits/stdc++.h>
using namespace std;

//enum situacoes {a = "Vitoria do jogador O",b =""}
class tic_tac_toe
{
    int size;
    char **tab;
    int turn = 0;
    bool victory = false;
    int plays = 0;

public:
    tic_tac_toe(int s)
    {
        size = s;
        tab = new char *[s];
        for (int i = 0; i < s; i++)
        {
            tab[i] = new char[s];
        }
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s; j++)
            {
                tab[i][j] = ' ';
            }
        }
    }

    void getTurn()
    {
        if (turn == 0)
            cout << "turn: O" << endl;
        else
            cout << "turn: X" << endl;
    }
    void play(int x, int y);
    void print();
    bool check(int x, int y,char c);
    bool getVictory()
    {
        return victory;
    } 
};

void tic_tac_toe::play(int x, int y)
{


    if (x < 0 || x >= size)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    if (y < 0 || y >= size)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    if (tab[x][y] != ' ')
    {
        cout << "Occupied Position" << endl;
        return;
    }
    else
    {
        if (turn == 0)
        {
            tab[x][y] = 'O';
            plays++;
            if(check(x,y,'O'))
            {
                print();
                cout << "O wins"  <<  endl;
                victory = true;
                return;
            } 
        }
        else
        {
            tab[x][y] = 'X';
            plays++;
            if(check(x,y,'X'))
            {
                print();
                cout << "X wins" << endl;
                victory = true;
                return;
            } 
        }
        if(plays == size*size)
        {
            cout << "Draw" << endl;
            victory = true;
            return;
        }
        
    }
    turn++;
    turn = turn % 2;
}
void tic_tac_toe::print()
{
    cout << "  ";
    for(int i = 1; i <= size; i++)
    {
        cout << i << "  ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i+1 << " ";
        for (int j = 0; j < size; j++)
        {
            if (j != size - 1)
            {
                cout << tab[i][j] << "| ";
            }
            else
                cout << tab[i][j];
        }
        cout << endl;
        cout << " ";
        if (i != size - 1)
        {
            for (int k = 0; k < size + size/2; k++)
                cout << "- ";
                
            cout << "-" << endl;
        }
    }
    cout << endl
         << endl;
}
bool tic_tac_toe ::check(int x,int y, char c)
{
    bool check_line = true;
    bool check_col = true;
    bool check_diag1 = true;
    bool check_diag2 = true;
    for(int i = 0; i < size; i++)
    {
        if(tab[x][i] != c) 
        {
            check_line = false;
            break;
        }
        
    }
    for(int i = 0; i < size; i++)
    {
        if(tab[i][y] != c) 
        {
            check_col = false;
            break;
        }
        
    }
    if (x == y)
    {
        for(int i = 0; i < size; i++)
        {
            if(tab[i][i] != c)
            {
                check_diag1 = false;
                break;
            }
        }
        if(check_diag1 == true) return true;
    }
    if(x + y == size-1)
    {
        for(int i = 0; i < size; i++)
        {
            if(tab[i][size - i - 1] != c)
            {
                check_diag2 = false;
                break;
            }
        }
        if(check_diag2 == true) return true;
    }

    if(check_col == true || check_line == true ) return true;
    return false;
}

int main()
{
    int sz;
    cout << "insert the tic tac toe size:" << endl;
    cin >> sz;
    tic_tac_toe ttt(sz);
    while (1)
    {
        int x = 0, y = 0; 
        ttt.print();
        ttt.getTurn();
        cout << "insert the coordinates" << endl;
        cin >> x >> y;
        ttt.play(x-1,y-1);
        if(ttt.getVictory()) break;


    }
}