#include "gtest/gtest.h"
#include "factory.hpp"

TEST(robberTest, ConstructorAndGetters) {
  robber robber(1, 2);
  EXPECT_EQ(robber.get_x(), 1);
  EXPECT_EQ(robber.get_y(), 2);
  EXPECT_TRUE(robber.alive());
  EXPECT_EQ(robber.get_type(), "robber");
}

TEST(robberTest, Visitors) {
  NPCFactory factory;
  std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 2);
  std::shared_ptr<NPC> werewolf = factory.create_NPC(NPC_type::WEREWOLF, 3, 4);
  std::shared_ptr<NPC> robber = factory.create_NPC(NPC_type::ROBBER, 5, 6);
  std::shared_ptr<NPC> robber_ = factory.create_NPC(NPC_type::ROBBER, 5, 6);

  EXPECT_FALSE(robber->accept(bear));
  EXPECT_TRUE(robber->alive());
  EXPECT_TRUE(robber->accept(werewolf));
  EXPECT_FALSE(robber->alive());
  EXPECT_FALSE(robber_->accept(robber));
  EXPECT_TRUE(robber_->alive());
  remove("battle_stats.txt");
  remove("test.txt");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}