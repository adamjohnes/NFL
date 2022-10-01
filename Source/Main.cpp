//AUTHOR: ADAM JOHNES
//DATE: September 9th, 2022 21:31:00

#include "Team.h"
#include "Spread.h"
#include "time.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

//declare certain methods up here
void selectTeam(string name);
void printMenu();

//global variables
int week;
vector<Team> teamList;


time_t current = time(0);

void calculateWeek()
{
  if (current <= 1664167948)
    {
      week = 2;
      return;
    }
  else if (current <= 1664304348)
    {
      week = 3;
      return;
    }
  else if (current <= 1664775222)
    {
      week = 4;
      return;
    }
  else if (current <= 1665380022)
    {
      week = 5;
      return;
    }
  else if (current <= 1665984822)
    {
      week = 6;
      return;
    }
  else if (current <= 1666589622)
    {
      week = 7;
      return;
    }
  else if (current <= 1667194422)
    {
      week = 8;
      return;
    }
  else if (current <= 1668404022)
    {
      week = 9;
      return;
    }
  else if (current <= 1669008822)
    {
      week = 10;
      return;
    }
  else if (current <= 1669613622)
    {
      week = 11;
      return;
    }
  else if (current <= 1670218422)
    {
      week = 12;
      return;
    }
  else if (current <= 1670823222)
    {
      week = 13;
      return;
    }
  else if (current <= 1671428022)
    {
      week = 14;
      return;
    }
  else if (current <= 1672032822)
    {
      week = 15;
      return;
    }
  else if (current <= 1672637622)
    {
      week = 16;
      return;
    }
  else if (current <= 1673242422)
    {
      week = 17;
      return;
    }
  else
    {
      week = 18;
      return;
    }
}

vector<Team> importTeams(string fileName)
{
  ifstream file (fileName);
  vector<Team> localTeamList;
  char splitter = '\t';
  string line, name;
  double qbTalent, o_strength, d_strength, st_strength, home, away;

  if (!file)
    {
      cout << "Error trying to read/open file " << fileName << "\n";
      exit(1);
    }

  getline(file, line);
  while (getline(file, line))
    {
      istringstream split(line);
      string each;
      for (int i = 0; i < 7; i++)
	{
	  Team newTeam;
	  getline(split, each, splitter);
	  switch (i)
	    {
	    case 0:
	      name = each;
	      //newTeam.setName(each);
	      break;
	    case 1:
	      qbTalent = stod(each);
	      //newTeam.setQbTalent(stod(each));
	      break;
	    case 2:
	      o_strength = stod(each);
	      //newTeam.setO_Strength(stod(each));
	      break;
	    case 3:
	      d_strength = stod(each);
	      //newTeam.setD_Strength(stod(each));
	      break;
	    case 4:
	      st_strength = stod(each);
	      //newTeam.setSt_Strength(stod(each));
	      break;
	    case 5:
	      home = stod(each);
	      //newTeam.setHome(stod(each));
	      break;
	    case 6:
	      away = stod(each);
	      //newTeam.setAway(stod(each));
	      newTeam.setAll(name, qbTalent, o_strength, d_strength, st_strength, home, away);
	      localTeamList.push_back(newTeam);
	      break;
	    }
	}
    }
  return localTeamList;
}

