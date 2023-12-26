#include "npc.hpp"

NPC::NPC(NPC_type type, int x, int y, const std::string& name) : type(type), x(x), y(y), name(name), _alive(true) {}

const int NPC::get_x() const {
  return x;
}

const int NPC::get_y() const {
  return y;
}

const std::string& NPC::get_name() const {
  return name;
}

const bool NPC::alive() const {
  return _alive;
}

void NPC::notify_killed(const NPC& defender) const {
  for (auto& o: observers) {
    o->report_killed(*this, defender);
  }
}

void NPC::attach(std::shared_ptr<Observer> observer) {
  observers.push_back(observer);
}

bool NPC::near(const std::shared_ptr<NPC>& enemy, int distance) const {
  return std::pow(x - enemy->x, 2) + std::pow(y - enemy->y, 2) <= std::pow(distance, 2);
}

std::ostream& operator<<(std::ostream& out, const NPC& npc) {
  return out << npc.name << " {x : " << npc.x << ", y : " << npc.y << "}";
}

int NPC::id = 0;