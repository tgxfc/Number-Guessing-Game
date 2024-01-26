#include <iostream>
#include <ctime>
#include "colors.hpp"
using namespace std;


int main()
{
    srand (time(0));
    int attempt=9;
    int number=rand()%1000;

    cout<<colors::red<<"N "<<colors::green<<"U "<<colors::yellow<<"M "<<colors::blue<<"B "<<colors::magenta<<"E "<<colors::cyan<<"R "<<"   "
    <<colors::red<<"G "<<colors::green<<"U "<<colors::yellow<<"E "<<colors::blue<<"S "<<colors::magenta<<"S "<<colors::cyan<<"I "<<colors::red<<"N "<<colors::green<<"G"<<"   "
    <<colors::yellow<<"G "<<colors::blue<<"A "<<colors::magenta<<"M "<<colors::cyan<<"E "<<colors::reset<<"\n";
    cout<<colors::bright_yellow<<"You have to guess a randomly generated number from 0 to 999 in 10 turns or less."<<colors::reset<<"\n";
    cout<<colors::bright_white<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<colors::reset<<"\n";
    cout<<endl;

    while(attempt>-1)
    {
        int guess;
        cout<<colors::bold<<colors::blue<<"Enter a number: "<<colors::reset;
        cin>>guess;

        if(guess==number)
        {
            cout<<endl;
            cout<<colors::bright_red<<"This is the correct number!"<<colors::reset;
            cout<<endl;
            break;
        }
        if(guess<number)
        {
            cout<<colors::bright_cyan<<"The number is too small!"<<colors::reset<<"\n";
            attempt==1 ? cout<<colors::bright_cyan<<"You have "<<colors::white<<attempt<<colors::bright_cyan<<" turn left."<<colors::reset<<"\n" :
            cout<<colors::cyan<<"You have "<<colors::white<<attempt<<colors::cyan<<" turns left."<<colors::reset<<"\n";
            cout<<endl;
        }
        if(guess>number)
        {
            cout<<colors::bright_cyan<<"The number is too big!"<<colors::reset<<"\n";
            attempt==1 ? cout<<colors::cyan<<"You have "<<colors::white<<attempt<<colors::cyan<<" turn left."<<colors::reset<<"\n" :
            cout<<colors::cyan<<"You have "<<colors::white<<attempt<<colors::cyan<<" turns left."<<colors::reset<<"\n";
            cout<<endl;
        }

        if(attempt==0)
        {
            cout<<colors::red<<"You didn't guess the number!"<<colors::reset<<"\n";
            cout<<colors::bright_red<<"The correct number was "<<colors::red<<number<<colors::bright_red<<"!"<<colors::reset;
            cout<<endl;
        }
        attempt--;
    }

    system("pause");
}
