// mazestack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

class Coord
{
public:
    Coord(int r, int c) : m_row(r), m_col(c) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
private:
    int m_row;
    int m_col;
};

bool pathExists(string maze[], int nRows, int nCols,
                int sr, int sc, int er, int ec)
{
    stack<Coord> istack;
    istack.push(Coord(sr, sc));
    maze[sr][sc] = '_';

    while (!istack.empty())
    {
        Coord current = istack.top();
        istack.pop();

        if (current.r() == er && current.c() == ec)
            return true;

        int cR = current.r();
        int cC = current.c();
        // If you can move EAST  and haven't encountered that cell yet:
        if (maze[cR + 1][cC] == '.') 
        {
            istack.push(Coord(cR + 1, cC));
            maze[cR + 1][cC] = '_';
        }
        // If you can move NORTH and haven't encountered that cell yet:
        if (maze[cR][cC - 1] == '.') 
        {
            istack.push(Coord(cR, cC - 1));
            maze[cR][cC - 1] = '_';
        }
        // If you can move WEST  and haven't encountered that cell yet:
        if (maze[cR - 1][cC] == '.') 
        {
            istack.push(Coord(cR - 1, cC));
            maze[cR - 1][cC] = '_';
        }
        // If you can move SOUTH and haven't encountered that cell yet:
        if (maze[cR][cC + 1] == '.') 
        {
            istack.push(Coord(cR, cC + 1));
            maze[cR][cC + 1] = '_';
        }

    }

    return false;

}

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X....X...X",
        "X.XX.XX..X",
        "XXX....X.X",
        "X.XXX.XXXX",
        "X.X...X..X",
        "X...X.X..X",
        "XXXXX.X.XX",
        "X........X",
        "XXXXXXXXXX"
    };

    if (pathExists(maze, 10, 10, 3, 5, 8, 8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}