#include "logicexpr/visitor.h"
#include "logicexpr/expression.h"

#include <sstream>


namespace expr
{
    using namespace std::string_literals;

    std::string toString(BinaryOpType op)
    {
        switch(op)
        {
            case BinaryOpType::EQUALS: return "==";
            case BinaryOpType::NOT_EQUAL: return "!=";
            case BinaryOpType::LESS: return "<";
            case BinaryOpType::LESS_EQUAL: return "<=";
            case BinaryOpType::GREATER: return ">";
            case BinaryOpType::GREATER_EQUAL: return ">=";
            case BinaryOpType::LOGICAL_AND: return "AND";
            case BinaryOpType::LOGICAL_OR: return "OR";
        }
        throw std::runtime_error("Unknow BinaryOpType: "s
                                 + std::to_string(static_cast<int>(op)));
    }

    std::string SqlExpressionVisitor::createWhereStatement(IExpression& e)
    {
        e.evaluate(*this);
        auto result = mVisited.top();
        mVisited = {};
        return "WHERE "s + result;
    }

    void SqlExpressionVisitor::visit(ExpressionUnary& e)
    {
        std::ostringstream oss;
        oss << e.value().value;
        mVisited.push(oss.str());
    }

    void SqlExpressionVisitor::visit(ExpressionBinary& e)
    {
        std::ostringstream oss;
        oss << "(" << mVisited.top() << " " << toString(e.op());
        mVisited.pop();
        oss << " " << mVisited.top() << ")";
        mVisited.pop();
        mVisited.push(oss.str());
    }
}