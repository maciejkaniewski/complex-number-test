# complex-number-test

complex-number-test is a project I realized in the second semester of my studies within the Object Oriented Programming course at the Wroclaw University of Technology in the field of Control Engineering and Robotics. The main goal of this task was to model the concept of a complex number, and then the test itself, which will test the user's skills in solving operations consisting of complex numbers. The task was an introduction to issues related to object-oriented programming.

## Table of Contents
- [Features](#features)
- [Setup](#setup)
- [Usage](#usage)
- [Concepts I Learned](#concepts-i-learned)
  
## Features

- Perform the following operations on complex numbers:
  - addition
  - subtraction
  - multiplication
  - division
- Two difficulty levels for the test
- Validate the format of the entered complex number
- Display test results

## Setup
Prerequisites:
* Installed CMake *(minimum VERSION 3.0)*,

Clone repository:

    git clone https://github.com/maciejkaniewski/complex-number-test.git

Create `build` directory and launch `CMake`:

    cd complex-number-test
    mkdir build
    cd build
    cmake ..

Run `make` command and execute the program. Provide the name of the test as the argument:

    make
    ./Complex_Number_Test easy
    ./Complex_Number_test hard

If the test name has not been entered, the following message will be displayed:

    There is no option to specify the type of test.
    The available names are: easy, hard.

If an incorrect test name has been entered, the following message will be displayed:

    Failed to initialize test under the name "easa".

## Usage

After successfully starting the program, the following text appears in the terminal:

    Complex Number Test: easy

    [1/4]

    :? Provide the results of the operation: (2-3i) + (1+2i) =
    Answer: 

The answer must be given in the correct format:

    (real_number+imag_numberi)

Example:

    (3-1i)

Result:

    [1/4]

    :? Provide the results of the operation: (2-3i) + (1+2i) =
    Answer: (3-1i)
    :) Correct answer.

If the number is entered three times in the wrong format, the answer will be considered incorrect:

    [2/4]

    :? Provide the results of the operation: (2+3i) - (3+5i) =
    Answer: (2+i)
    :X Wrong format of a complex number. Attempts left: 2
    Answer: 2-1i
    :X Wrong format of a complex number. Attempts left: 1
    Answer: 11i
    :( All attempts have been used. The answer will be considered incorrect.

If an incorrect answer has been entered, the following message will be displayed:

    [3/4]

    :? Provide the results of the operation: (3+2i) * (5+3i) =
    Answer: (2+8i)
    :( Incorrect answer. The correct result is: (9+19i)

After the test is completed, information about the result will be displayed:

    [4/4]

    :? Provide the results of the operation: (20-4i) / (3+2i) =
    Answer: (4-4i)
    :) Correct answer.

    [Results]

    Correct answers: 2
    Incorrect answers: 2
    Percentage result: 50%

## Concepts I Learned

- Basic functionalities of the C++ language,
- Modeling new concepts using structures,
- Operator overloading,
