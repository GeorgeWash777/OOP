#ifndef ROBBER_H
#define ROBBER_H

#include "NPC.h"


class Robber : public NPC {
  public:
    using NPC::NPC;
    ~Robber() override;

    std::string GetType() const override;
    void KillOtherNPC(NPC& other) const override;
};

#endif