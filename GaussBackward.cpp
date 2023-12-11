#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a[10][10], x, u1, u, y;
    int i, j, n, n1, fact = 1;

    cout << "enter the n" << endl;
    cin >> n;

    cout << "enter the x: ";
    for (i = 0; i < n; i++)
        cin >> a[i][0];

    cout << "enter the y: ";
    for (i = 0; i < n; i++)
        cin >> a[i][1];

    cout << "enter the value to predict" << endl;
    cin >> x;

    for (j = 2; j < n + 1; j++)
    {
        for (i = 0; i < n - j + 1; i++)
        {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    cout << "the difference table is" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n - i; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    // Gauss Backward
    y = a[n / 2][1];
    cout << "\n y: " << y << endl;
    u = (x - a[n / 2][0]) / (a[1][0] - a[0][0]);
    u1 = u;
    cout << u1 << endl;

    for (i = 2; i <= n; i++)
    {
        y = y + (u1 / fact) * a[(n - 2) / i][i];
        cout<< a[(n - 1) / i][i] << "\t";
        fact = fact * i;
        if (i % 2 == 0)
        {
            u1 = u1 * (u + (i / 2));
            cout << u1 << endl;
        }
        else
        {
            u1 = u1 * (u - (i / 2));
            cout << u1 << endl;
        }
    }

    cout << "\n\nthe desired value is " << y << endl;
    return 0;
}
