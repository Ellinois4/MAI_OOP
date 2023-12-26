#pragma once

#include "bear.hpp"
#include "werewolf.hpp"
#include "npc.hpp"

class robber : public NPC {
public:
  robber(int x, int y);

  std::string get_type() override;

  bool accept(std::shared_ptr<NPC> visitor) override;

  bool fight(bear& accepter) override;

  bool fight(werewolf& accepter) override;

  bool fight(robber& accepter) override;
};
