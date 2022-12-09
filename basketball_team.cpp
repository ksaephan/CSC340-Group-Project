/*
Group Members: Andy Almeida, Kao Saephan, Nicholas Valencia, Umaran Ahmadzai, Shanil Prasad
*/

#include "basketball_team.h"

namespace BASKETBALL_SPACE{
  //implement all functions for class basketball_team
  //REMEMBER ALL FUNCTIONS MUST HAVE SCOPE RESOLUTION OPERATOR WHICH ARE DOUBLE COLONS
  //Format: Basketball_Team::someFunction()
  
  //ALSO REMEMBER ALL GET FUNCTIONS MUST BE DECLARED CONST
  //Format: basketball_team::getFunction() const{ function body }
  
  //REMEMBER EVERYTHING MUST STAY INSIDE THE NAMESPACE BASKETBALL_SPACE

  //Default Constructor
  Basketball_Team::Basketball_Team(){
      name = "N/A";
      conference = "N/A";
      gamesWon = 0;
      gamesPlayed = 0;
      winRate = 0;
      offensePoints = 0;
      defensePoints = 0;
      weightedScore = 0;
      probableChance = yourChampionshipChance::NA;
  }

  //Paramaterized Constructor 
  Basketball_Team::Basketball_Team(string newName, string newConference, double newGamesPlayed, double newGamesWon, double newOffensePoints, double newDefensePoints) {
      name = newName;
      conference = newConference;
      gamesWon = newGamesWon;
      gamesPlayed = newGamesPlayed;
      winRate = 0;
      offensePoints = newOffensePoints;
      defensePoints = newDefensePoints;
      weightedScore = 0;
      probableChance = yourChampionshipChance::NA;
  }

  //Setters
  void Basketball_Team::setName(string newName){
    name = newName;
  }

  void Basketball_Team::setConference(string newConference){
    conference = newConference;
  }

  void Basketball_Team::setGamesWon(double newGamesWon){
    gamesWon = newGamesWon;
  }
      
  void Basketball_Team::setGamesPlayed(double newGamesPlayed){
    gamesPlayed = newGamesPlayed;
  }

  void Basketball_Team::setWinRate(double newWinRate){
    winRate = newWinRate;
  }

  void Basketball_Team::setOffensePoints(double newOffensePoints){
    offensePoints = newOffensePoints;
  }

  void Basketball_Team::setDefencePoints(double newDefensePoints){
    defensePoints = newDefensePoints;
  }

  void Basketball_Team::setWeightedScore(double newWeightedScore){
    weightedScore = newWeightedScore;
  }

  void Basketball_Team::setOffencePoints(yourChampionshipChance newChance){
    probableChance = newChance;
  }

  //Getters
  string Basketball_Team::getName() const{
    return name;
  }

  string Basketball_Team::getConference() const{
    return conference;
  }

  double Basketball_Team::getGamesWon() const{
    return gamesWon;
  }

  double Basketball_Team::getGamesPlayed() const{
    return gamesPlayed;
  }

  double Basketball_Team::getWinRate() const{
    return winRate;
  }    

  double Basketball_Team::getOffensePoints() const{
    return offensePoints;
  }
    
  double Basketball_Team::getDefensePoints() const{
    return defensePoints;
  }

  double Basketball_Team::getWeightedScore() const{
    return weightedScore;
  }

  yourChampionshipChance Basketball_Team::getProbableChance() const{
    return probableChance;
  }

  //this function calculates win rate based on games won and games played in a single year 
  double Basketball_Team::calculateWinrate(double gamesWon, double gamesPlayed){
    return ((gamesWon / gamesPlayed)*100);
  }

  //this function takes in the raw offense, defense, and winRate scores then gives them a weighted score out of 100. 
  double Basketball_Team::calculateWeightedScore(double offensePoints, double defensePoints){
    //control variable track score
    double weightScore = 0;
    double winrate = calculateWinrate(this->getGamesWon(), this->getGamesPlayed());
      
      //assigning points based on generic avg offense points
      if (offensePoints >= 110) {
        weightScore = weightScore + 30;
      }
      else if (offensePoints >= 100 && offensePoints < 110) {
        weightScore = weightScore + 24;
      }
      else if (offensePoints >= 90 && offensePoints < 100) {
        weightScore = weightScore + 18;
      }
      else if (offensePoints >= 80 && offensePoints < 90) {
        weightScore = weightScore + 12;
      }
      else if (offensePoints < 80) {
        weightScore = weightScore + 6;
      }

      //assign points based on generic avg defense points
      if (defensePoints >= 105) {
        weightScore = weightScore + 30;
      }
      else if (defensePoints >= 100 && offensePoints < 105) {
        weightScore = weightScore + 24;
      }
      else if (defensePoints >= 95 && offensePoints < 100) {
        weightScore = weightScore + 18;
      }
      else if (defensePoints >= 90 && offensePoints < 95) {
        weightScore = weightScore + 12;
      }
      else if (defensePoints < 90) {
        weightScore = weightScore + 6;
      }

      //assign points based on generic avg winrate
      if (winrate >= 70) {
        weightScore = weightScore + 40;
      }
      else if (winrate >= 60 && winrate < 70) {
        weightScore = weightScore + 32;
      }
      else if (winrate >= 50 && winrate < 60) {
        weightScore = weightScore + 24;
      }
      else if (winrate >= 40 && winrate < 50) {
        weightScore = weightScore + 16;
      }
      else if (winrate < 40) {
        weightScore = weightScore + 8;
      }

    //output the control variable
    return weightScore;
  } //end of calculate weighted score function

  //this function simply turns the yourChampionshipChance enumerated class object into a string 
  string Basketball_Team::toStr_yourChampionshipChance( yourChampionshipChance chance ){
      switch (chance){
          case yourChampionshipChance::HighChance:
              return "High Chance";
          case yourChampionshipChance::MedChance:
              return "Med Chance";
          case yourChampionshipChance::LowChance:
              return "Low Chance";
          case yourChampionshipChance::ExtremelyUnlikely:
              return "Extremely Unlikely";
          default:  //this will not happen. just to make this compiler not generate a warning.
              return "Nobody Knows, this could be an error";  
      } 
  } //end of toStr_yourChampionshipChance function

  //based on the weighted score out of 100, this function calculates yourChampionshipChance from
  //enum class yourChampionshipChance {GreatChance, GoodChance, LowChance, ExtremelyUnlikely } 
  yourChampionshipChance Basketball_Team::calculateTeamsChances(double weightedScore){
    if (weightedScore <= 100.0 && weightedScore >= 0.0){
      if (weightedScore >= 70){
        return yourChampionshipChance::HighChance;
      }
      else if(weightedScore >= 55 && weightedScore < 70) {
        return yourChampionshipChance::MedChance;
      }
      else if(weightedScore >= 40 && weightedScore < 55) {
        return yourChampionshipChance::LowChance;
      }
      else if(weightedScore < 40) {
        return yourChampionshipChance::ExtremelyUnlikely;
      }
    }
    return yourChampionshipChance::NA;

  }//end of the calculateTeamsChances function 
} //end of BASKETBALL_SPACE