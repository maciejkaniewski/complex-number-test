#include "test_data_base.hh"

// Array with easy questions
static ComplexExpression easy_test[] =
    {
        {{2, -3}, Op_Add, {1, 2}},
        {{2, 3}, Op_Subtract, {3, 5}},
        {{3, 2}, Op_Multiply, {5, 3}},
        {{20, -4}, Op_Divide, {3, 2}},
};

// Array with hard questions
static ComplexExpression hard_test[] =
    {
        {{1.2, 3.8}, Op_Add, {15.6, -6.4}},
        {{1.458, 6.13222}, Op_Subtract, {1.222, 4.99999}},
        {{3.3, 5}, Op_Multiply, {2.88, -9}},
        {{2, -7}, Op_Divide, {0, 3}},
};

void SetTest(TestDataBase *test_data_base, ComplexExpression *test_array, unsigned int number_of_questions)
{
    test_data_base->test_array = test_array;
    test_data_base->number_of_questions = number_of_questions;
    test_data_base->question_index = 0;
}

bool InitializeTest(TestDataBase *test_data_base, const char *test_name)
{
    if (!strcmp(test_name, "easy"))
    {
        SetTest(test_data_base, easy_test, sizeof(easy_test) / sizeof(ComplexExpression));
        return true;
    }

    if (!strcmp(test_name, "hard"))
    {
        SetTest(test_data_base, hard_test, sizeof(hard_test) / sizeof(ComplexExpression));
        return true;
    }
    
    return false;
}

bool GetNextQuestion(TestDataBase *test_data_base, ComplexExpression *expression)
{
    // No more questions in test data base
    if (test_data_base->question_index >= test_data_base->number_of_questions)
    {
        return false;
    }

    *expression = test_data_base->test_array[test_data_base->question_index];
    ++test_data_base->question_index;

    return true;
}