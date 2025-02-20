#ifndef FACTORY_H
#define FACTORY_H

#include "NPC.h"
#include <memory>
#include <stdexcept>

class Factory {
public:
    static std::shared_ptr<NPC> CreateNPC(const std::string& type, const std::string& name, double x, double y, double range);
};

#endif