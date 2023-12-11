#include<bits/stdc++.h>
using namespace std;

float func(float x)
{
    return x*x;
}

int main()
{
    float a,b,h;
    int interval,i;

    cout<<"Enter Lower Limit, Upper Limit and Interval"<<endl;
    cin>>a>>b>>interval;

    h = (b-a)/interval;

    vector<float>y(interval);

    for(i=0;i<=interval;i++)
    {
        y[i] = func(i*h);
    }

    float ans = 0;

    for(i=0;i<=interval;i++)
    {
        if(i==0||i==interval) ans+=y[i];
        else ans+=2*y[i];
    }

    cout<<"The Answer of The Given Interval is "<<(ans*h)/2;
    return 0;
}