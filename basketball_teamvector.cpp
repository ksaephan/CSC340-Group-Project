/*
Implementation of the basketball_teamvector.h functions

*/

#include "basketball_teamvector.h"
#include "basketball_team.h"


namespace BASKETBALL_SPACE{

  //implement all functions for class basketball_team
  //REMEMBER ALL FUNCTIONS MUST HAVE SCOPE RESOLUTION OPERATOR WHICH ARE DOUBLE COLONS
  //Format: Basketball_Team::someFunction()
  
  //ALSO REMEMBER ALL GET FUNCTIONS MUST BE DECLARED CONST
  //Format: basketball_team::getFunction() const{ function body }
  
  //REMEMBER EVERYTHING MUST STAY INSIDE THE NAMESPACE BASKETBALL_SPACE

    //Default Constructor
    BasketballTeamVector::BasketballTeamVector(){
    }

    //Adds team to the teamlist, future use
    void BasketballTeamVector::addTeam(Basketball_Team team){
        teamlist.push_back(team);
    }

    //calculates total win rate over 2021, 2020, 2019
    double BasketballTeamVector::calcTotalWinrate(string teamname){
        double totalWinrate = 0;
        double winrate2019 = 0;
        double winrate2020 = 0;
        double winrate2021 = 0;

        //get winrate from 2019
        for (int i = 0; i < year2019.size(); i++){   
                if (year2019.at(i).getName() == teamname) {
                    winrate2019 = year2019.at(i).calculateWinrate(year2019.at(i).getGamesWon(), year2019.at(i).getGamesPlayed());
                }
            }

        //get winrate from 2020
        for (int i = 0; i < year2020.size(); i++){   
                if (year2020.at(i).getName() == teamname) {
                    winrate2020 = year2020.at(i).calculateWinrate(year2020.at(i).getGamesWon(), year2020.at(i).getGamesPlayed());
                }
            } 

        //get winrate from 2021
        for (int i = 0; i < year2021.size(); i++){   
                if (year2021.at(i).getName() == teamname) {
                    winrate2021 = year2021.at(i).calculateWinrate(year2021.at(i).getGamesWon(), year2021.at(i).getGamesPlayed());
                }
            }
        
        //average the winrates across 2021, 2020, 2019
        totalWinrate = ((winrate2019 + winrate2020 + winrate2021) / 3);

        return totalWinrate;               
    } //end of calcTotalWinrate function

    //Calculates total weighted score over 2019, 2020, 2021
    double BasketballTeamVector::calcTotalWeighted(string teamName){
        double totalWeight = 0;
        double weight2019 = 0;
        double weight2020 = 0;
        double weight2021 = 0;

        //get winrate from 2019
        for (int i = 0; i < year2019.size(); i++){   
                if (year2019.at(i).getName() == teamName) {
                    weight2019 = year2019.at(i).calculateWeightedScore(year2019.at(i).getOffensePoints(), year2019.at(i).getDefensePoints());
                }
            }

        //get winrate from 2020
        for (int i = 0; i < year2020.size(); i++){   
                if (year2020.at(i).getName() == teamName) {
                    weight2020 = year2020.at(i).calculateWeightedScore(year2020.at(i).getOffensePoints(), year2020.at(i).getDefensePoints());
                }
            } 

        //get winrate from 2021
        for (int i = 0; i < year2021.size(); i++){   
                if (year2021.at(i).getName() == teamName) {
                    weight2021 = year2021.at(i).calculateWeightedScore(year2021.at(i).getOffensePoints(), year2021.at(i).getDefensePoints());
                }
            }
        
        //average the winrates across 2021, 2020, 2019
        totalWeight = ((weight2019 + weight2020 + weight2021) / 3);
        return totalWeight;               
    } //End of calcTotalWeighted function


    //Get team from teamlist using thier name
    Basketball_Team BasketballTeamVector::getTeam(string name, int year){
        Basketball_Team emptyTeam;

        //check year for 2019
        if ( year == 2019){
            //iterate through 2019
            for (int i = 0; i < year2019.size(); i++){
                //compare team name at each element to the passed name, return object if they match for year 2019    
                if (year2019.at(i).getName() == name) {
                    return year2019.at(i);
                }
            }
        }
        
        //check year for 2020
        if (year == 2020){
            //iterate through 2020
            for (int i = 0; i < year2020.size(); i++) {
                //compare team name at each element to the passed name, return object if they match for year 2020
                if (year2020.at(i).getName() == name){
                    return year2020.at(i);
                }
            }
        }

        //check year for 2021
        if (year == 2021){
            //Iterate through 2021
            for (int i = 0; i < year2021.size(); i++) {

                //Compare the team name at each element to the passed name, return the object if they match for year 2021
                if (year2021.at(i).getName() == name) {
                    return year2021.at(i);
                }
            }
        }

        return emptyTeam;
    } // end of getTeam() function
    
    //reads and pulls all data from year2020 csv file
    void BasketballTeamVector::setYear2019(){
        ifstream ip;

        //this vector will be used to store the info from the csv file
        vector<string> data;

        //declarations used to help parse and tokenize the strings from vector<string>data
        string word, line, temp;
        string delimiters{", \n"};

        double games;
        double wins;
        double offPoints;
        double defPoints;

        // opening cbb19.csv file
        ip.open("cbb19.csv");
        //testing if file open correctly
        if(!ip.is_open()){
            cout << "Could not open file" << endl;
        }

        //beginning to store info from csv file to vector data
        while(!ip.eof()){
          //getting an entire row and store it in variable line
          getline(ip, line);
          //used for breaking up words
          stringstream s(line);
          while(getline(s,word,',')){
          data.push_back(word);
          }
        } // end of tokenizing while loop

        //Extracts data from our desired columns
        for(int i = 0; i < 353; i++){
          games = stod(data.at(25+(23*i)));
          wins = stod(data.at(26+(23*i)));
          offPoints = stod(data.at(27+(23*i)));
          defPoints = stod(data.at(28+(23*i)));
          year2019.push_back(Basketball_Team(data.at(23+(23*i)), data.at(24+(23*i)), games, wins, offPoints, defPoints));
        }
        ip.close();
    } // end of setYear2019 function

