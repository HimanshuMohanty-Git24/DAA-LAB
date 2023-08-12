// Guess Game
//  A and B are playing a guessing game where B first thinks up an integer X (positive, negative or
//  zero, and could be of arbitrarily large magnitude) and A tries to guess it. In response to A’s guess, B gives exactly one of the following three replies:
//  a) Try a bigger number
//  b) Try a smaller number or
//  c) You got it. Write a program by designing an efficient algorithm to minimize the number of guesses A has to
//  make. An example (not necessarily an efficient one) below:
//  Assume B thinks up the number 35. A’s guess B’s response. 10 Try a bigger number
//  20 Try a bigger number
//  30 Try a bigger number
//  40 Try a smaller number
//  35 You got it
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cout << "Enter the number : ";
    cin >> x;
    int a = -100, b = 100, c;
    int ctr = 0;
    while (true)
    {
        ctr++;
        c = (a + b) / 2;
        cout << "Guess " << ctr << " : " << c << endl;
        // user input bigger or smaller or you got it
        string s;
        cin >> s;
        if (s == "bigger")
        {
            a = c;
        }
        else if (s == "smaller")
        {
            b = c;
        }
        else if (s == "you")
        {
            cout << "You got it in " << ctr << " guesses" << endl;
            break;
        }
    }
    return 0;
}