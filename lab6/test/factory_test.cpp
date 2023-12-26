#include "gtest/gtest.h"
#include "factory.hpp"

TEST(NPCFactoryTest, CreateNPC) {
  NPCFactory factory;
  bool test = true;
  try {
    std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 2);
    std::shared_ptr<NPC> werewolf = factory.create_NPC(NPC_type::WEREWOLF, 3, 4);
    std::shared_ptr<NPC> robber = factory.create_NPC(NPC_type::ROBBER, 5, 6);
  } catch (...) {
    test = false;
  }
  EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Save) {
  NPCFactory factory;
  set_t s;
  bool test = true;
  try {
    s.insert(factory.create_NPC(NPC_type::BEAR, 1, 2));
    s.insert(factory.create_NPC(NPC_type::WEREWOLF, 3, 4));
    s.insert(factory.create_NPC(NPC_type::ROBBER, 5, 6));
    factory.save(s, "test.txt");
  } catch (...) {
    test = false;
  }
  EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Load) {
  NPCFactory factory;
  set_t s;
  bool test = true;
  try {
    s = factory.load("test.txt");
  } catch (...) {
    test = false;
  }
  EXPECT_TRUE(test);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}