void selectCategory(string &category, Team &teamToChange)
{

  if (category == "5")
    {
      selectTeam(teamToChange.name);
      return;
    }
  
  string input;
  cout << "[1] Improve Drastically (0.05+ rating)\n";
  cout << "[2] Improve Slightly (0.025+ rating)\n";
  cout << "[3] Worsen Drastically (0.05- rating)\n";
  cout << "[4] Worsen Slightly (0.025- rating)\n";
  cin >> input;
  
  if (input == "1")
    {
      if (category == "1")
	{
	  teamToChange.qbTalent+=0.05;
	  selectTeam(teamToChange.name);
	}
      else if (category == "2")
	{
	  teamToChange.o_strength+=0.05;
	  selectTeam(teamToChange.name);
	}
      else if (category == "3")
	{
	  teamToChange.d_strength+=0.05;
	  selectTeam(teamToChange.name);
	}
      else if (category == "4")
	{
	  teamToChange.st_strength+=0.05;
	  selectTeam(teamToChange.name);
	}
      else
	{
	  cout << "Ensure you typed a proper change. (Number 1-4)\n";
	  selectTeam(teamToChange.name);
	}
    }
  else if (input == "2")
    {
      if (category == "1")
	{
	  teamToChange.qbTalent+=0.025;
	  selectTeam(teamToChange.name);
	}
      else if (category == "2")
	{
	  teamToChange.o_strength+=0.025;
	  selectTeam(teamToChange.name);
	}
      else if (category == "3")
	{
	  teamToChange.d_strength+=0.025;
	  selectTeam(teamToChange.name);
	}
      else if (category == "4")
	{
	  teamToChange.st_strength+=0.025;
	  selectTeam(teamToChange.name);
	}
      else
	{
	  cout << "Ensure you typed a proper change. (Number 1-4)\n";
	  selectTeam(teamToChange.name);
	}
    }
  else if (input == "3")
    {
      if (category == "1")
	{
	  teamToChange.qbTalent-=0.05;
	  selectTeam(teamToChange.name);
	}
      else if (category == "2")
	{
	  teamToChange.o_strength-=0.05;
	  selectTeam(teamToChange.name);
	}
      else if (category == "3")
	{
	  teamToChange.d_strength-=0.05;
	  selectTeam(teamToChange.name);
	}
      else if (category == "4")
	{
	  teamToChange.st_strength-=0.05;
	  selectTeam(teamToChange.name);
	}
      else
	{
	  cout << "Ensure you typed a proper change. (Number 1-4)\n";
	  selectTeam(teamToChange.name);
	}
    }
  else if (input == "4")
    {
      if (category == "1")
	{
	  teamToChange.qbTalent-=0.025;
	  selectTeam(teamToChange.name);
	}
      else if (category == "2")
	{
	  teamToChange.o_strength-=0.025;
	  selectTeam(teamToChange.name);
	}
      else if (category == "3")
	{
	  teamToChange.d_strength-=0.025;
	  selectTeam(teamToChange.name);
	}
      else if (category == "4")
	{
	  teamToChange.st_strength-=0.025;
	  selectTeam(teamToChange.name);
	}
      else
	{
	  cout << "Ensure you typed a proper change. (Number 1-4)\n";
	  selectTeam(teamToChange.name);
	}
    }
  else
    {
      cout << "Ensure you entered the correct selection.\n";
      selectTeam(teamToChange.name);
    }
}

void outputToTeams()
{
  ofstream file  ("Resources/teams.txt");
  file << "Team Name\tQB Rating\tOffensive Strength\tDefensive Strength\tST/HC Strength\tHome\tAway\n";
  for (int i = 0; i < teamList.size(); i++)
    {
      file << teamList.at(i).outputInfo();
    }
}

void readInByeWeeks(const string fileName, vector<Team> &teamList)
{
  ifstream file (fileName);
  string line;
  int count = 0;
  
  if (!file)
    {
      cout << "Error trying to read in file: " << fileName << "\n";
      exit(1);
    }
  while (getline(file, line))
    {
      teamList.at(count++).byeWeek = line;
    }
}

void readInSchedule(const string fileName, vector<Team> &teamList)
{
  ifstream file (fileName);
  string line;
  char splitter = ',';
  int weekCount = 3;
  
  if (!file)
    {
      cout << "Error trying to read in schedule file: " << fileName << "\n";
      exit(1);
    }

  while (getline(file, line))
    {
      istringstream split(line);
      string each, away, home;
      for (int i = 0; i < 2; i++)
	{
	  getline(split, each, splitter);
	  if (each == "-")
	    {
	      weekCount++;
	      break;
	    }

	  switch (i)
	    {
	    case 0:
	      away = each;
	      break;
	    case 1:
	      home = each;
	    }
	}
      transform(away.begin(), away.end(), away.begin(), ::toupper);
      transform(home.begin(), home.end(), home.begin(), ::toupper);
      for (int i = 0; i < teamList.size(); i++)
	{
	  if (teamList.at(i).name == away)
	    { 
	      string week = string("Week ") + to_string(weekCount) + ": vs " + home;
	      teamList.at(i).schedule.push_back(week);
	      teamList.at(i).homeOrAway.push_back("A");
	      teamList.at(i).opposition.push_back(home);
	    }
	  else if (teamList.at(i).name == home)
	    {
	      string week = string("Week ") + to_string(weekCount) + ": vs " + away;
	      teamList.at(i).schedule.push_back(week);
	      teamList.at(i).homeOrAway.push_back("H");
	      teamList.at(i).opposition.push_back(away);
	    }
	}
    }

  file.close();
}

