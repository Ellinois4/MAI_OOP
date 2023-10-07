#include "gtest/gtest.h"
#include "../include/containers/Vector.hpp"
#include "../include/Three.hpp"


TEST(constructor_test, default_constructor_test) {
  Vector<Three> vec; // TESTED

  EXPECT_EQ(vec.get_capacity(), 1);
  EXPECT_EQ(vec.get_size(), 0);
  EXPECT_NO_THROW(vec[0]);
}

TEST(constructor_test, capacity_constructor_test) {
  Vector<Three> vec(100); // TESTED

  EXPECT_EQ(vec.get_capacity(), 100);
  EXPECT_EQ(vec.get_size(), 0);
}

TEST(constructor_test, initializer_constructor_test) {
  Vector<Three> vec{122, 122, 121, 22, 121, 2121}; // TESTED

  EXPECT_EQ(vec.get_capacity(), 6);
  EXPECT_EQ(vec.get_size(), 6);
}

TEST(constructor_test, copy_constructor_test) {
  Vector<Three> vec{1212, 12212, 1212};
  Vector<Three> vec1 = vec; // TESTED

  EXPECT_EQ(vec1.get_size(), 3);
  EXPECT_EQ(vec1.get_capacity(), 3);

  for (size_t i = 0; i < vec.get_size(); ++i) {
    EXPECT_EQ(vec1[i], vec[i]);
  }
}

TEST(constructor_test, move_constructor_test) {
  Vector<Three> vec{1212, 121212, 1211221, 1212122121};

  Vector<Three> vec1 = std::move(vec); // TESTED

  EXPECT_EQ(vec1.get_size(), 4);
  EXPECT_EQ(vec1.get_capacity(), 4);
  EXPECT_EQ(vec1[0], Three{1212});
  EXPECT_EQ(vec1[1], Three{121212});
  EXPECT_EQ(vec1[2], Three{1211221});
  EXPECT_EQ(vec1[3], Three{1212122121});

  EXPECT_EQ(vec.get_size(), 0);
  EXPECT_EQ(vec.get_capacity(), 0);
}

TEST(assignment_operator_test, copy_assignment) {
  Vector<Three> vec{1212, 1, 12121112, 1211111221};
  Vector<Three> vec1;

  vec1 = vec; // TESTED

  EXPECT_EQ(vec1.get_size(), 4);
  EXPECT_EQ(vec1.get_capacity(), 4);

  for (size_t i = 0; i < vec.get_size(); ++i) {
    EXPECT_EQ(vec1[i], vec[i]);
  }

  EXPECT_TRUE(vec == vec1);
}

TEST(assignment_operator_test, move_assignment) {
  Vector<Three> vec{12112, 12122112};
  Vector<Three> vec1;

  vec1 = std::move(vec); // TESTED

  EXPECT_EQ(vec1.get_size(), 2);
  EXPECT_EQ(vec1.get_capacity(), 2);
  EXPECT_EQ(vec1[0], Three{12112});
  EXPECT_EQ(vec1[1], Three{12122112});

  EXPECT_EQ(vec.get_size(), 0);
  EXPECT_EQ(vec.get_capacity(), 0);
}

TEST(get_size_test, empty_vector) {
  Vector<Three> v;
  size_t size = v.get_size(); // TESTED

  EXPECT_EQ(size, 0);
}

TEST(get_size_test, non_empty_vector) {
  Vector<Three> v{1212, 12112, 11111, 12111212, 1122111, 12, 11, 21, 121, 2222};
  size_t size = v.get_size(); // TESTED

  EXPECT_EQ(size, 10);
}

TEST(get_capacity_test, empty_vector) {
  Vector<Three> v;
  size_t capacity = v.get_capacity(); // TESTED

  EXPECT_EQ(capacity, 1);
}

TEST(get_capacity_test, non_empty_vector) {
  Vector<Three> v{1221211, 12122, 1212212, 1211, 1, 2, 1, 212, 1221, 2212};
  size_t capacity = v.get_capacity(); // TESTED

  EXPECT_EQ(capacity, 10);
}

TEST(empty_test, empty_vector) {
  Vector<Three> v;
  bool is_empty = v.empty(); // TESTED

  ASSERT_TRUE(is_empty);
}

TEST(empty_test, non_empty_vector) {
  Vector<Three> v{12211, 111, 21212};
  bool is_empty = v.empty(); // TESTED
  
  ASSERT_FALSE(is_empty);
}

TEST(empty_test, const_empty_vector) {
  const Vector<Three> v;
  bool is_empty = v.empty(); // TESTED

  ASSERT_TRUE(is_empty);
}

TEST(empty_test, const_non_empty_vector) {
  const Vector<Three> v{12121, 121212, 1212212};
  bool is_empty = v.empty(); // TESTED
  
  ASSERT_FALSE(is_empty);
}

TEST(equal_operator_test, equal_vectors) {
  Vector<Three> v{1121, 11212, 1212};
  Vector<Three> v1 = v;
  
  bool is_equal = v1 == v; // TESTED
  EXPECT_TRUE(is_equal);
}

TEST(equal_operator_test, non_equal_vectors_with_non_equal_size) {
  Vector<Three> v{112, 1211, 11212};
  Vector<Three> v1{1212, 112, 122112, 11212, 1121};
  
  bool is_equal = v1 == v; // TESTED
  EXPECT_FALSE(is_equal);
}

