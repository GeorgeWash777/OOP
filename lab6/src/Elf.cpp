#include "../include/Elf.h"
#include <math.h>

Elf::~Elf() = default;

std::string Elf::GetType() const {
  return "Elf";
}

void Elf::KillOtherNPC(NPC& other) const {
  position othPos = other.GetPos();
  position thPos = this->GetPos();
  double length = 0;
  length = sqrt(pow(othPos.x - thPos.x , 2) + pow(othPos.y - thPos.y, 2));

  if (this->range >= length && other.GetType() == "Robber") {
    other.KillThisNPC();
  }
}