#pragma once

#include <memory>
#include <string>

namespace expr
{
    struct Attribute
    {
        std::string value;
    };

    enum class BinaryOpType
    {
        EQUALS,
        LOGICAL_AND,
        LOGICAL_OR
    };

    class IExpressionVisitor;

    class IExpression
    {
    public:
        using Ptr = std::shared_ptr<IExpression>;

        virtual ~IExpression() = default;
        virtual void evaluate(IExpressionVisitor& visitor) = 0;
    };

    class ExpressionUnary : public IExpression
    {
    public:
        ExpressionUnary(const Attribute& value);

        void evaluate(IExpressionVisitor& visitor) override;

        const Attribute& value() const;

    private:
        Attribute mValue;
    };

    class ExpressionBinary : public IExpression
    {
    public:
        using Ptr = typename IExpression::Ptr;

        ExpressionBinary(const Ptr& left, const Ptr& right, BinaryOpType op);

        void evaluate(IExpressionVisitor& visitor) override;

        BinaryOpType op() const;
        const Ptr& left() const;
        const Ptr& right() const;

    private:
        BinaryOpType mOp;
        Ptr          mLeft;
        Ptr          mRight;
    };
}
