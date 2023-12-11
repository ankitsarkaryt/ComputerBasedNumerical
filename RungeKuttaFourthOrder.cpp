#include<bits/stdc++.h>
using namespace std;

float func(float x, float y)
{
    return x+y;
}

int main()
{
    float x,y,h,z;

    cout<<"Enter x and f(x) : "<<endl;
    cin>>x>>y;

    cout<<"Enter step size : ";
    cin>>h;

    cout<<"Enter the value for approximation : ";
    cin>>z;

    int n = (z-x)/h;

    for(int i=0;i<n;i++)
    {
        float k1 = h*func(x,y);
        float k2 = h*func(x+h/2,y+k1);
        float k3 = h*func(x+h/2,y+k2/2);
        float k4 = h*func(x+h,y+k3);
        y = y + (k1+2*k2+2*k3+k4)/6;
        x = x+h;
    }

    cout<<"Answer = "<<y;

    return 0;
}