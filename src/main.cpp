#include <ios>
#include <limits>
#include "test_data_base.hh"
#include "statistics.hh"

int main(int argc, char **argv)
{
    ComplexExpression test_question;
    ComplexNumber user_answer;
    Statistics statistics;
    TestDataBase test_data_base;

    // Initialize user answer complex number = user_answer = {0, 0}
    user_answer.real = 0;
    user_answer.imag = 0;

    // Initialize statistics = statistics = {0, 0}
    statistics.correct_answers = 0;
    statistics.incorrect_answers = 0;

    // Initialize test data base = test_data_base = {nullptr, 0, 0}
    test_data_base.test_array = nullptr;
    test_data_base.number_of_questions = 0;
    test_data_base.question_index = 0;

    int attempt = 3;

    if (argc < 2) // Check whether the type of test has been specified
    {
        std::cout << std::endl;
        std::cout << " There is no option to specify the type of test." << std::endl;
        std::cout << " The available names are: easy, hard." << std::endl;
        std::cout << std::endl;
        return 1;
    }

    if (!InitializeTest(&test_data_base, argv[1]))
    {
        std::cerr << " Failed to initialize test under the name "
                  << "\"" << argv[1] << "\"." << std::endl;
        return 1;
    }

    std::cout << std::endl;
    std::cout << "Complex Number Test: " << argv[1] << std::endl;
    std::cout << std::endl;

    while (GetNextQuestion(&test_data_base, &test_question)) // Main loop
    {
        std::cout << "[" << test_data_base.question_index << "/" << test_data_base.number_of_questions << "]" << std::endl << std::endl;
        std::cout << ":? Provide the results of the operation: ";
        std::cout << test_question << " =" << std::endl;
        std::cout << "   Answer: ";
        std::cin >> user_answer; // Get user answer

        while ((std::cin.fail()) && (attempt >= 1)) // Incorrect answer format
        {
            --attempt;                                                          // Decrease number of attempts
            std::cin.clear();                                                   // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore until next '\n'

            if (attempt == 0) // If all attempts have been used
            {
                std::cerr << ":( All attempts have been used. The answer will be considered incorrect." << std::endl << std::endl;
                statistics.incorrect_answers++; // Count as incorrect answer
            }
            else // Next attempt to input answer in correct format
            {
                std::cerr << ":X Wrong format of a complex number. Attempts left: " << attempt << std::endl;
                std::cout << "   Answer: ";
                std::cin >> user_answer;
            }
        }

        if (attempt) // If all attempts have been used skip this part
        {
            if (CheckAnswer(test_question, user_answer))
            {
                std::cout << ":) Correct answer." << std::endl << std::endl;
                statistics.correct_answers++;
            }
            else
            {
                std::cout << ":( Incorrect answer. The correct result is: " << Calculate(test_question) << std::endl << std::endl;
                statistics.incorrect_answers++;
            }
        }
        attempt = 3; // Reset attempt number
    }

    DisplayTestResults(statistics);

    return 0;
}