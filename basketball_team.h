/*
declaration of the following class in namespace BASKETBALL_SPACE:
  -class basketball_team

contains our enumerated class yourChampionshipChance
contains the to_string function for our enumerated class

*/

#ifndef basketball_team_h
#define basketball_team_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>


namespace BASKETBALL_SPACE{
  using namespace std;
  
  //A class to classify each team with a Championship Win Chance -kao
  enum class yourChampionshipChance {HighChance, MedChance, LowChance, ExtremelyUnlikely, NA};

  class Basketball_Team{
    public:

      //Default Constructor 
      Basketball_Team();

      //Parameterized Constructor
      Basketball_Team(string newName, string newConference, double newGamesWon, double newGamesPlayed, double newOffensePoints, double newDefensePoints);

      //this function calculates win rate based on games won and games played in a single year
      double calculateWinrate(double gamesWon, double gamesPlayed);

      //this function takes in the raw offense, defense, and winRate scores then gives them a weighted score out of 100.
      //Took out winRate as part of the score b/c we dont know avg scores so it became too difficult to predict how to assign points based on win rate
      double calculateWeightedScore(double offensePoints, double defensePoints); 

      //based on the weighted score out of 100, this function calculates yourChampionshipChance from
      //enum class yourChampionshipChance {GreatChance, GoodChance, LowChance, ExtremelyUnlikely }
      yourChampionshipChance calculateTeamsChances(double weightedScore); //this is a function

      //I think that this could be put into overrides
      //this function simply turns the yourChampionshipChance enumerated class object into a string
      string toStr_yourChampionshipChance( yourChampionshipChance chance );

      //Getters
      string getName() const;
      string getConference() const;
      double getGamesWon() const;
      double getGamesPlayed() const;
      double getWinRate() const;    
      double getOffensePoints() const;
      double getDefensePoints() const;
      double getWeightedScore() const;
      yourChampionshipChance getProbableChance() const;

      //Setters
      void setName(string newName);
      void setConference(string newConference);
      void setGamesWon(double newGamesWon);
      void setGamesPlayed(double newGamesPlayed);
      void setWinRate(double newWinRate);
      void setOffensePoints(double newOffencePoints);
      void setDefencePoints(double newDefencePoints);
      void setWeightedScore(double newWeightedScore);
      void setOffencePoints(yourChampionshipChance newChance);
      
    private:
      string name;
      string conference;
      double gamesWon;
      double gamesPlayed;
      double winRate;    
      double offensePoints;
      double defensePoints;
      double weightedScore;
      yourChampionshipChance probableChance;

  }; //end of BasketBall_team class
} //end of BASKETBALL_SPACE
#endif //end of basketball_team_h 
