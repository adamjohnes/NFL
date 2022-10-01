//Spread class

#ifndef Spread_class
#define Spread_class

#include "Team.h"
#include <string>
#include <iostream>

class Spread
{
 public:
  Team homeTeam;
  Team awayTeam;
  double homePoints, awayPoints;

 public:
  Spread();
  Spread(const Team homeTeam, const Team awayTeam);

  void calculatePoints();
  Team getHomeTeam();
  Team getAwayTeam();
  double getHomePoints();
  double getAwayPoints();

  void setHomeTeam(const Team homeTeam);
  void setAwayTeam(const Team awayTeam);
  void setHomePoints(const double homePoints);
  void setAwayPoints(const double awayPoints);
  
  friend std::ostream& operator<<(std::ostream &ostrm, const Spread &spread);
};

#endif
