#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N % 2 == 0)
    {
        cout << "Wrong input" << endl;
        return 0;
    }



    for (int i = 0; i < N; i++)
    {
        // Method-1
        if (N/2 >= i)
        {
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }

            if (N/2 == i)
            {
                cout << "X" << endl;
            }
            else
            {
                cout << "\\" ;

                for (int j = 0; j < N - 2 - 2*i; j++)
                {
                    cout << " ";
                }

                cout << "/" << endl;
            }
        }
        else
        {
            for (int j = i; j < N-1; j++)
            {
                cout << " ";
            }
            cout << "/";
            for (int j = 0; j < 2*i - N ; j++)
            {
                cout << " ";
            }
            cout << "\\" << endl;
        }

        // Method-2
        // string Y(i, ' ');

        // if (i < N / 2) {
        //     string Z(N-2*i-2, ' ');
        //     cout << Y << "\\" << Z << "/" << endl;
        // }
        // else if (i == N / 2)
        // {
        //     cout << Y << "X" << endl;
        // }
        // else {
        //     string Y(N - i - 1, ' ');
        //     string Z(2*i-N, ' ');
        //     cout << Y << "/" << Z << "\\" << endl;
        // }

    }

    return 0;
}