void selectTeam(string name)
{
  int valid = 0;
  string input;

  for (int i = 0; i < teamList.size(); i++)
    {
      transform(teamList.at(i).name.begin(), teamList.at(i).name.end(), teamList.at(i).name.begin(), ::toupper);
      if (name == teamList.at(i).name)
	{
	  valid = 1;
	  cout << "Information about: " << teamList.at(i).name << "\n";
	  cout << "[1] Show Schedule\n";
	  cout << "[2] Show Team Strength (used in spread calculations)\n";
	  cout << "[3] Edit Team Strength Stats\n";
	  cout << "[4] Back to Menu\n";
	  cin >> input;
	  if (input == "1")
	    {
	      cout << teamList.at(i).printSchedule() << "\n";
	      selectTeam(name);
	    }
	  else if (input == "2")
	    {
	      cout << teamList.at(i);
	      selectTeam(name);
	    }
	  else if (input == "3")
	    {
	      cout << "Which category would you like to change?\n";
	      cout << "[1] QB Talent\n";
	      cout << "[2] Offensive Strength\n";
	      cout << "[3] Defensive Strength\n";
	      cout << "[4] K/ST/HC Strength\n";
	      cout << "[5] Back to Team Menu\n";
	      cin >> input;
	      if (input != "1" && input != "2" && input !="3" && input != "4" && input != "5")
		{
		  cout << "Ensure you entered the selection correctly, try again.\n";
		  selectTeam(name);
		}
	      selectCategory(input, teamList.at(i));
	      outputToTeams();
	    }
	  else if (input == "4")
	    {
	      return;
	    }
	  else
	    {
	      cout << "Ensure you entered the selection correctly, try again.\n";
	      selectTeam(name);
	    }
	}
    }
  if (valid == 0)
    {
      cout << "Ensure you entered the name correctly, try again.\n";
      cin >> input;
      transform(input.begin(), input.end(), input.begin(), ::toupper);
      selectTeam(input);
    }
}

void updateRecord(string winLoss)
{
  ifstream file ("Resources/record.txt");
  string line, input;
  char splitter = '-';
  int wins, losses;

  if (winLoss != "1" && winLoss != "2" && winLoss != "3" && winLoss != "4")
    {
      cout << "Ensure you entered a proper selection\n";
      printMenu();
    }
  
  if (!file)
    {
      cout << "Error trying to read in schedule file: Resources/record.txt\n";
      exit(1);
    }

  getline(file, line);
  istringstream split(line);
  string each, wRecord, lRecord;
  for (int i = 0; i < 2; i++)
  {
    getline(split, each, splitter);
    if (i == 0)
      {
	wins = stoi(each);
      }
    else if (i == 1)
      {
	losses = stoi(each);
      }
  }

  if (winLoss == "1")
    {
      wins+=1;
    }
  else if (winLoss == "2")
    {
      losses+=1;
    }
  else if (winLoss == "3")
    {
      wins-=1;
    }
  else if (winLoss == "4")
    {
      losses-=1;
    }

  wRecord = to_string(wins);
  lRecord = to_string(losses);
  
  ofstream outFile ("Resources/record.txt");
  outFile << wRecord << "-" << lRecord;
  outFile.close();
  printMenu();
}

