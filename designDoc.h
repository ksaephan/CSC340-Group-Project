/*

Group Members: Andy Almeida, Kao Saephan, Nicholas Valencia, Umaran Ahmadzai, Shanil Prasad


What this whole program does: 
    Main function:
         1) gets input team name from the user
         2) if the user inputs a team name, then the main function will call the functions checkName() and printData()
         3) checkName() checks to see if that team name is in the vector of basketball team objects, prints error message if not
         4) if found then printData() will print the avgerage win rate, conference, average weighted score, and a probability chance of winning next championship!
    
    
    basketball_team.h
        //description: a class that contains four labels correlating to levels of chance to win a championship
        enum class yourChampionshipChance
            data: {HighChance, MedChance, LowChance, ExtremelyUnlikely, NA}
  

        class Basketball_Team {
            //description: a class that will allow for data allocation for each team
            data:
                string name;
                string conference;
                double gamesWon;
                double gamesPlayed;
                double winRate;
                double offensePoints;
                double defensePoints;
                double weightedScore;
                yourChampionshipChance probableChance;
            functions:

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
                } //end of function


                //Parameterize Constructor 
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
                } //end of function


                Getters that return a const data member


                Setters that can set the new data members


                //description: calculate a winrate based on gamesplayed and gameswon
                double calculateWinrate(double gamesWon, double gamesPlayed){ 
                    return (gamesWon/gamesPlayed)
                } //end of function


                //description: calculates a score from a base of 100 based on Offense and Defense points and cumulative win rate
                double calculateWeightedScore(double offensePoints, double defensePoints){
                    if(offense points is this){
                        apply apropriate points
                    }

                    if(defense points is this){
                        apply apropriate points
                    }

                    if(win rate is this){
                        apply apropriate points
                    }
                } // end of function


                //description: given the weighted score, apply an appropriate probable chance
                yourChampionshipChance calculateTeamsChances(double weightedScore){
                    switch(whatever the weighted score is){
                        apply apropriate enumerated label or chance
                    }
                } //end of function


                //converts the enumerated object(our label) into a string.
                string toStr_yourChampionshipChance( yourChampionshipChance chance ){
                    switch(whatever the enumerated object is){
                        apply apropriate to_string conversion
                    }
                } //end of function  

        } //end of class Basketball_Team
    } //end of basketball_team.h and .cpp too


    basketball_teamvector.h
        description: contains a class that will store the vector of basketball_teams along with potential functions
        class Team_Vector {
            data: 
                vector<Basketball_Team> teamlist; //for future use if we wanted to combine all 3 years
                vector<Basketball_Team> year2019;
                vector<Basketball_Team> year2020;
                vector<Basketball_Team> year2021;


            functions:
                void addTeam(Basketball_Team team); //for future use, adds new team to teamlist
                
                
                //iterates through each year and returns the team object when found
                void getTeam(string name, int year){
                    if(2019){
                        check year2019 vector for team name and return the team
                    }
                    if(2020){
                        check year2020 vector for team name and return the team
                    }
                    if(2021){
                        check year2021 vector for team name and return the team
                    }
                } //end of function 
                

                //Calculates average winrate over the last 3 years
                double calcTotalWinrate(string teamname){
                    if(iterate through vector named year2019) {
                        get this team's winrate for 2019
                    }
                    
                    if(iterate through vector named year2020) {
                        get this team's winrate for 2020
                    }

                    if(iterate through vector named year2021) {
                        get this teams winrate for 2021
                    }
                    returns an average win rate of a team based on the last 3 years
                } //end of function
                

                //Calculates average weighted score over the last 3 years
                double calcTotalWeighted(string teamName){
                    if(iterate through vector named year2019) {
                        get this team's weighted score for 2019
                    }
                    
                    if(iterate through vector named year2020) {
                        get this team's weighted score for 2020
                    }

                    if(iterate through vector named year2021) {
                        get this teams weighted score for 2021
                    }
                    returns an average weighted score of a team based on the last 3 years
                } //end of function
                

                //checks to see if there is a team by that name
                bool checkName(string nameCheck){
                    if(iterate through vector named year2019) {
                        check to see if this team participated in 2019, returns true if found
                    }
                    
                    if(iterate through vector named year2020) {
                        check to see if this team participated in 2020, returns true if found
                    }

                    if(iterate through vector named year2021) {
                        check to see if this team participated in 2021, returns true if found
                    }
                    returns false otherwise
                } //end of function
                

                //sets all the data from 2019 csv file into a vector. Those elements for the vectors are then assigned to a basketball team object.
                //That basketball team object that has all the data fields assigned is then pushed into a vector 
                void setYear2019(){
                    open the file for 2019

                    if(file not open){
                        output error line
                    }

                    while(not end of file){
                        tokenize file into words using delimiter ","(a comma)
                        add all the words into a temp vector of strings
                    }

                    for(iterate through temp vector of strings){
                        pull relevant information, store that information into a team, and push the team into vector for this year
                    }
                    close the file for 2019
                } //end of function
                

                //sets all the data from 2020 csv file. Those elements for the vectors are then assigned to a basketball team object.
                //That basketball team object that has all the data fields assigned is then pushed into a vector 
                void setYear2020(){
                    open the file for 2020

                    if(file not open){
                        output error line
                    }

                    while(not end of file){
                        tokenize file into words using delimiter ","(a comma)
                        add all the words into a temp vector of strings
                    }

                    for(iterate through temp vector of strings){
                        pull relevant information, store that information into a team, and push the team into vector for this year
                    }
                    close the file for 2020
                } 
               

                //sets all the data from 2021 csv file. Those elements for the vectors are then assigned to a basketball team object.
                //That basketball team object that has all the data fields assigned is then pushed into a vector 
                void setYear2021(){
                    open the file for 2021

                    if(file not open){
                        output error line
                    }

                    while(not end of file){
                        tokenize file into words using delimiter ","(a comma)
                        add all the words into a temp vector of strings
                    }

                    for(iterate through temp vector of strings){
                        pull relevant information, store that information into a team, and push the team into vector for this year
                    }
                    close the file for 2021
                } //end of function
               

                //This functions prints out team name, conference, a weighted score, and the probability of winning championship!
                void printData(string teamName){
                    print all relevant data and format it to look professional
                } //end of function 
        } //end of class Team_Vector
    } //end of basketball_teamvector.h and the .cpp too 

*/

