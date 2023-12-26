#pragma once

#include <cmath>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

class NPC;

class bear;

class werewolf;

class robber;

using set_t = std::set<std::shared_ptr<NPC>>;

enum NPC_type {
  UNKNOWN = 0,
  BEAR = 1,
  WEREWOLF = 2,
  ROBBER = 3
};

class Observer {
public:
  virtual ~Observer() = default;

  virtual void report_killed(const NPC& attacker, const NPC& defender) = 0;
};

class NPC {
protected:
  NPC_type type;
  int x = 0, y = 0;
  std::string name;
  bool _alive;
  std::vector<std::shared_ptr<Observer>> observers;
  static int id;

  NPC(NPC_type type, int x, int y, const std::string& name);

  virtual ~NPC() = default;

public:
  virtual std::string get_type() = 0;

  const int get_x() const;

  const int get_y() const;

  const std::string& get_name() const;

  const bool alive() const;

  virtual bool accept(std::shared_ptr<NPC> visitor) = 0;

  virtual bool fight(bear& accepter) = 0;

  virtual bool fight(werewolf& accepter) = 0;

  virtual bool fight(robber& accepter) = 0;

  void attach(std::shared_ptr<Observer> observer);

  void notify_killed(const NPC& defender) const;

  bool near(const std::shared_ptr<NPC>& enemy, int distance) const;

  friend std::ostream& operator<<(std::ostream& out, const NPC& npc);
};
