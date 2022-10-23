#pragma once

#include <string>
#include <iostream>

using namespace std;

class Player {
private:
  static int lastCreatedPlayerId;

private:
  unsigned int id;
  string username;
  string password;

public:
  Player();
  Player(string, string);

public:
  ~Player();

public:
  friend ostream& operator<<(ostream&, Player&);
};