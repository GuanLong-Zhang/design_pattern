//������ģʽ
//����һ�����Ե��ķ������ҽ���һ��������ȥ���͸����Եľ���
#include <iostream>
#include <string>
#include <unordered_map>

// ������ʽ��
class Expression {
public:
    virtual ~Expression() {}
    virtual int interpret(std::unordered_map<std::string, int>& context) = 0;
};

// �ս�����ʽ��
class TerminalExpression : public Expression {
private:
    std::string variable;

public:
    TerminalExpression(std::string var) : variable(var) {}

    int interpret(std::unordered_map<std::string, int>& context) override {
        return context[variable];   //����value
    }
};

// ���ս�����ʽ��
class AddExpression : public Expression {
private:
    Expression* left;
    Expression* right;

public:
    AddExpression(Expression* l, Expression* r) : left(l), right(r) {}

    int interpret(std::unordered_map<std::string, int>& context) override {
        return left->interpret(context) + right->interpret(context);
    }

    ~AddExpression() {
        delete left;
        delete right;
    }
};

// ��������
class Context {
private:
    std::unordered_map<std::string, int> variables;

public:
    void setVariable(std::string var, int value) {
        variables[var] = value;
    }

    std::unordered_map<std::string, int> getVariables() {
        return variables;
    }

};

//int main() {
//    // ���������Ķ������ñ���ֵ
//    Context* context = new Context;
//    context->setVariable("x", 5);
//    context->setVariable("y", 10);
//    std::unordered_map<std::string, int> temp = context->getVariables();
//
//    // �������ʽ����x + y
//    Expression* expression = new AddExpression(new TerminalExpression("x"), new TerminalExpression("y"));
//
//    // ���ͱ��ʽ��������
//    int result = expression->interpret(temp);
//    std::cout << "Result: " << result << std::endl;
//
//    // �ͷű��ʽ����
//    delete expression;
//    delete context;
//
//    return 0;
//}
