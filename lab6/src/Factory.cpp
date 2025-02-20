#include "../include/Factory.h"
#include "../include/Bear.h"
#include "../include/Elf.h"
#include "../include/Robber.h"

std::shared_ptr<NPC> Factory::CreateNPC(const std::string& type, const std::string& name, double x, double y, double range) {
    if (type == "Bear") {
        return std::make_shared<Bear>(name, x, y, range);
    }
    if (type == "Elf") {
        return std::make_shared<Elf>(name, x, y, range);
    }
    if (type == "Robber") {
        return std::make_shared<Robber>(name, x, y, range);
    }
}