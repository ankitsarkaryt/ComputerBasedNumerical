#include<iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter number of records: ";
    cin >> n;

    float arr[n][n + 1] = {0};

    cout << "Enter data points:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0];  // x-coordinate
        cin >> arr[i][1];  // y-coordinate
    }

    // Calculating divided differences
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            arr[j][i] = (arr[j + 1][i - 1] - arr[j][i - 1]) / (arr[j + i - 1][0] - arr[j][0]);
        }
    }

    float ans = arr[0][1];

    // Displaying the divided differences matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    cout << "Enter value to be interpolated: ";
    float x;
    cin >> x;

    float f = 1;
    for (int i = 2; i <= n; i++) {
        f *= (x - arr[i - 2][0]);
        ans += (f * arr[0][i]);
    }

    cout << "The interpolated value at " << x << " is: " << ans << endl;

    return 0;
}
