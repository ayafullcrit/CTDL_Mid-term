#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string.h>
#include <fstream>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
void Print(float f[101][101], int N, int M, string VariableCol[], string VariableRow[])
{
    cout << " ";
    FOR(k, 1, (N + M + 2) * 11 - 1)
    cout << "_";
    cout << endl;
    cout << "|" << setw(10);
    FOR(i, 0, N + M)
    {
        cout << VariableCol[i];
        cout << "|" << setw(10);
    }
    cout << setw(12) << "Value|\n";
    VariableRow[M + 1] = "Z";
    FOR(i, 1, M + 2)
    {
        cout << "|";
        int uCount = 0;
        FOR(k, 1, (N + M + 2) * 11)
        {
            if (uCount == 10)
            {
                cout << '|';
                uCount = 0;
                continue;
            }
            uCount++;
            cout << '-';
        }
        if (i == M + 2)
            break;
        cout << endl;
        cout << "|" << setw(10) << VariableRow[i] << "|" << setw(10);

        FOR(j, 1, N + M + 1)
        {
            cout << f[i][j] << "|";
            if (j <= N + M)
                cout << setw(10);
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
int main()
{
    //file input
    string FileName;
    cout << "Nhap ten file input: ";
    cin >> FileName;
    freopen(FileName.c_str(), "r", stdin);
    
    int x;
    cin >> x;
    cout << x;
}

/*
2
2
3 5
x2 <= 4
x1 <= 3

2
2
3 5
x1 + 2x2 <= 6
3x1 + 2x2 <= 12

2
2
40 30
2x1 + x2 <= 16
x1 + x2 <= 9

3
2
3 5
-2x1 + -4x2 >= -40
3x1 + 2x2 <= 36
6x1 + 5x2 <= 60

2
2
8 6
4x1 + 2x2 <= 60 
2x1 + 4x2 <= 48
*/