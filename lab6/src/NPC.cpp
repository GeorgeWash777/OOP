#include "../include/NPC.h"
#include <stdexcept>

NPC::NPC(std::string name, double x, double y, double range) {
  if (x < 0 || x > 500 || y < 0 || y > 500) {
    throw std::out_of_range("Map must be 500x500, coords must be is not negative\n");
  }
  this->name = name;
  this->pos = {x, y};
  this->range = range;
}

std::string NPC::Name() const noexcept{
  return this->name;
}

bool NPC::Alive() const noexcept{
  return this->alive;
}

position NPC::GetPos() const noexcept{
  return this->pos;
}

double NPC::GetRange() const noexcept {
  return this->range;
}

void NPC::KillThisNPC() {
  this->alive = false;
}
