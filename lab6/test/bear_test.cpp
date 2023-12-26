#include "gtest/gtest.h"
#include "factory.hpp"

TEST(bearTest, ConstructorAndGetters) {
  bear bear(1, 2);
  EXPECT_EQ(bear.get_x(), 1);
  EXPECT_EQ(bear.get_y(), 2);
  EXPECT_TRUE(bear.alive());
  EXPECT_EQ(bear.get_type(), "bear");
}

TEST(bearTest, Visitors) {
  NPCFactory factory;
  std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 2);
  std::shared_ptr<NPC> werewolf = factory.create_NPC(NPC_type::WEREWOLF, 3, 4);
  std::shared_ptr<NPC> robber = factory.create_NPC(NPC_type::ROBBER, 5, 6);

  EXPECT_FALSE(bear->accept(bear));
  EXPECT_FALSE(bear->accept(werewolf));
  EXPECT_TRUE(bear->accept(robber));
  EXPECT_FALSE(bear->alive());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}