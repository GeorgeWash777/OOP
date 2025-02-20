#ifndef BEAR_H
#define BEAR_H

#include "NPC.h"


class Bear : public NPC {
  public:
    using NPC::NPC;
    ~Bear() override;

    std::string GetType() const override;
    void KillOtherNPC(NPC& other) const override;
};

#endif