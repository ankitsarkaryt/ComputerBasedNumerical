#include<bits/stdc++.h>
using namespace std;

float func(float x)
{
    return 1/(1+(x*x));
}

int main()
{
    float a,b,h;
    int i,interval;

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
        if(i==0||i==interval) ans+= y[i];
        else if(i%2==0) ans+= 2*y[i];
        else ans+= 4*y[i];
    }
    cout<<"The Answer = "<<(ans*h)/3;

    return 0;
}