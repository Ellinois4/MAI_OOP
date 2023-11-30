#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

#include "Node.hpp"
#include <memory>

template <typename T, typename Allocator = std::allocator<T>>
class Queue {
public:
    class Iterator;
    using value_type = T;
    using node_pointer = Node<T>*;
    using allocator_type = Allocator;
    using size_type = size_t;
    using reference = T&;
    using const_reference = const T&;

    using Alloc = typename std::allocator_traits<Allocator>::template rebind_alloc<Node<T>>;
    Alloc alloc;
    using AllocTraits = std::allocator_traits<Alloc>;


    node_pointer head = nullptr;
    node_pointer block_ptr = nullptr;
    size_type size = 0;

    Queue();
    Queue(const allocator_type& alloc);
    Queue(const Queue<value_type, allocator_type>& rhs);
    Queue(Queue<value_type, allocator_type>&& rhs) noexcept;
    Queue<value_type, allocator_type>& operator=(const Queue<value_type, allocator_type>& rhs);
    Queue<value_type, allocator_type>& operator=(Queue<value_type, allocator_type>&& rhs) noexcept;
    ~Queue();

    bool operator==(const Queue<value_type, allocator_type>& rhs) const noexcept;
    bool operator!=(const Queue<value_type, allocator_type>& rhs) const noexcept;
    bool empty() const;

    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    size_type get_size() const;
    void pop();
    void push(const_reference value);
    void clear();

    Iterator begin();
    Iterator end();
    const Iterator cbegin() const;
    const Iterator cend() const;

    class Iterator {
    public:
        using difference_type = int;
        using value_type = Queue::value_type;
        using reference = Queue::value_type&;
        using iterator_category = std::bidirectional_iterator_tag;
        
        Iterator(Node<value_type>* ptr);
        reference operator*();
        Iterator& operator=(const Iterator& it);
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        Iterator& operator+=(size_t n);
        Iterator& operator-=(size_t n);
        Iterator operator+(size_t rhs) const;

        bool operator==(const Iterator& it) const;
        bool operator!=(const Iterator& it) const;
        
    private:
        Node<value_type>* current_node_ptr = nullptr;
    };    

};

#include "../src/Queue.cpp"

#endif