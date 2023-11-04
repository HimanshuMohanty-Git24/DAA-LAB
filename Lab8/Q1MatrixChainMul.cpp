// Aim of the experiment: Write a program to implement the matrix chain multiplication
#include <iostream>
#include <climits>
using namespace std;

void printOptimalParenthesis(int **S, int i, int j, char &matrixName)
{
    if (i == j)
    {
        cout << matrixName++;
        return;
    }
    cout << "(";
    printOptimalParenthesis(S, i, S[i][j], matrixName);
    printOptimalParenthesis(S, S[i][j] + 1, j, matrixName);
    cout << ")";
}

void matrixChainOrder(int p[], int n)
{
    int **M = new int *[n];
    int **S = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        M[i] = new int[n];
        S[i] = new int[n];
    }

    for (int i = 1; i < n; ++i)
    {
        M[i][i] = 0;
    }

    for (int l = 2; l < n; ++l)
    {
        for (int i = 1; i < n - l + 1; ++i)
        {
            int j = i + l - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k)
            {
                int q = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < M[i][j])
                {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }

    cout << "M Table:" << endl;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    cout << "S Table:" << endl;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }

    char matrixName = 'A';
    cout << "Optimal parenthesization: ";
    printOptimalParenthesis(S, 1, n - 1, matrixName);
    cout << endl;

    cout << "The optimal ordering of the given matrices requires " << M[1][n - 1] << " scalar multiplications." << endl;

    // Free allocated memory
    for (int i = 0; i < n; ++i)
    {
        delete[] M[i];
        delete[] S[i];
    }
    delete[] M;
    delete[] S;
}

int main()
{
    int dimensions[] = {2, 4, 5, 6}; // Matrix dimensions: 2x4, 4x5, 5x6
    int n = sizeof(dimensions) / sizeof(dimensions[0]);

    matrixChainOrder(dimensions, n);

    return 0;
}
