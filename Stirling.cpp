#include <iostream>
using namespace std;

int main()
{
    float a[10][10], x, u1, u, y;
    int i, j, n, fact = 1;

    cout << "Enter the n: ";
    cin >> n;

    cout << "Enter the x: ";
    for (i = 0; i < n; i++)
        cin >> a[i][0];

    cout << "Enter the y: ";
    for (i = 0; i < n; i++)
        cin >> a[i][1];

    cout << "Enter the value to predict: ";
    cin >> x;

    for (j = 2; j <= n; j++)
    {
        for (i = 0; i < n - j + 1; i++)
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
    }

    cout << "The difference table is \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n - i; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    y = a[n / 2][1];
    cout << "\n y: " << y;

    u = (x - a[n / 2][0]) / (a[1][0] - a[0][0]);
    u1 = u;
    cout << "\n"
         << u1;

    for (i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            y = y + (u1 / fact) * ((a[(n - 2) / 2][i] + a[(n - 1) / 2][i]) / 2);
            u1 = (u1 * (u - 1));
            cout << "\n"
                 << u1;
            cout << "\n"
                 << ((a[(n - 2) / 2][i] + a[(n - 1) / 2][i]) / 2);
        }
        else
        {
            y = y + (u1 / fact) * a[(n - 2) / 2][i];
            u1 = (u1 * (u - 1));
            cout << "\n"
                 << u1;
            cout << "\n"
                 << a[(n - 2) / 2][i];
        }
        fact = fact * i;
    }

    cout << "\n\nThe desired value is " << y << endl;
    return 0;
}
