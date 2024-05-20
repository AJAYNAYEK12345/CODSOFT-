#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    int num1;
    srand(time(NULL));
    const int X =rand()%100+1;    
    while(1){                                                  
    cout<<"\n guess the number in between 1 to 100:";       
    cin>>num1;

    if(num1==X)
    {                                           
        cout<<"\n congratulation The guessing the Number Is right: "<<num1;
        return 0;
    }
    else if(num1>X)
    {             
        cout<<"\n the number is very large.";
    }
    else                                        
        cout<<"\n the number is very small.";
    
    }
}                                             