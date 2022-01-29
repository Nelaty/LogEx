#pragma once

#include <memory>
#include <string>

namespace expr
{
    struct Attribute
    {
        std::string value;
    };

    class IExpression;
    class ExpressionEquals;
    class ExpressionAnd;

    class IExpressionVisitor
    {
    public:
        virtual ~IExpressionVisitor() = default;

        virtual void visit(IExpression& e) = 0;
        virtual void visit(ExpressionEquals& e) = 0;
        virtual void visit(ExpressionAnd& e) = 0;
    };

    class IExpression
    {
    public:
        using Ptr = std::shared_ptr<IExpression>;

        virtual ~IExpression() = default;
        virtual void evaluate(IExpressionVisitor& visitor) = 0;
    };

    class ExpressionEquals : public IExpression
    {
    public:
        ExpressionEquals(const Attribute& left, const Attribute& right)
            : mLeft(left)
            , mRight(right)
        {}

        void evaluate(IExpressionVisitor& visitor) override
        {
            visitor.visit(*this);
        }

        const Attribute& left() const { return mLeft; }
        const Attribute& right() const { return mRight; }

    private:
        Attribute mLeft;
        Attribute mRight;
    };

    class ExpressionAnd : public IExpression
    {
    public:
        using Ptr = typename IExpression::Ptr;

        ExpressionAnd(const Ptr& left, const Ptr& right)
            : mLeft(left)
            , mRight(right)
        {}

        void evaluate(IExpressionVisitor& visitor) override
        {
            visitor.visit(*this);
        }

        const Ptr& left() { return mLeft; }
        const Ptr& right() { return mRight; }

    private:
        Ptr mLeft;
        Ptr mRight;
    };

    // Only usable from one thread
    class SqlExpressionVisitor : virtual IExpressionVisitor
    {
    public:
        std::string createWhereStatement(const IExpression& e){
            mWhereStatement.clear();

            return mWhereStatement;
        }

        void visit(IExpression& e) override
        {

        }
        void visit(ExpressionEquals& e) override
        {

        }
        void visit(ExpressionAnd& e) override
        {

        }

    private:
        std::string mWhereStatement;
    };
}
