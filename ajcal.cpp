#include<iostream>
using namespace std;
int main()
{
    int a,b,ans;
    int cho;
    top:
    cout<<"Input  first number:";
    cin>>a;
    cout<<"\ninput second number:";
    cin>>b;
    x:
    cout<<"Enter Your Choice:\n";
    cout<<"1. Addition\n";
    cout<<"2. Subtraction\n";
    cout<<"3. Multiplication\n";
    cout<<"4. Divition\n";
    if(!(cin>>cho))
    {
        return 1;
    }                                           
    if(cho==1){
        ans=a+b;
        cout<<"\nsum of "<<a<<" + "<<b<<" = "<<ans;
    }
    else if(cho==2){
        ans=a-b;
        cout<<"\nsubtraction of "<<a<<" - "<<b<<" = "<<ans;
    }
    else if(cho==3){
        ans=a*b;
        cout<<"\nMultiplication of "<<a<<" * "<<b<<" = "<<ans;
    }
    else if(cho==4){
        if(b==0){
            cout<<"\nDivisible by zero is Not possible please try again\n";
            goto top;
        }
        else{
        float X=(float)a/b;
        cout<<"\nDivision of "<<a<<" / "<<b<<" = "<<X;
        }
    }
    else{
        cout<<"Wrong choice \n";
        goto x;
    }
    return 0;
}