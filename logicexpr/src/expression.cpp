#include "logicexpr/expression.h"
#include "logicexpr/visitor.h"

namespace expr
{
    using Ptr = typename IExpression::Ptr;

    ExpressionUnary::ExpressionUnary(const Attribute& value)
        : mValue(value)
    {
    }

    void ExpressionUnary::evaluate(IExpressionVisitor& visitor)
    {
        visitor.visit(*this);
    }

    const Attribute& ExpressionUnary::value() const
    {
        return mValue;
    }

    ExpressionBinary::ExpressionBinary(const Ptr& left, const Ptr& right, BinaryOpType op)
        : mLeft(left)
        , mRight(right)
        , mOp(op)
    {
    }

    void ExpressionBinary::evaluate(IExpressionVisitor& visitor)
    {
        mRight->evaluate(visitor);
        mLeft->evaluate(visitor);
        visitor.visit(*this);
    }

    BinaryOpType ExpressionBinary::op() const
    {
        return mOp;
    }

    const Ptr& ExpressionBinary::left() const
    {
        return mLeft;
    }

    const Ptr& ExpressionBinary::right() const
    {
        return mRight;
    }
}