#include <gtest/gtest.h>
#include <stdexcept>


// Очередь
template <typename T>
class Queue {
public:
    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual ~Queue() = default;
};

// Куча
template <typename T>
class Heap {
public:
    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual ~Heap() = default;
};

// Бинарное дерево
template <typename T>
class BinaryTree {
public:
    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual bool search(const T& value) const = 0;
    virtual ~BinaryTree() = default;
};

template <typename T>
class MockQueue : public Queue<T> {
public:
    void push(const T& value) override {}
    T pop() override { return T(); }
};

template <typename T>
class MockHeap : public Heap<T> {
public:
    void push(const T& value) override {}
    T pop() override { return T(); }
};

template <typename T>
class MockBinaryTree : public BinaryTree<T> {
public:
    void push(const T& value) override {}
    T pop() override { return T(); }
    bool search(const T& value) const override { return false; }
};

// --- Тесты для Queue ---
TEST(QueueTest, PushAndPop) {
    MockQueue<int> q;
    q.push(10);
    EXPECT_EQ(q.pop(), 0); // так как заглушка возвращает 0
}

TEST(QueueTest, MultiplePushPop) {
    MockQueue<int> q;
    q.push(1);
    q.push(2);
    EXPECT_EQ(q.pop(), 0); // заглушка
    EXPECT_EQ(q.pop(), 0); // заглушка
}

// --- Тесты для Heap ---
TEST(HeapTest, PushAndPop) {
    MockHeap<int> h;
    h.push(5);
    EXPECT_EQ(h.pop(), 0); // заглушка
}

TEST(HeapTest, MultipleElements) {
    MockHeap<int> h;
    h.push(3);
    h.push(8);
    EXPECT_EQ(h.pop(), 0); // заглушка
}

// --- Тесты для BinaryTree ---
TEST(BinaryTreeTest, PushSearch) {
    MockBinaryTree<int> bt;
    bt.push(7);
    EXPECT_FALSE(bt.search(7)); // заглушка всегда false
}

TEST(BinaryTreeTest, PopElement) {
    MockBinaryTree<int> bt;
    bt.push(10);
    EXPECT_EQ(bt.pop(), 0); // заглушка
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
