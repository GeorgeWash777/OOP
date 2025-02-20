#ifndef ELF_H
#define ELF_H

#include "NPC.h"


class Elf : public NPC {
  public:
    using NPC::NPC;
    ~Elf() override;

    std::string GetType() const override;
    void KillOtherNPC(NPC& other) const override;
};

#endif