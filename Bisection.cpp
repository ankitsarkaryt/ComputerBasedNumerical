#include<iostream>
using namespace std;

double equation(double x)
{
    return x*x - 2*x - 1;
}

int main()
{
    double x1=2,x2=3,x3;
    while(x2-x1>0.0000001)
    {
        x3 = (x1+x2)/2;

        if(equation(x3)==0)break;
        else
        {
            if(equation(x3)>0) x2 = x3;
            else x1 = x3;
        }
    }
    cout<<"Root = "<<x3;

    return 0;
}