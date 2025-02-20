#ifndef NPC_H
#define NPC_H

#include <memory>
#include <string>

struct position {
    double x;
    double y;
};

class NPC {
  protected:
    position pos;
    std::string name;
    bool alive = true;
    double range;

  public:
    NPC(std::string name, double x, double y, double range);
    std::string Name() const noexcept;
    bool Alive() const noexcept;
    position GetPos() const noexcept;
    double GetRange() const noexcept;

    virtual std::string GetType() const = 0;

    void KillThisNPC();
    virtual void KillOtherNPC(NPC& other) const = 0;
    virtual ~NPC() = default;
};
#endif