#include <gtest/gtest.h>
#include "DataStructures/RedBlackTree.hpp"

using namespace DataStructures;


// Helper to create an int pointer
int* make_int_ptr(int val) { return new int(val); }

class RedBlackTreeTest : public ::testing::Test {
protected:
    RedBlackTree<int> tree;
};

// Test that the static color constants are defined
TEST(RedBlackTreeStaticTest, ColorValues) {
    EXPECT_EQ(RedBlackTree<int>::Red, 0);
    EXPECT_EQ(RedBlackTree<int>::Black, 1);
}

// Test Node helper methods
TEST(NodeHelperTest, IsNilAndIsRoot) {
    Node<int> nilNode{RedBlackTree<int>::Black, nullptr, nullptr, nullptr, nullptr};
    EXPECT_TRUE(nilNode.isNil());
    EXPECT_FALSE(nilNode.isRoot()); // has no parent, but value is nullptr

    Node<int> regularNode{RedBlackTree<int>::Red, make_int_ptr(42), nullptr, nullptr, nullptr};
    EXPECT_FALSE(regularNode.isNil());
    EXPECT_TRUE(regularNode.isRoot()); // parent is nullptr
}

// Test insertion and search
TEST_F(RedBlackTreeTest, InsertAndFind) {
    int val = 10;
    tree.insert(&val);

    Node<int> found = tree.find(&val);
    EXPECT_FALSE(found.isNil());   // should find a node
    EXPECT_NE(found.value, nullptr);
    EXPECT_EQ(*(found.value), val);
}

// Test removal
TEST_F(RedBlackTreeTest, RemoveAndFind) {
    int val = 20;
    tree.insert(&val);

    // Verify insertion
    Node<int> found = tree.find(&val);
    EXPECT_FALSE(found.isNil());

    // Remove
    tree.remove(&val);

    // Verify removal
    Node<int> afterRemoval = tree.find(&val);
    EXPECT_TRUE(afterRemoval.isNil()); // assuming find returns a nil node when not found
}

// Test removal by value (not pointer)
TEST_F(RedBlackTreeTest, RemoveByValue) {
    int val = 30;
    tree.insert(val); // overload with value

    // Verify insertion
    Node<int> found = tree.find(&val);
    EXPECT_FALSE(found.isNil());

    // Remove by value
    tree.remove(val);

    // Verify removal
    Node<int> afterRemoval = tree.find(&val);
    EXPECT_TRUE(afterRemoval.isNil());
}

// Test insertion by value (not pointer)
TEST_F(RedBlackTreeTest, InsertByValue) {
    int val = 40;
    tree.insert(val); // overload with value

    Node<int> found = tree.find(&val);
    EXPECT_FALSE(found.isNil());
    EXPECT_EQ(*(found.value), val);
}
