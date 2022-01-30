#include "catch2/catch.hpp"
#include "logicexpr/expression.h"
#include "logicexpr/visitor.h"

TEST_CASE("expression visitor", "[api]")
{
    using Ptr = expr::IExpression::Ptr;

    auto visitor = expr::SqlExpressionVisitor{};
    SECTION("equals")
    {
        auto expr = expr::Attribute{"value"} == expr::Attribute{"value"};
        CHECK(visitor.createWhereStatement(*expr) == "WHERE (value == value)");
    }
    SECTION("not equal")
    {
        auto expr = expr::Attribute{"35"} != expr::Attribute{"24"};
        CHECK(visitor.createWhereStatement(*expr) == "WHERE (35 != 24)");
    }
    SECTION("less")
    {
        auto expr = expr::Attribute{"35"} < expr::Attribute{"24"};
        CHECK(visitor.createWhereStatement(*expr) == "WHERE (35 < 24)");
    }
    SECTION("less equal")
    {
        auto expr = expr::Attribute{"35"} <= expr::Attribute{"24"};
        CHECK(visitor.createWhereStatement(*expr) == "WHERE (35 <= 24)");
    }
    SECTION("greater")
    {
        auto expr = expr::Attribute{"35"} > expr::Attribute{"24"};
        CHECK(visitor.createWhereStatement(*expr) == "WHERE (35 > 24)");
    }
    SECTION("greater equal")
    {
        auto expr = expr::Attribute{"35"} >= expr::Attribute{"24"};
        CHECK(visitor.createWhereStatement(*expr) == "WHERE (35 >= 24)");
    }
    SECTION("or")
    {
        auto expr = (expr::Attribute{"a"} == expr::Attribute{"5"})
                    || (expr::Attribute{"b"} == expr::Attribute{"20"});
        CHECK(visitor.createWhereStatement(*expr) == "WHERE ((a == 5) OR (b == 20))");
    }
    SECTION("and")
    {
        auto expr = (expr::Attribute{"a"} == expr::Attribute{"5"})
                    && (expr::Attribute{"b"} == expr::Attribute{"20"});
        CHECK(visitor.createWhereStatement(*expr) == "WHERE ((a == 5) AND (b == 20))");
    }
}
