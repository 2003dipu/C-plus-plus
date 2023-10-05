// Quiz Game in C++
#include <iostream>
#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine and std::chrono

int main()
{
    std::cout << "\n                                                        \n";
    std::cout << "------------------------------------------------------------\n\n";
    std::cout << "Welcome to QUIZ Game in C++ \n";
    std::string questions[] = {"1. What year was C++ creatd?: ",     // index0         // 1D array because it has only one row
                               "2. Who invented C++?: ",             // index1
                               "3. What is the predecessor of C++",  // index2
                               "4. Is the Earth flat?: ",            // index3
                               "5. Who are you ?: ",                 // index4
                               "6. What is AI?: ",                   // index5
                               "5. What is the best advice for success?: " };               // index6  
    std::string options[][4] = { //2D array(because it has multiple rows)
                                // column0                column1               column2                 column3   
                                {"A. 1950"              , "B. 1985"             , "C. 2000",            "D. 1999"},             //row 0
                                {"A. Guido Van Rossum"  , "B. Bjarne Stroutstrp", "C. John Carmack", "D. Bill Gates"},         // row 1
                                {"A. C"                 , "B. C+"               , "C. C--"         , "D. B++"},                // row 2
                                {"A. yes"               , "B. no"               , "C. sometimes"   , "D. What's Earth?"},      // row 3
                                {"A. Software Developer", "B. Alien"            , "C. I don't know", "D. Fellow Human Being"}, // row 4
                                {"A. Alien",           "B. Human Intelligence" ,"C. Artificial Intelligence", "D. Hardware Machine"}, //5
                                {"A. Give up" , "B. ask for help", "C. always try", "D. Be courageous to follow your drems"}
                                };
                    // index0  index1  index2 index3  index4
    char answerKey[] = {'B',    'B',     'A',   'B',    'D',  'C', 'D'}; // 1D array because it has only one row
    int size = sizeof(questions) / sizeof(questions[0]);
    char guess;
    int score = 0;
   
    for (int i = 0; i < size; i++) {
        std::cout << "*******************************\n";
        std::cout << questions[i] << '\n';
        std::cout << "*******************************\n";

        for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++) {
            std::cout << options[i][j] << '\n';
        }

        char guess;
        bool validInput = false;

        while (!validInput) {
            std::cout << "->:";
            std::cin >> guess;
            guess = toupper(guess);

            if (guess == 'A' || guess == 'B' || guess == 'C' || guess == 'D') {
                validInput = true; // Valid input, exit the loop
            } else {
                std::cout << "Invalid input. Please enter A, B, C, or D.\n";
            }
        }

        if (guess == answerKey[i]) {
            std::cout << "CORRECT\n";
            score++;
        } else {
            std::cout << "WRONG!\n";
            std::cout << "Answer: " << answerKey[i] << '\n';
        }
    }
	std::cout << "*******************************\n";
	std::cout << "*           RESULTS           *\n";
	std::cout << "*******************************\n";
	std::cout << "CORRECT GUESSES: " << score << '\n';
	std::cout << "# of QUESTIONS: " << size << '\n';
	std::cout << "SCORE: " << (score/(double)size)*100 << "%";
 
    return 0;
}
/*
// use more functions and a class to organize the code

*/
