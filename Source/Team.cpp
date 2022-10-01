//AUTHOR: ADAM JOHNES
//DATE: September 9th, 2022 21:31:00

#include "Team.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

Team::Team(){}

Team::Team(const string name, const double qbTalent, const double o_strength, const double d_strength, const double st_strength, const double home, const double away)
{
  setAll(name, qbTalent, o_strength, d_strength, st_strength, home, away);
}

const string Team::getName()
{
  return this->name;
}

const double Team::getQbTalent()
{
  return this->qbTalent;
}

const double Team::getO_Strength()
{
  return this->o_strength;
}

const double Team::getD_Strength()
{
  return this->d_strength;
}

const double Team::getSt_Strength()
{
  return this->st_strength;
}

void Team::setName(const string name)
{
  this->name = name;
}
void Team::setTrue()
{
  this->used = true;
}

void Team::setQbTalent(const double qbTalent)
{
  if (qbTalent > 1)
    {
      cout << "Ensure the qbTalent is less than 1!" << endl;
      this->qbTalent = 0;
    }
  else if (qbTalent < 0)
    {
      cout << "Ensure the qbTalent is not a negative number!" << endl;
      this->qbTalent = 0;
    }
  else
    {
      this->qbTalent = qbTalent;
    }
}

void Team::setO_Strength(const double o_strength)
{
  if (o_strength > 1)
    {
      cout << "Ensure the o_strength is less than 1!" << endl;
      this->o_strength = 0;
    }
  else if (o_strength < 0)
    {
      cout << "Ensure the o_strength is not a negative number!" << endl;
      this->o_strength = 0;
    }
  else
    {
      this->o_strength = o_strength;
    }
}

void Team::setD_Strength(const double d_strength)
{
  if (d_strength > 1)
    {
      cout << "Ensure the d_strength is less than 1!" << endl;
      this->d_strength = 0;
    }
  else if (d_strength < 0)
    {
      cout << "Ensure the d_strength is not a negative number!" << endl;
      this->d_strength = 0;
    }
  else
    {
      this->d_strength = d_strength;
    }
}

void Team::setSt_Strength(const double st_strength)
{
  if (st_strength > 1)
    {
      cout << "Ensure the st_strength is less than 1!" << endl;
      this->st_strength = 0;
    }
  else if (st_strength < 0)
    {
      cout << "Ensure the st_strength is not a negative number!" << endl;
      this->st_strength = 0;
    }
  else
    {
      this->st_strength = st_strength;
    }
}

void Team::setHome(const double home)
{
  if (home > 1)
    {
      cout << "Ensure the home is less than 1!" << endl;
      this->home = 0;
    }
  else if (home < 0)
    {
      cout << "Ensure the home is not a negative number!" << endl;
      this->home = 0;
    }
  else
    {
      this->home = home;
    }
}

void Team::setAway(const double away)
{
  if (away > 1)
    {
      cout << "Ensure the away is less than 1!" << endl;
      this->away = 0;
    }
  else if (away < 0)
    {
      cout << "Ensure the away is not a negative number!" << endl;
      this->away = 0;
    }
  else
    {
      this->away = away;
    }
}

void Team::setAll(const string name, const double qbTalent, const double o_strength, const double d_strength, const double
		  st_strength, const double home, const double away)
{
  setName(name);
  setQbTalent(qbTalent);
  setO_Strength(o_strength);
  setD_Strength(d_strength);
  setSt_Strength(st_strength);
  setHome(home);
  setAway(away);
  this->used = false;
}

string Team::outputInfo()
{
  return this->name + "\t" + to_string(this->qbTalent) + "\t" + to_string(this->o_strength) + "\t" + to_string(this->d_strength) + "\t" + to_string(this->st_strength) + "\t" + to_string(this->home) + "\t" + to_string(this->away) + "\n";
}

string Team::printSchedule()
{
  string scheduleList = "\n" + this->name + "'s SCHEDULE\n";
  for (string week : this->schedule)
    {
      scheduleList += week + "\n";
    }
  return scheduleList;
}

ostream& operator<<(ostream &ostrm, const Team &team)
{
  return ostrm << "\nAll ratings are on a 0-1 scale, (0 being the worst, 1 being the best)\n" << team.name << "\nQb Rating: " << team.qbTalent << "\nOffensive Talent: " << team.o_strength << "\nDefensive Talent: " << team.d_strength << "\nK/ST Consistency and Head Coach Competence: " << team.st_strength << "\n\n";
}
