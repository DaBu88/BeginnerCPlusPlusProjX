/*
CIS 215, Summer 2022
Date: 8/24/22
Author: David Buckley
Assignment: Week 14 Fun with Polymorphism
Comments: 
*/

#include<iostream>
#include <string>
using namespace std;
// the base class
class FootballPlayer
{
 public:
    FootballPlayer()
    {
        cout << "Calling the FootballPlayer constructor" << endl;
    }
    // prints out the main function that the player's position contributes to the team 
    virtual void primaryRoles() = 0;
    string getName()
    {
        return playerName;
    }
    void setName(string name)
    {
        playerName = name;
    }
    void setGamesPlayed(int numGames) 
    {
        gamesPlayed = numGames;
    }
 protected:
    string playerName;
    int gamesPlayed;
}; // end of class Team

// derived DefensiveLineman class
class DefensiveLineman: public FootballPlayer
{
    public:
        DefensiveLineman(string name, int numGamesPlayed)
        {
            playerName = name;
            gamesPlayed = numGamesPlayed;
            cout << "Calling the DefensiveLineman constructor" << endl;
        }
        // this function overrides the FootballPlayer primaryRoles() function
        void primaryRoles()
        {
            cout << playerName << "'s primary roles are to tackle offensive players and to bat down or intercept passes." << endl;
        }
        void setSackTotal(int numSacks) 
        {
            sackTotal = numSacks;
        }
        double SacksPerGame() 
        {
            return (double)sackTotal / (double)gamesPlayed;
        }
    private:
        // number of sacks made by the defensive lineman
        int sackTotal;

}; // end of class Spider

// a derived class
class Kicker: public FootballPlayer
{
    public:
        Kicker(string name, int numGamesPlayed)
        {
            playerName = name;
            gamesPlayed = numGamesPlayed;
            cout << "Calling the Kicker constructor" << endl;
        }
        // this function overrides the FootballPlayer primaryRoles() function
        void primaryRoles()
        {
            cout << playerName << "'s primary roles are to kick field goals and conduct kickoffs." << endl;
        }
        void setFGAttemptTotal(int numFGs) 
        {
            totalFGAttempts = numFGs;
        }
        double FGAttemptsPerGame() 
        {
            return (double)totalFGAttempts / (double)gamesPlayed;
        }
    private:
        int totalFGAttempts;
}; // end of class Kicker
// a derived class
class Quarterback: public FootballPlayer
{
    public:
        Quarterback(string name, int numGamesPlayed)
        {
            playerName = name;
            gamesPlayed = numGamesPlayed;
            cout << "Calling the Quarterback constructor" << endl;
        }
        // this function overrides the FootballPlayer primaryRoles() function
        void primaryRoles()
        {
            cout << playerName << "'s primary roles are to orchestrate the offense, pitch or hand the ball off to other players, pass the ball, and rush with the ball." << endl;
        }
        void setTouchdownTotal(int numTDPasses) 
        {
            totalTouchdownsScored = numTDPasses;
        }
        double touchdownsPerGame() 
        {
            return (double)totalTouchdownsScored / (double)gamesPlayed;
        }
    private:
        int totalTouchdownsScored;

}; // end of class Quarterback
// test inheritance and polymorphism
int main()
{
    Quarterback ChargersQB("Justin Herbert", 32);
    ChargersQB.primaryRoles();
    ChargersQB.setTouchdownTotal(69);
    cout << ChargersQB.getName() << " has scored " << ChargersQB.touchdownsPerGame() << " touchdowns on average per game." << endl;

    DefensiveLineman FourtyNinersDE("Nick Bosa", 35);
    FourtyNinersDE.primaryRoles();
    FourtyNinersDE.setSackTotal(24.5);
    cout << FourtyNinersDE.getName() << " has an average sack rate per game of " << FourtyNinersDE.SacksPerGame() << " sacks." << endl;

    Kicker RamsPK("Matt Gay", 33);
    RamsPK.primaryRoles();
    RamsPK.setFGAttemptTotal(85);
    cout << RamsPK.getName() << " has averaged " << RamsPK.FGAttemptsPerGame() << " field goal attempts per game in the games he has played." << endl;
}