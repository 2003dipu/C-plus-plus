
#include <iostream>

void questionsFunction()
{

    std::string name;
    std::cout << "What's your name?: ";
    std::getline(std::cin, name);
    std::cout << "Welcome " << name << "\n";
    std::string questions[] =
    {
        "1. What is your mission in life?", "2. Do you really know what you are most interested in?",
        "3. Have you really found out your passion in life? If yes, share with other fellow human being here.",
        "4.Why are you passionate about this?", "5. What do you think about AI?"
    };

    int lengthOfQuestionsArray = sizeof(questions) / sizeof(questions[0]);
    std::cout << "\nWe would be grateful if you answer the following questions to help our research\n";
    std::cout << "To learn more visit our website dipusingha.com \n";
    std::string uanswer;
    std::string storeUanswers[lengthOfQuestionsArray];
    for (int i = 0; i < lengthOfQuestionsArray; i++)
    {
        std::cout << questions[i] << "\n ->: ";
        std::getline(std::cin, uanswer);
        storeUanswers[i] = uanswer;
        std::cout << "\n-----------------------------------------------------\n";
    }
    std::cout << "Here's your story. \n";
    for (int i = 0; i < lengthOfQuestionsArray; i ++)
    {
        std::cout << storeUanswers[i] << "\n";
    }
    
}

int main()
{
    std::cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    questionsFunction();
    std::cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}