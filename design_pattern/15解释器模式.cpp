//解释器模式
//定义一个语言的文法，并且建立一个解释器去解释该语言的句子
#include <iostream>
#include <string>
#include <unordered_map>

// 抽象表达式类
class Expression {
public:
    virtual ~Expression() {}
    virtual int interpret(std::unordered_map<std::string, int>& context) = 0;
};

// 终结符表达式类
class TerminalExpression : public Expression {
private:
    std::string variable;

public:
    TerminalExpression(std::string var) : variable(var) {}

    int interpret(std::unordered_map<std::string, int>& context) override {
        return context[variable];   //返回value
    }
};

// 非终结符表达式类
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

// 上下文类
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
//    // 创建上下文对象并设置变量值
//    Context* context = new Context;
//    context->setVariable("x", 5);
//    context->setVariable("y", 10);
//    std::unordered_map<std::string, int> temp = context->getVariables();
//
//    // 构建表达式树：x + y
//    Expression* expression = new AddExpression(new TerminalExpression("x"), new TerminalExpression("y"));
//
//    // 解释表达式并输出结果
//    int result = expression->interpret(temp);
//    std::cout << "Result: " << result << std::endl;
//
//    // 释放表达式对象
//    delete expression;
//    delete context;
//
//    return 0;
//}
