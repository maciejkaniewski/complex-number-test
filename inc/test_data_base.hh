#ifndef TEST_DATA_BASE_HH
#define TEST_DATA_BASE_HH

#include "complex_expression.hh"
#include <string.h>

struct TestDataBase
{
    ComplexExpression *test_array;
    unsigned int number_of_questions;
    unsigned int question_index;
};

/**
 * @brief Set the test
 *
 * @param test_data_base pointer to a variable representing the test base
 * @param test_array pointer to an array containing arithmetic expressions
 * @param number_of_questions number of questions in the test
 */
void SetTest(TestDataBase *test_data_base, ComplexExpression *test_array, unsigned int number_of_questions);

/**
 * @brief Initialize test
 *
 * @param test_data_base pointer to a variable representing the test base
 * @param test_name name of the selected test
 * @return true successful initialization
 * @return false initialization failed
 */
bool InitializeTest(TestDataBase *test_data_base, const char *test_name);

/**
 * @brief Get the next question from test data base
 *
 * @param test_data_base pointer to a variable representing the test base
 * @param expression
 * @return true sucessful opeartion
 * @return false operation failed
 */
bool GetNextQuestion(TestDataBase *test_data_base, ComplexExpression *expression);

#endif // TEST_DATA_BASE_HH