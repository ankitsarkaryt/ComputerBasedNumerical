#include<iostream>

using namespace std;

int main()
{
    int n,i,j,p;
    cout<<"Enter the value of n : ";
    cin>>n;

    float arr[n][n+1];
    float x,y,u;

    cout<<"Enter x : ";
    for(i=0;i<n;i++)
    {
        cin>>x;
        arr[i][0] = x;
    }

     cout<<"Enter y : ";
    for(i=0;i<n;i++)
    {
        cin>>y;
        arr[i][1] = y;
    }

    for(i=2;i<=n;i++)
    {
        for(j=0;j<n-i+1;j++)
        {
            arr[j][i] = arr[j+1][i-1] - arr[j][i-1];
        }
    }

    cout<<"Difference Table \n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n-i;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

     /*Newton Backward Interpolation
    ------------------------------*/

    float y1 = arr[n-1][1];
    float x1;
    cout<<"Enter x1 for backward interpolation : ";
    cin>>x1;

    u = (x1 - arr[n-1][0])/(arr[1][0]-arr[0][0]);
    cout<<"u = "<<u<<endl;

    float u1 = u;
    int fact = 1;

    for(i=2;i<=n;i++)
    {
        y1 = y1 + (u1*arr[n-i][i])/fact;

        u1 = u1*(u+(i-1));
        fact = fact*i;
    }
    cout<<"Backward Interpolation Answer = "<<y1<<endl;

    /*Newton Forward Interpolation
    ------------------------------*/

    y1 = arr[0][1];

    float x2;
    cout<<"Enter x2 for forward interpolation : ";
    cin>>x2;
    u = (x2 - arr[0][0])/(arr[1][0]-arr[0][0]);
    cout<<"u = "<<u<<endl;
   u1 = u;

    for(i=2;i<=n;i++)
    {
        y1 = y1 + (u1*arr[0][i])/fact;
        u1 = u1 * (u1-(i-1));
        fact =fact*i;
    }
    cout<<"Forward Interpolation Answer = "<<y1<<endl;

    return 0;

}