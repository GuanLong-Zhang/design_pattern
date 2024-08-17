//迭代器模式
//提供一种方法顺序访问一个聚合对象中的各个元素，而不暴露其内部表示
#include <iostream>
#include <vector>

// 迭代器接口
template <typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
};

// 具体迭代器实现
template <typename T>
class ConcreteIterator : public Iterator<T> {
private:
    std::vector<T> data;
    size_t position;

public:
    ConcreteIterator(const std::vector<T>& vec) : data(vec), position(0) {}

    bool hasNext() const override {
        return position < data.size();
    }

    T next() override {
        if (!hasNext()) {
            throw std::out_of_range("No more elements");
        }
        return data[position++];
    }
};

// 聚合对象接口
template <typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() const = 0;
    virtual ~Aggregate() {}
};

// 具体聚合对象实现
template <typename T>
class ConcreteAggregate : public Aggregate<T> {
private:
    std::vector<T> data;

public:
    void add(const T& item) {
        data.push_back(item);
    }

    Iterator<T>* createIterator() const override {
        return new ConcreteIterator<T>(data);
    }
};

//int main() {
//    ConcreteAggregate<int> aggregate;
//    aggregate.add(1);
//    aggregate.add(2);
//    aggregate.add(3);
//
//    Iterator<int>* iter = aggregate.createIterator();
//
//    while (iter->hasNext()) {
//        std::cout << iter->next() << std::endl;
//    }
//
//    delete iter;
//
//    return 0;
//}
