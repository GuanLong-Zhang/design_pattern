//������ģʽ
//�ṩһ�ַ���˳�����һ���ۺ϶����еĸ���Ԫ�أ�������¶���ڲ���ʾ
#include <iostream>
#include <vector>

// �������ӿ�
template <typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
};

// ���������ʵ��
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

// �ۺ϶���ӿ�
template <typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() const = 0;
    virtual ~Aggregate() {}
};

// ����ۺ϶���ʵ��
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
