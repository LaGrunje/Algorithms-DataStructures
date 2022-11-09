#include <iostream>
#include <deque>
#include <memory>

template<typename ValueType, typename Container =std::deque<ValueType>>
class Stack
{
    public:
        Stack();
        ~Stack();

        Stack(const Stack& other);
        Stack(Stack&& other) noexcept;

        Stack& operator=(const Stack& other) &;
        Stack& operator=(Stack&& other) & noexcept;

        ValueType& top() const;

        bool empty() const;
        size_t size() const;

        void push(const ValueType& value);
        void push(ValueType&& value);

        void pop();

    private:
       size_t size_;

       std::shared_ptr<Container> container;
};

template<typename ValueType, typename Container>
Stack<ValueType, Container>::Stack():
        size_(0),
        container(std::make_shared<Container>()) {}

template<typename ValueType, typename Container>
Stack<ValueType, Container>::~Stack() {};

template<typename ValueType, typename Container>
Stack<ValueType, Container>::Stack(const Stack& other):
        size_(other.size_),
        container(std::make_shared<Container>(*other.container)) {}

template<typename ValueType, typename Container>
Stack<ValueType, Container>::Stack(Stack&& other) noexcept:
    size_(other.size_),
    container(std::move(other.container)) {}

template<typename ValueType, typename Container>
Stack<ValueType, Container>& Stack<ValueType, Container>::operator=(const Stack& other) & {
    if (this == &other)
        return *this;
    container.reset(std::make_shared<Container>(*other.container));
    size_ = other.size_;
    return *this;
}

template<typename ValueType, typename Container>
Stack<ValueType, Container>& Stack<ValueType, Container>::operator=(Stack&& other) & noexcept {
    if (this == &other)
    {
        return *this;
    }
    container.reset(std::move(other.container));
    size_ = other.size_;
    return *this;
}

template<typename ValueType, typename Container>
ValueType& Stack<ValueType, Container>::top() const {
    return container->at(size_ - 1);
}

template<typename ValueType, typename Container>
bool Stack<ValueType, Container>::empty() const {
    return size_ == 0;
}

template<typename ValueType, typename Container>
size_t Stack<ValueType, Container>::size() const {
    return size_;
}

template<typename ValueType, typename Container>
void Stack<ValueType, Container>::push(const ValueType& value) {
    container->push_back(value);
    ++size_;
}

template<typename ValueType, typename Container>
void Stack<ValueType, Container>::push(ValueType&& value) {
    container->push_back(std::move(value));
    ++size_;
}

template<typename ValueType, typename Container>
void Stack<ValueType, Container>::pop() {
    container->pop_back();
    --size_;
}