#include "complex_expression.hh"

ComplexNumber Calculate(ComplexExpression expression)
{
    ComplexNumber result;

    switch (expression.op)
    {
    case Op_Add:

        result = expression.first_component + expression.second_component;
        break;

    case Op_Subtract:

        result = expression.first_component - expression.second_component;
        break;

    case Op_Multiply:

        result = expression.first_component * expression.second_component;
        break;

    case Op_Divide:

        result = expression.first_component / expression.second_component;
        break;
    }

    return result;
}

bool CheckAnswer(ComplexExpression expression, ComplexNumber answer)
{
    ComplexNumber correct = Calculate(expression);
    return ((std::abs(correct.real - answer.real) < 0.01) && (std::abs(correct.imag - answer.imag) < 0.01));
}

std::ostream &operator<<(std::ostream &output, const ComplexExpression &expression)
{
    output << expression.first_component << " ";

    switch (expression.op)
    {
    case Op_Add:

        output << "+";
        break;

    case Op_Subtract:

        output << "-";
        break;

    case Op_Multiply:

        output << "*";
        break;

    case Op_Divide:

        output << "/";
        break;
    }

    output << " " << expression.second_component;
    return output;
}

std::istream &operator>>(std::istream &input, ComplexExpression &expression)
{
    char sign;

    input >> expression.first_component;
    input >> sign;

    switch (sign)
    {
    case '+':

        expression.op = Op_Add;
        break;

    case '-':

        expression.op = Op_Subtract;
        break;

    case '*':

        expression.op = Op_Multiply;
        break;

    case '/':

        expression.op = Op_Divide;
        break;
    }

    input >> expression.second_component;
    return input;
}