#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <iostream>

struct Statistics
{
    double correct_answers;
    double incorrect_answers;
};

/**
 * @brief Display test results
 * 
 * @param statistics 
 */
void DisplayTestResults(Statistics statistics);

#endif // STATISTICS_HH