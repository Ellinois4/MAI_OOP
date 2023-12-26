#include "robber.hpp"

robber::robber(int x, int y) : NPC(NPC_type::ROBBER, x, y, "robber_" + std::to_string(id++)) {}

std::string robber::get_type() {
  return "robber";
}

bool robber::accept(std::shared_ptr<NPC> visitor) {
  if (visitor->fight(*this)) {
    this->_alive = false;
    return true;
  }
  return false;
}

bool robber::fight(bear& accepter) {
  notify_killed(accepter);
  return true;
}

bool robber::fight(werewolf& accepter) {
  return false;
}

bool robber::fight(robber& accepter) {
  return false;
}