#include "../include/World.h"

void World::AddNPC(const std::string& type, const std::string& name, double x, double y, double range) {
    NPC_.push_back(Factory::CreateNPC(type, name, x, y, range));
}

void World::AllNPC() const {
    for (const auto& c : NPC_) {
        std::cout << c->GetType() << " '" << c->Name() << "' ("
            << c->GetPos().x << ", " << c->GetPos().y << ", " << c->GetRange() << ")\n";
    }
}

void World::Serialize(const std::string& filename) const {
    std::ofstream fs(filename);
    for (const auto& c : NPC_) {
        if (c->Alive()) {
            fs << c->GetType() << " " << c->Name() << " "
                << c->GetPos().x << " " << c->GetPos().y << " " << c->GetRange() << "\n";
        }
    }
}

void World::Deserialize(const std::string& filename) {
    std::ifstream fs(filename);
    std::string type, name;
    double x, y, range;
    while (fs >> type >> name >> x >> y >> range) {
        AddNPC(type, name, x, y, range);
    }
}

void World::Engage(Visitor& visitor) {
    visitor.Engage(NPC_);
}