#include "catch2/catch.hpp"
#include "logicexpr/expression.h"
#include "logicexpr/visitor.h"

expr::IExpression::Ptr operator==(const expr::Attribute& lhs, const expr::Attribute& rhs)
{
    return std::make_shared<expr::ExpressionBinary>(
            std::make_shared<expr::ExpressionUnary>(lhs),
            std::make_shared<expr::ExpressionUnary>(rhs),
            expr::BinaryOpType::EQUALS);
}

expr::IExpression::Ptr operator&&(const expr::IExpression::Ptr& lhs, const expr::IExpression::Ptr& rhs)
{
    return std::make_shared<expr::ExpressionBinary>(lhs, rhs, expr::BinaryOpType::LOGICAL_AND);
}

expr::IExpression::Ptr operator||(const expr::IExpression::Ptr& lhs, const expr::IExpression::Ptr& rhs)
{
    return std::make_shared<expr::ExpressionBinary>(lhs, rhs, expr::BinaryOpType::LOGICAL_OR);
}


TEST_CASE("expression visitor", "[api]")
{
    using Ptr = expr::IExpression::Ptr;

    auto visitor = expr::SqlExpressionVisitor{};
    SECTION("equals")
    {
        auto expr = expr::Attribute{"value"} == expr::Attribute{"value"};
        CHECK(visitor.createWhereStatement(*expr) == "(value == value)");
    }
    SECTION("or")
    {
        auto expr = (expr::Attribute{"a"} == expr::Attribute{"5"})
                    || (expr::Attribute{"b"} == expr::Attribute{"20"});
        CHECK(visitor.createWhereStatement(*expr) == "((a == 5) OR (b == 20))");
    }
    SECTION("and")
    {
        auto expr = (expr::Attribute{"a"} == expr::Attribute{"5"})
                    && (expr::Attribute{"b"} == expr::Attribute{"20"});
        CHECK(visitor.createWhereStatement(*expr) == "((a == 5) AND (b == 20))");
    }
}