    //reads and pulls all data from year2020 csv file 
    void BasketballTeamVector::setYear2020(){
        ifstream ip;

        //this vector will be used to store the info from the csv file
        vector<string> data1;

        //declarations used to help parse and tokenize the strings from vector<string>data
        string word, line;

        double games;
        double wins;
        double offPoints;
        double defPoints;

        // opening cbb21.csv file
        ip.open("cbb20.csv");

        //testing if file open correctly
        if(!ip.is_open()){
            cout << "Could not open file" << endl;
        }

        //beginning to store info from csv file to vector data
        while(!ip.eof()){

          //getting an entire row and store it in variable line
          getline(ip, line);

          //used for breaking up words
          stringstream s(line);

          while(getline(s,word,',')){

          data1.push_back(word);
          }
        } // end of tokenizing while loop

        //Extracts data from our desired columns
        for(int i = 0; i < 353; i++){

          // converting strings to doubles
          games = stod(data1.at(25+(22*i)));
          wins = stod(data1.at(26+(22*i)));
          offPoints = stod(data1.at(27+(22*i)));
          defPoints = stod(data1.at(28+(22*i)));

          year2020.push_back(Basketball_Team(data1.at(23+(22*i)), data1.at(24+(22*i)), games, wins, offPoints, defPoints));
        }
    ip.close();
    }// end of setYear2020 function
    

    //reads and pulls all data from the year2021 csv file
    void BasketballTeamVector::setYear2021(){
        ifstream ip;

        //this vector will be used to store the info from the csv file
        vector<string> data;

        //declarations used to help parse and tokenize the strings from vector<string>data
        string word, line, temp;
        string delimiters{", \n"};

        double games;
        double wins;
        double offPoints;
        double defPoints;

        // opening cbb21.csv file
        ip.open("cbb21.csv");

        //testing if file open correctly
        if(!ip.is_open()){
            cout << "Could not open file" << endl;
        }

        //beginning to store info from csv file to vector data
        while(!ip.eof()){

          //getting an entire row and store it in variable line
          getline(ip, line);

          //used for breaking up words
          stringstream s(line);

          while(getline(s,word,',')){

          data.push_back(word);

          }
        } //end of tokenizing

        //Extracts data from our desired columns
        for(int i = 0; i < 347; i++){

          games = stod(data.at(24+(22*i)));
          wins = stod(data.at(25+(22*i)));
          offPoints = stod(data.at(26+(22*i)));
          defPoints = stod(data.at(27+(22*i)));

          year2021.push_back(Basketball_Team(data.at(22+(22*i)), data.at(23+(22*i)), games, wins, offPoints, defPoints));
        }
    ip.close();
    } // end of setYear2021 function 

    //check if team exists in the vector list
    bool BasketballTeamVector::checkName(string nameCheck){
        //checks year2021
        for (int i = 0; i < year2021.size(); i++){
            if (nameCheck == year2021.at(i).getName()){
                return true;
            }
        }

        //checks year2020
        for (int i = 0; i < year2020.size(); i++){
            if (nameCheck == year2020.at(i).getName()){
                return true;
            }
        }

        //checks year2019
        for (int i = 0; i < year2019.size(); i++){
            if (nameCheck == year2019.at(i).getName()){
                return true;
            }
        }

        return false;
    } //End of checkName function

    //print function
    void BasketballTeamVector::printData(string teamName){
        double totalW=(this->calcTotalWinrate(teamName));
        cout << endl;

         string c1 = (this->getTeam(teamName, 2020).getConference());//gets the conference and stores it for formatting output
        double c2 = this->calcTotalWeighted(teamName);//for the weighted score
        string c3 = (this->getTeam(teamName, 2020).toStr_yourChampionshipChance(this->getTeam(teamName, 2020).calculateTeamsChances(this->calcTotalWeighted(teamName))));//for chance
        cout << endl;
        cout << "\t\t\t\t\t**------ ALL INFORMAION IS BELOW ------**"<<endl<<endl;

        cout << "\t\t---------------------------------------------------------------------------------------------"<<endl;
        cout << "\t\t|\tCumulative win rate for " << teamName << " is: " << fixed << setprecision(1) << totalW << " %";
        cout << setw(50-(teamName.length()));
        cout << "|"<<endl;//Should be good, end of cumalitive win

        //conference
        cout << "\t\t|\tConference: "<<c1;
        cout << setw(73-(c1.length()));
        cout << "|"<<endl;//already good

        //CUMULATIVE WEIGHTED SCORE
        cout << "\t\t|\t"<< teamName << " Cumulative Weighted Score is: " << c2 << " of 100";
        cout << setw(43-(teamName.length()));
        cout << "|"<<endl;

        //Chance at Championship
        cout << "\t\t|\t"<< teamName << " Chance at Championship for next season is: " <<  c3;
        cout << setw(41-(teamName.length()+c3.length()));
        cout << "|"<<endl;

        cout << "\t\t---------------------------------------------------------------------------------------------"<<endl;
        cout <<endl<<"\t\t\t    **------ END OF ALL INFORMATION, READ BELOW FOR NEXT OPTION ------**" << endl;
    } //end of print function

} //end of BASKETBALL_SPACE