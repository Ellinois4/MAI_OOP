#include "bear.hpp"

bear::bear(int x, int y) : NPC(NPC_type::BEAR, x, y, "bear_" + std::to_string(id++)) {}

std::string bear::get_type() {
  return "bear";
}

bool bear::accept(std::shared_ptr<NPC> visitor) {
  if (visitor->fight(*this)) {
    this->_alive = false;
    return true;
  }
  return false;
}

bool bear::fight(bear& accepter) {
  return false;
}

bool bear::fight(werewolf& accepter) {
  notify_killed(accepter);
  return true;
}

bool bear::fight(robber& accepter) {
  return false;
}