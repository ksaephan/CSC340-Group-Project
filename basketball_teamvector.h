#ifndef basketball_teamvector_h
#define basketball_teamvector_h

#include "basketball_team.h"

namespace BASKETBALL_SPACE{
  using namespace std;

  class BasketballTeamVector{  
     public:
        //Default Constructor
        BasketballTeamVector();

        void printTop5(Basketball_Team team); //not implemented yet

        //Adds team to the list
        void addTeam(Basketball_Team team); //for future use, included just in case

        //Calculates total winrate over 2019, 2020, 2021
        double calcTotalWinrate(string teamname);

        //Calculates total weighted score over 2019, 2020, 2021
        double calcTotalWeighted(string teamName); 

        //Get team from the list using thier name
        Basketball_Team getTeam(string name, int year);

        //checks if the name if the school is in the list
        bool checkName(string nameCheck);

        // this function will set the vector with basketball team objects using cbb19.csv and cbb20.csv and cbb21.csv
        void setYear2019();
        void setYear2020();
        void setYear2021();

        //print function: cumulative winrate, conference, weighted score, Chance at championship
        void printData(string teamName);

    private:
        vector<Basketball_Team> teamlist;
        vector<Basketball_Team> year2019;
        vector<Basketball_Team> year2020;
        vector<Basketball_Team> year2021;
      
  }; //end of BasketBall_team class
} //end of BASKETBALL_SPACE
#endif //end of basketball_team_h 
