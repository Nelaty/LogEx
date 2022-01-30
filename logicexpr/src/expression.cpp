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

    expr::IExpression::Ptr operator==(const expr::Attribute& lhs, const expr::Attribute& rhs)
    {
        return std::make_shared<expr::ExpressionBinary>(
                std::make_shared<expr::ExpressionUnary>(lhs),
                std::make_shared<expr::ExpressionUnary>(rhs),
                expr::BinaryOpType::EQUALS);
    }

    expr::IExpression::Ptr operator!=(const expr::Attribute& lhs, const expr::Attribute& rhs)
    {
        return std::make_shared<expr::ExpressionBinary>(
                std::make_shared<expr::ExpressionUnary>(lhs),
                std::make_shared<expr::ExpressionUnary>(rhs),
                expr::BinaryOpType::NOT_EQUAL);
    }

    expr::IExpression::Ptr operator<(const expr::Attribute& lhs, const expr::Attribute& rhs)
    {
        return std::make_shared<expr::ExpressionBinary>(
                std::make_shared<expr::ExpressionUnary>(lhs),
                std::make_shared<expr::ExpressionUnary>(rhs),
                expr::BinaryOpType::LESS);
    }

    expr::IExpression::Ptr operator<=(const expr::Attribute& lhs, const expr::Attribute& rhs)
    {
        return std::make_shared<expr::ExpressionBinary>(
                std::make_shared<expr::ExpressionUnary>(lhs),
                std::make_shared<expr::ExpressionUnary>(rhs),
                expr::BinaryOpType::LESS_EQUAL);
    }

    expr::IExpression::Ptr operator>(const expr::Attribute& lhs, const expr::Attribute& rhs)
    {
        return std::make_shared<expr::ExpressionBinary>(
                std::make_shared<expr::ExpressionUnary>(lhs),
                std::make_shared<expr::ExpressionUnary>(rhs),
                expr::BinaryOpType::GREATER);
    }

    expr::IExpression::Ptr operator>=(const expr::Attribute& lhs, const expr::Attribute& rhs)
    {
        return std::make_shared<expr::ExpressionBinary>(
                std::make_shared<expr::ExpressionUnary>(lhs),
                std::make_shared<expr::ExpressionUnary>(rhs),
                expr::BinaryOpType::GREATER_EQUAL);
    }

    expr::IExpression::Ptr operator&&(const expr::IExpression::Ptr& lhs, const expr::IExpression::Ptr& rhs)
    {
        return std::make_shared<expr::ExpressionBinary>(lhs, rhs, expr::BinaryOpType::LOGICAL_AND);
    }

    expr::IExpression::Ptr operator||(const expr::IExpression::Ptr& lhs, const expr::IExpression::Ptr& rhs)
    {
        return std::make_shared<expr::ExpressionBinary>(lhs, rhs, expr::BinaryOpType::LOGICAL_OR);
    }
}