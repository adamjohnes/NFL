//Team class

#ifndef Team_class
#define Team_class

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

class Team
{
public:
  std::string name;
  double qbTalent, o_strength, d_strength, st_strength, home, away;
  std::vector<std::string> schedule;
  bool used;
  std::vector<std::string> opposition;
  std::vector<std::string> homeOrAway;
  std::string byeWeek;
  
public:
  Team();
  Team(const std::string name, const double qbTalent, const double o_strength, const double d_strength, const double st_strength, const double home, const double away);

  const std::string getName();
  const double getQbTalent();
  const double getO_Strength();
  const double getD_Strength();
  const double getSt_Strength();

  void setName(const std::string name);
  void setQbTalent(const double qbTalent);
  void setO_Strength(const double o_strength);
  void setD_Strength(const double d_strength);
  void setSt_Strength(const double st_strength);
  void setHome(const double home);
  void setAway(const double away);
  void setAll(const std::string name, const double qbTalent, const double o_strength, const double d_strength, const double st_strength, const double home, const double away);

  void setTrue();
  void selectCategory(const std::string category, const std::string fileName);
  std::string printSchedule();
  
  double majorIncrement(const double value);
  double minorIncrement(const double value);
  double majorDecrement(const double value);
  double minorDecrement(const double value);

  void addWin();
  void addLoss();

  std::string outputInfo();
  
  friend std::ostream& operator<<(std::ostream &ostrm, const Team &team);
};

#endif
