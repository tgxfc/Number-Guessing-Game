#include <iostream>
#include <ctime>
#include "colors.hpp"
using namespace std;

void printTitle(int score, int streak)
{
    cout<<colors::bright_yellow<<"                    ****************************************"<<colors::reset<<"\n";
    cout<<colors::red<<"                    N "<<colors::green<<"U "<<colors::yellow<<"M "<<colors::blue<<"B "<<colors::magenta<<"E "<<colors::cyan<<"R "<<"   "
        <<colors::red<<"G "<<colors::green<<"U "<<colors::yellow<<"E "<<colors::blue<<"S "<<colors::magenta<<"S "<<colors::cyan<<"I "<<colors::red<<"N "<<colors::green<<"G"<<"   "
        <<colors::yellow<<"G "<<colors::blue<<"A "<<colors::magenta<<"M "<<colors::cyan<<"E "<<colors::reset<<"\n";
    cout<<colors::yellow<<"You have to guess a randomly generated number from 0 to 999 in 10 turns or less."<<colors::reset<<"\n";
    cout<<colors::bright_yellow<<"---------------------------------------------------------------------------------"<<colors::reset<<"\n";
    cout<<colors::magenta<<"Score: "<<colors::bright_blue<<score<<"        "<<colors::magenta<<"Streak: "<<colors::bright_blue<<streak<<colors::reset<<"\n";
    cout<<colors::bright_yellow<<"================================================================================="<<colors::reset<<"\n";
}

void printGuesses(int* guessList, int guessCount)
{
    cout<<colors::blue<<"Guesses: ";
    for(int i=0; i<guessCount; i++)
    {
        cout<<colors::bright_blue<<guessList[i]<<colors::reset<<" ";
    }
    cout<<endl;
}

int main()
{
    srand (time(0));

    char playAgain='y';
    int streak=0, score=0;
    bool flagstreak=false, flagscore=false;
    printTitle(score,streak);

    while(toupper(playAgain)=='Y') {
        int attempt=9;
        int number=rand()%1000;
        int guessList[11], guessCount=0;

        while (attempt>-1)
        {
            int guess;
            cout<<colors::bold<<colors::blue<<"Enter a number: "<<colors::reset;
            if(cin>>guess)
            {
                system("cls");
                printTitle(score,streak);
                guessList[guessCount]=guess;
                guessCount++;
                printGuesses(guessList,guessCount);
                cout<<endl;
            }

            if (guess==number)
            {
                cout<<endl;
                cout<<colors::bright_red<<"This is the correct number!"<<colors::reset;
                cout<<endl;
                flagscore=true;
                flagstreak=true;
                break;
            }
            if (guess<number)
            {
                cout<<colors::bright_cyan<<"The number is too small!"<<colors::reset<<"\n";
                attempt==1 ? cout<<colors::cyan<<"You have "<<colors::white<<attempt<<colors::cyan<<" turn left."<<colors::reset<<"\n" :
                cout<<colors::cyan<<"You have "<<colors::white<<attempt<<colors::cyan<<" turns left."<< colors::reset<<"\n";
                cout<<endl;
            }
            if (guess>number)
            {
                cout<<colors::bright_cyan<<"The number is too big!"<<colors::reset<<"\n";
                attempt==1 ? cout<<colors::cyan<<"You have "<<colors::white<< attempt<<colors::cyan<<" turn left."<<colors::reset<<"\n" :
                cout<<colors::cyan<<"You have "<<colors::white<<attempt<<colors::cyan<< " turns left."<<colors::reset<<"\n";
                cout<<endl;
            }

            if (attempt==0)
            {
                cout<<colors::red<<"You didn't guess the number!"<<colors::reset<<"\n";
                cout<<colors::bright_red<<"The correct number was "<<colors::red<<number<<colors::bright_red<<"!"<<colors::reset;
                cout<<endl;
            }
            attempt--;
            flagstreak=false;
            flagscore=false;
        }
        flagstreak ? streak+=1 : streak=0;
        flagscore ? score+=10 : score-=5;

        cout<<endl;
        cout<<colors::green<<"Do you want to play again?"<<colors::bright_green<<" (y/n) "<<colors::reset;
        if(cin>>playAgain)
        {
            system("cls");
            printTitle(score,streak);
        }
    }
}
