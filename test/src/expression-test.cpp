#include "catch2/catch.hpp"
#include "logicexpr/expr.h"

TEST_CASE("expression visitor", "[api]")
{
    using Ptr = expr::IExpression::Ptr;

    auto equals1 = std::make_shared<expr::ExpressionEquals>(expr::Attribute{"a"}, expr::Attribute{"5"});
    auto equals2 = std::make_shared<expr::ExpressionEquals>(expr::Attribute{"b"}, expr::Attribute{"20"});
    Ptr expr = std::make_shared<expr::ExpressionAnd>(equals1, equals2);

    auto visitor = expr::SqlExpressionVisitor{};
    auto where = visitor.createWhereStatement(*expr);

    CHECK(where == "");
}