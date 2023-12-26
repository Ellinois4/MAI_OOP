#include "gtest/gtest.h"
#include "factory.hpp"

TEST(NPCTest, Getters) {
  NPCFactory factory;
  std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 2);
  std::shared_ptr<NPC> werewolf = factory.create_NPC(NPC_type::WEREWOLF, 3, 4);
  std::shared_ptr<NPC> robber = factory.create_NPC(NPC_type::ROBBER, 5, 6);

  EXPECT_EQ(bear->get_type(), "bear");
  EXPECT_EQ(werewolf->get_type(), "werewolf");
  EXPECT_EQ(robber->get_type(), "robber");

  EXPECT_TRUE(bear->alive());
  EXPECT_TRUE(werewolf->alive());
  EXPECT_TRUE(robber->alive());

  EXPECT_EQ(bear->get_x(), 1);
  EXPECT_EQ(werewolf->get_x(), 3);
  EXPECT_EQ(robber->get_x(), 5);
  EXPECT_EQ(bear->get_y(), 2);
  EXPECT_EQ(werewolf->get_y(), 4);
  EXPECT_EQ(robber->get_y(), 6);
}

TEST(NPCTest, Near) {
  NPCFactory factory;
  std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 1);
  std::shared_ptr<NPC> werewolf = factory.create_NPC(NPC_type::WEREWOLF, 50, 1);
  std::shared_ptr<NPC> robber = factory.create_NPC(NPC_type::ROBBER, 100, 1);

  EXPECT_FALSE(bear->near(werewolf, 10));
  EXPECT_TRUE(bear->near(werewolf, 60));
  EXPECT_FALSE(bear->near(robber, 90));
  EXPECT_TRUE(bear->near(robber, 110));
}

TEST(NPCTest, Attach) {
  NPCFactory factory;
  std::shared_ptr<NPC> bear = factory.create_NPC(NPC_type::BEAR, 1, 1);
  std::shared_ptr<Observer> console_observer, file_observer;
  console_observer = std::make_shared<ConsoleObserver>();
  file_observer = std::make_shared<FileObserver>();
  bool test = true;
  try {
    bear->attach(console_observer);
    bear->attach(file_observer);
  } catch (...) {
    test = false;
  }
  EXPECT_TRUE(test);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}