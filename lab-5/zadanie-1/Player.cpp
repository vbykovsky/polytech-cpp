#include "Player.hpp"

int Player::lastCreatedPlayerId = -1;

Player::Player(): Player("", "") {
  this->username = to_string(this->id);
}

Player::Player(string username, string password): username(username), password(password) {
  Player::lastCreatedPlayerId += 1;

  this->id = Player::lastCreatedPlayerId;
}

Player::~Player() {
  cout << *this << " | Was deleted" << endl;
}

// #5
ostream& operator<<(ostream& out, Player& player) {
  out << "Player[ID=" << player.id << "] \"" << player.username << "\" with password \"" << player.password << "\"";

  return out;
}