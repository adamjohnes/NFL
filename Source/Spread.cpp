//AUTHOR: ADAM JOHNES
//DATE: September 9th, 2022 21:31:00

#include "Spread.h"
#include "Team.h"
#include <string>

using namespace std;

Spread::Spread(){}

Spread::Spread(const Team homeTeam, const Team awayTeam)
{
  this->homeTeam = homeTeam;
  this->awayTeam = awayTeam;
}

Team Spread::getHomeTeam()
{
  return this->homeTeam;
}

Team Spread::getAwayTeam()
{
  return this->awayTeam;
}

double Spread::getHomePoints()
{
  return this->homePoints;
}

double Spread::getAwayPoints()
{
  return this->awayPoints;
}

void Spread::setHomeTeam(const Team homeTeam)
{
  this->homeTeam = homeTeam;
}

void Spread::setAwayTeam(const Team awayTeam)
{
  this->awayTeam = awayTeam;
}

void Spread::setHomePoints(const double homePoints)
{
  this->homePoints = homePoints;
}

void Spread::setAwayPoints(const double awayPoints)
{
  this->awayPoints = awayPoints;
}

void Spread::calculatePoints()
{
  double hmPts = ((12.5 * (1 - awayTeam.getD_Strength())) + (12.5 * homeTeam.getO_Strength()) + (12.5 * homeTeam.getQbTalent()) + (5 * homeTeam.getSt_Strength()) + 0.5);
  double awPts = ((12.5 * (1 - homeTeam.getD_Strength())) + (12.5 * awayTeam.getO_Strength()) + (12.5 * awayTeam.getQbTalent()) + (5 * awayTeam.getSt_Strength()) - 0.5);
  int intHmPts = (int)hmPts;
  int intAwPts = (int)awPts;
  hmPts = 0.5 + intHmPts;
  awPts = intAwPts;
  if (hmPts == awPts) { hmPts += 0.5; }
  setHomePoints(hmPts);
  setAwayPoints(awPts);
}

ostream& operator<<(ostream &ostrm, const Spread &spread)
{
  if (spread.awayPoints >= spread.homePoints)
    {
      return ostrm << "Away: " << spread.awayTeam.name <<  " -" << spread.awayPoints - spread.homePoints << " | Home: " << spread.homeTeam.name << " +" << spread.awayPoints - spread.homePoints << " [O/U] " << spread.awayPoints + spread.homePoints << "\n";
    }
  else
    {
      return ostrm << "Away: " << spread.awayTeam.name <<  " +" << spread.homePoints - spread.awayPoints << " | Home: " << spread.homeTeam.name << " -" << spread.homePoints - spread.awayPoints << " [O/U] " << spread.awayPoints + spread.homePoints << "\n";
    }
}