void printRecord()
{
  ifstream file ("Resources/record.txt");
  string line, input;
  char splitter = '-';
  string wins, losses;

  if (!file)
    {
      cout << "Error trying to read in schedule file: Resources/record.txt\n";
      exit(1);
    }

  getline(file, line);
  istringstream split(line);
  string each, wRecord, lRecord;
  for (int i = 0; i < 2; i++)
    {
      getline(split, each, splitter);
      if (i == 0)
	{
	  wins = each;
	}
      else if (i == 1)
	{
	  losses = each;
	}
    }
  
  file.close();
  cout << "Wins: " << wins << "\nLosses: " << losses << "\nRecord: " << wins << "-" << losses << endl;
}

void printHelp()
{
  cout << "------------------USER MANUAL------------------\n";
  cout << "This is software developed by Adam Johnes. The idea behind the program is to generate NFL spreads\n and compare these spreads to Vegas' NFL spreads on a week-by-week basis. Although the goal is to generate spreads\n that remotely resemble these Vegas NFL spreads, the more important idea is to see which spreads are most unalike,\n and use these games as betting advantages.\n";
  cout << "\nExample:\nIf there were 16 games to be played over a particular weekend, the program would\n generate 16 spreads accordingly. If 13 of the programmatically generated spreads matched vegas (or were very near\n matches) then that means there are 3 games that are standing out. These are the games that the program proposes\n to bet on; and the games where the program's record is generated from.\n";
  cout << "\n-------------------SPREADS--------------------\n";
  cout << "Spreads are popular options for sports betting. Spreads involve a point difference between two teams\n in a particular match. It is how many points the favorite is prefered to win over the underdog. If a spread is\n read as -3.5, this means that the favorite is preferred by Vegas to win by 3.5 points. Obviously, it is impossible\n in the NFL to score half a point. The reasoning for this is to avoid ties in betting. Essentially, you would either\n have to bet that the favorite wins by 4 or more, or you bet that the underdog loses by 3 or less.\n";
  cout << "\n------------------OVER / UNDER----------------\n";
  cout << "The over / under, or often referred to as [O/U] by both Vegas and this program, is the sum of total\n points that is expected to be scored by both teams in a particular game. Similar to the spread, it also tends to\n end in a .5 for the same reason.\n";
  cout << "\n----------------USER NAVIGATION----------------\n";
  cout << "Most navigation tools in this program are through single digit responses followed by\n pressing 'ENTER'. This seemed like the most simple and efficient method that allows input to be predictable while also\n maintaining effectiveness. Please try to stick to these numbers in giving responses, unless told to do otherwise.\n";
}

void printSpreads()
{
  Spread spread;
  for (int i = 0; i < teamList.size(); i++)
    {
      if (teamList.at(i).used != true)
	{
	  for (int j = 0; j < teamList.size(); j++)
	    {
	      if (teamList.at(i).opposition.at(week - 3) == teamList.at(j).name)
		{
		  teamList.at(i).used = true;
		  teamList.at(j).used = true;
		  if (teamList.at(i).homeOrAway.at(week - 3) == "H")
		    {
		      spread.setHomeTeam(teamList.at(i));
		      spread.setAwayTeam(teamList.at(j));
		      spread.calculatePoints();
		      cout << spread << endl;
		    }
		  if (teamList.at(i).homeOrAway.at(week - 3) == "A")
		    {
		      spread.setHomeTeam(teamList.at(j));
		      spread.setAwayTeam(teamList.at(i));
		      spread.calculatePoints();
		      cout << spread << endl;
		    }
		}
	    }
	}
    }
  for (int i = 0; i < teamList.size(); i++)
    {
      teamList.at(i).used = false;
    }
  printMenu();
  /**
  for (int i = 0; i < spreads.size(); i++)
    {
      cout << spreads.at(i) << endl;
    }
  **/
}

void insertByeWeeks(vector<Team> &teamList)
{
  for (int i = 0; i < teamList.size(); i++)
    {
      for (int j = 0; j < teamList.size(); j++)
	{
	  if (stoi(teamList.at(i).byeWeek) == j)
	    {
	      teamList.at(i).schedule.insert(teamList.at(i).schedule.begin() + j - 3, "BYE");
	      teamList.at(i).homeOrAway.insert(teamList.at(i).homeOrAway.begin() + j - 3, "H");
	      teamList.at(i).opposition.insert(teamList.at(i).opposition.begin() + j - 3, "BYE");
	    }
	}
    }
}

