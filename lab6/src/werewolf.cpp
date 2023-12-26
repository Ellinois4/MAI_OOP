#include "werewolf.hpp"

werewolf::werewolf(int x, int y) : NPC(NPC_type::WEREWOLF, x, y, "werewolf_" + std::to_string(id++)) {}

std::string werewolf::get_type() {
  return "werewolf";
}

bool werewolf::accept(std::shared_ptr<NPC> visitor) {
  if (visitor->fight(*this)) {
    this->_alive = false;
    return true;
  }
  return false;
}

bool werewolf::fight(bear& accepter) {
  return false;
}

bool werewolf::fight(werewolf& accepter) {
  return false;
}

bool werewolf::fight(robber& accepter) {
  notify_killed(accepter);
  return true;
}