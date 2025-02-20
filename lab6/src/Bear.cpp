#include "../include/Bear.h"
#include <math.h>

Bear::~Bear() = default;

std::string Bear::GetType() const {
  return "Bear";
}

void Bear::KillOtherNPC(NPC& other) const {
  position othPos = other.GetPos();
  position thPos = this->GetPos();
  double length = 0;
  length = sqrt(pow(othPos.x - thPos.x , 2) + pow(othPos.y - thPos.y, 2));

  if (this->range >= length && other.GetType() == "Elf") {
    other.KillThisNPC();
  }
}