void printMenu()
{
  string input;
  cout << "\n--------------MENU---------------" << "\n";
  cout << "\nType your selection(i.e. press '1'), then press 'ENTER'" << "\n";
  cout << "[1] Show Spreads\n";
  cout << "[2] Select Team\n";
  cout << "[5] View Program's Overall Record on the Season\n";
  cout << "[6] Update Program's Record\n";
  cout << "[7] Show how Spreads are Calculated\n";
  cout << "[8] Help (Basic Explanation of the Program and NFL Sports Betting)\n";
  cout << "[9] Exit\n";
  cin >> input;
  while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input !=
	 "7" && input != "8" && input != "9")
    {
      cout << "Ensure you entered a number without an additional characters. (i.e, 2 or 7)";
      cin >> input;
    }
  if (input == "1")
    {
      printSpreads();
    }
  else if (input == "2")
    {
      cout << "Which team did you want to see details of? (enter team name, caps dont matter)";
      cin >> input;
      transform(input.begin(), input.end(), input.begin(), ::toupper);
      selectTeam(input);
      printMenu();
    }
  else if (input == "5")
    {
      printRecord();
      printMenu();
    }
  else if (input == "6")
    {
      cout << "Would you like to add/remove a win or a loss?\n";
      cout << "[1] Add a Win\n";
      cout << "[2] Add a Loss\n";
      cout << "[3] Remove a Win\n";
      cout << "[4] Remove a Loss\n";
      cin >> input;
      updateRecord(input);
    }
  else if (input == "7")
    {
      cout << "Spread Calculations\n--------------------------\n";
      cout << "Spreads are calculated using an equation that gives a rating, between 0.00 and 1.00, to important aspects of each team. This rating is then multiplied by 12.5, (or 5 in the case of K/ST/HC, as I feel that category is not nearly as influential). For example, if the Chiefs (who currently have Patrick Mahomes) QB talent is .95, then the points from their QB into the equation would look like this:\n 12.5 * .95 = 11.75\n There are a total of 42.5 'points' a particular team can earn. The aspects that are considered by the program when calculating the spreads are the following:\n";
      cout << "[1. QB Talent /12.5] QBs are the most important position on the football field. It is important to consider just how valuable these players are towards their team success.\n";
      cout << "[2. Offensive Strength /12.5] This category considers how talented and consistent a teams offense performs. It looks at specific positions such as the quarterback, runningback and pass catchers, as well as how many points they score on any given week.\n";
      cout << "[3. Defensive Strength /12.5] This category considers how talented and consistent a teams defense performs. It looks at key personnel such as edge rushers, cornerbacks, safeties and linebackers. It also considers how many points a defense gives up on a given week.\n";
      cout << "[4. HC/ST Strength /5.0] This category is deemed as not as important as the others and thus is only out of 5.0 instead of 12.5. Sure, they could win/lose games, but so can anything else. It turns out a kicker cannot carry a team like a quarterback (Mahomes) or defensive tackle (Aaron Donald) can. Thus it is rated as such. For this rating, we look at ST consistency, the starting kicker's accuracy and the overall competence of the Head Coach (yes, this does matter)\n";
      cout << "There are a couple other important details it considers, like home/away but for the most part that is it. Similarly to the spread, the O/U is also calculated using these values.\n";
      printMenu();
    }
  else if (input == "8")
    {
      printHelp();
      printMenu();
    }
  else if (input == "9")
    {
      exit(1);
    }

}

int main()
{

  calculateWeek();
  cout << "Welcome to Adam's NFL Bet Helper! [WEEK: " << to_string(week) << "]\n";

  teamList = importTeams("Resources/teams.txt");
  readInByeWeeks("Resources/byeWeeks.txt", teamList);
  readInSchedule("Resources/schedule.txt", teamList);
  insertByeWeeks(teamList);
  
  printMenu();
  /**for (auto itr : teamList)
         {
	       cout << itr;
	           }
  **/

  return 0;
}
