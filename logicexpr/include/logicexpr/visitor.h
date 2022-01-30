#pragma once
#include <string>
#include <stack>

namespace expr
{
    class IExpression;
    class ExpressionUnary;
    class ExpressionBinary;

    class IExpressionVisitor
    {
    public:
        virtual ~IExpressionVisitor() = default;

        virtual void visit(ExpressionUnary& e) = 0;
        virtual void visit(ExpressionBinary& e) = 0;
    };

    // Only usable from one thread
    class SqlExpressionVisitor : public IExpressionVisitor
    {
    public:
        std::string createWhereStatement(IExpression& e);

        void visit(ExpressionUnary& e) override;
        void visit(ExpressionBinary& e) override;

    private:
        std::stack<std::string> mVisited;
    };
}