TEST(equal_operator_test, non_equal_vectors_with_equal_size) {
  Vector<Three> v{1212, 111, 222};
  Vector<Three> v1{1212, 121, 222};
  
  bool is_equal = v1 == v; // TESTED
  EXPECT_FALSE(is_equal);
}

TEST(non_equal_operator_test, non_equal_vectors_with_equal_size) {
  Vector<Three> v{1212, 111, 222};
  Vector<Three> v1{1212, 121, 222};
  
  bool is_equal = v1 != v; // TESTED
  EXPECT_TRUE(is_equal);
}

TEST(non_equal_operator_test, non_equal_vectors_with_non_equal_size) {
  Vector<Three> v{1212, 111, 222};
  Vector<Three> v1{1212, 111, 222, 1212, 111, 222};
  
  bool is_equal = v1 != v; // TESTED
  EXPECT_TRUE(is_equal);
}

TEST(non_equal_operator_test, equal_vectors) {
  Vector<Three> v{1212, 111, 222};
  Vector<Three> v1 = v;
  
  bool is_equal = v1 != v; // TESTED
  EXPECT_FALSE(is_equal);
}

TEST(resize_test, resize_empty_vector) {
  Vector<Three> v;
  size_t size = 10;
  v.resize(size, Three{1}); // TESTED

  EXPECT_EQ(v.get_capacity(), size);
  EXPECT_EQ(v.get_size(), size);

  for (size_t i = 0; i < v.get_size(); ++i) {
    EXPECT_EQ(v[i], Three{1});
  }
}

TEST(resize_test, non_empty_vector) {
  Vector<Three> v{1212, 111, 222, 1212};
  size_t old_size = v.get_size();
  size_t size = 15;

  v.resize(size, Three{1}); // TESTED

  EXPECT_EQ(v.get_size(), 15);
  EXPECT_EQ(v.get_capacity(), 15);

  EXPECT_EQ(v[0], Three{1212});
  EXPECT_EQ(v[1], Three{111});
  EXPECT_EQ(v[2], Three{222});
  EXPECT_EQ(v[3], Three{1212});

  for (size_t i = old_size; i < v.get_size(); ++i) {
    EXPECT_EQ(v[i], Three{1});
  }
}

TEST(reserve_test, empty_vector) {
  Vector<Three> v;
  size_t capacity = 100;

  v.reserve(capacity); // TESTED

  EXPECT_EQ(v.get_capacity(), capacity);
}

TEST(reserve_test, old_capacity_more_new_capacity) {
  Vector<Three> v(121);
  size_t capacity = 100;

  v.reserve(capacity); // TESTED

  EXPECT_EQ(v.get_capacity(), 121);
}

TEST(pop_back_test, non_empty_vector) {
  Vector<Three> v{121, 212, 222};
  size_t size = v.get_size();

  v.pop_back(); // TESTED

  EXPECT_EQ(size - 1, v.get_size());
  EXPECT_EQ(v[v.get_size() - 1], Three{212});
}

TEST(push_back_test, non_empty_vector) {
  Vector<Three> v{121, 212, 222};
  size_t size = v.get_size();

  v.push_back(Three{21222}); // TESTED

  EXPECT_EQ(v.get_size(), size + 1);
  EXPECT_EQ(v[v.get_size() - 1], Three{21222});
}

TEST(clear_test, empty_vector) {
  Vector<Three> v;
  
  EXPECT_NO_THROW(v.clear()); // TESTED

  EXPECT_EQ(v.get_size(), 0);
  EXPECT_EQ(v.get_capacity(), 1);
}

TEST(clear_test, non_empty_vector) {
  Vector<Three> v{1221, 21212, 2121, 121212};

  EXPECT_NO_THROW(v.clear()); // TESTED

  EXPECT_EQ(v.get_capacity(), 4);
  EXPECT_EQ(v.get_size(), 0);
  EXPECT_THROW(v.at(1), std::range_error);
}

TEST(emplace_back_test, non_empty_vector) {
  Vector<Three> v{1221, 21212, 2121, 121212};
  size_t size = v.get_size();
  size_t capacity = v.get_capacity();

  v.emplace_back("112121212112211212121221"); // TESTED

  EXPECT_EQ(capacity * 2, v.get_capacity());
  EXPECT_EQ(size + 1, v.get_size());
  EXPECT_EQ(v[v.get_size() - 1], Three{"112121212112211212121221"});
}

TEST(get_element_operator_test, non_empty_vector) {
  Vector<Three> v{121221, 121212, 12211, 1212121212};

  Three el0 = v[0]; // TESTED
  Three el1 = v[1]; // 
  Three el2 = v[2]; //  
  Three el3 = v[3]; //

  EXPECT_EQ(el0, Three{121221});
  EXPECT_EQ(el1, Three{121212});
  EXPECT_EQ(el2, Three{12211});
  EXPECT_EQ(el3, Three{1212121212});
}

TEST(at_test, out_of_range_test) {
  Vector<Three> v{1212, 222, 111, 21211212};

  EXPECT_THROW(v.at(5), std::range_error);
}

TEST(at_test, normal_test) {
  Vector<Three> v{121221, 21212, 222, 1212122};

  EXPECT_NO_THROW(v.at(3));
  EXPECT_EQ(v.at(3), Three{"1212122"});
}

TEST(front_test, normal_test) {
  Vector<Three> v{121221, 21212, 222, 1212122};

  EXPECT_EQ(v.front(), Three{"121221"});
}
 
int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}