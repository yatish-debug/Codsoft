#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    long n1,n2;
    char oprator;
    cout<<"Enter The Number 1=";
    cin>>n1;
    cout<<"Enter The Number 2=";
    cin>>n2;
    cout<<"Enter The Operator=";
    cin>>oprator;
    switch(oprator)
    {
        case '+':
        cout<<"Sum="<<n1+n2<<endl;
        break;
        case '-':
        cout<<"Subtract="<<n1-n2<<endl;
        break;
        case '*':
        cout<<"Multiplication="<<n1*n2<<endl;
        break;
        case '/':
        if(n2==0)
        {
            cout<<"This Number Is Not A Valid Input Because The Operation Is Not Valid";
        }
        else 
        {
            cout<<"Result ="<<n1/n2<<endl;
        }
        break;
        default:
        cout<<"Operation Is Not Valid:Pls Try New Operation";
        getch();
    }
}
// Coded By Yatish Hemant Bharambe // Level 1 // Task 2
