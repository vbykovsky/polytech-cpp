#pragma once

#include <string>
#include <iostream>

using namespace std;

// #4
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
  // #5
  friend ostream& operator<<(ostream&, Player&);
};