#include "gtest/gtest.h"
#include "factory.hpp"

TEST(werewolfTest, ConstructorAndGetters) {
  werewolf werewolf(1, 2);
  EXPECT_EQ(werewolf.get_x(), 1);
  EXPECT_EQ(werewolf.get_y(), 2);
  EXPECT_TRUE(werewolf.alive());
  EXPECT_EQ(werewolf.get_type(), "werewolf");
}

TEST(werewolfTest, Visitors) {
  NPCFactory factory;
  std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 2);
  std::shared_ptr<NPC> werewolf = factory.create_NPC(NPC_type::WEREWOLF, 3, 4);
  std::shared_ptr<NPC> robber = factory.create_NPC(NPC_type::ROBBER, 5, 6);

  EXPECT_FALSE(werewolf->accept(werewolf));
  EXPECT_FALSE(werewolf->accept(robber));
  EXPECT_TRUE(werewolf->alive());
  EXPECT_TRUE(werewolf->accept(bear));
  EXPECT_FALSE(werewolf->alive());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}