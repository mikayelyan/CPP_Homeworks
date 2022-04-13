#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

#define YELLOW "\033[33m"
#define WHITE "\033[37m"
#define BLUE "\033[34m"

struct Question
{
    string question{};
    string correctAnswer;
    string *incorrectAnswers;
};

Question *initQuestionsData();
int *getTable();
int getAnswers(Question, bool);
void printAnswers(const string[]);
void printWinningTable(int, int *);
int *initWinningTable();
int getWinningAmount(int);

int main()
{
    Question *questionsList = initQuestionsData();
    int *winningTable = initWinningTable();
    int questionIndex{};
    bool continuePlaying{true};
    bool help{false};
    int helpCount{};
    while (questionIndex < 15)
    {
        if (continuePlaying)
        {

            Question current = questionsList[questionIndex];
            int correctIndex = getAnswers(current, help);
            cout << YELLOW << questionIndex << ". " << current.question << WHITE << endl;
            if (helpCount < 3)
                cout << BLUE << "Type 'help' for 50/50: " << (3 - helpCount) << " left." << WHITE << endl;
            string answer{};
            cin >> answer;
            transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
            int answerInt{};
            if (answer.length() == 1 && isdigit(answer[0]))
            {
                answerInt = stoi(answer);
            }
            if (answer == "help")
            {
                if (helpCount < 4)
                {
                    help = true;
                    helpCount++;
                }
                else
                    cout << "Sorry! No more hints left." << endl;
            }
            else if (!isdigit(answer[0]) || answer.length() > 1)
            {
                cout << "Wrong Input! Try Again" << endl;
            }
            else if ((stoi(answer) < 0 || stoi(answer) > 4))
            {
                cout << "Wrong input. Try again" << endl;
            }
            else if (answerInt == correctIndex)
            {
                if (help)
                    help = false;
                questionIndex++;
                printWinningTable(questionIndex, winningTable);
                if (questionIndex == 15)
                {
                    cout << "Congratulations! You've won 1000000" << endl;
                    return 0;
                }
                string response{};

                while (response != "yes" && response != "no")
                {
                    cout << "Do you want to continue? (yes / no): " << endl;
                    cin >> response;
                    transform(response.begin(), response.end(), response.begin(), ::tolower);
                    if (response == "no")
                    {
                        continuePlaying = false;
                    }
                    else if (response != "no" && response != "yes")
                    {
                        cout << "wrong input!" << endl;
                    }
                }
            }
            else if (answerInt != correctIndex)
            {
                int winningAmount = questionIndex > 9 ? 32000 : questionIndex > 4 ? 1000
                                                                                    : 0;
                cout << "Game Over" << endl;
                cout << "You've won: " << winningAmount << endl;
                return 0;
            }
        }
        else
        {
            cout << "Congratulations! You've won " << winningTable[questionIndex] << "$" << endl;
            return 0;
        }
    }

    delete[] questionsList;
    delete[] winningTable;
    return 0;
}

int getAnswers(Question question, bool help)
{
    string answers[4];
    srand(time(nullptr));
    int corretQuestionIndex = rand() % 4 + 0;
    answers[corretQuestionIndex] = question.correctAnswer;
    int index{};
    for (int i{}; i < 4; ++i)
    {
        if (i != corretQuestionIndex)
        {
            if (!help)
            {
                answers[i] = question.incorrectAnswers[index];
                index++;
            }
            else
            {
                answers[i] = question.incorrectAnswers[rand() % 3 + 0];
                break;
            }
        }
    }
    printAnswers(answers);
    return corretQuestionIndex + 1;
}

void printAnswers(const string answers[])
{
    for (int i{}; i < 4; ++i)
    {
        cout << i + 1 << ". " << answers[i] << endl;
    }
}

Question *initQuestionsData()
{
    Question *questionsList = new Question[15];
    int listIndex{};
    ifstream data;
    data.open("questions.txt");
    if (data)
    {
        while (!data.eof())
        {
            string line;
            getline(data, line);
            istringstream questionData{line};

            string question{};
            getline(questionData, question, ',');

            string correctAnswer{};
            getline(questionData, correctAnswer, ',');

            string *incorrectAnswers = new string[3];
            int index{0};
            while (!questionData.eof())
            {
                string incorrectAnswer{};
                getline(questionData, incorrectAnswer, ',');
                incorrectAnswers[index] = incorrectAnswer;
                index++;
            }

            questionsList[listIndex] = Question{question, correctAnswer, incorrectAnswers};
            listIndex++;
        }
    }

    return questionsList;
}

int *initWinningTable()
{
    int *table = new int[15];
    table[0] = 100;
    table[1] = 200;
    table[2] = 300;
    table[3] = 500;
    table[4] = 1000;
    table[5] = 2000;
    table[6] = 4000;
    table[7] = 8000;
    table[8] = 16000;
    table[9] = 32000;
    table[10] = 64000;
    table[11] = 125000;
    table[12] = 250000;
    table[13] = 500000;
    table[14] = 1000000;

    return table;
}

void printWinningTable(int index, int *table)
{
    for (int i{14}; i >= 0; --i)
    {
        if (i == index)
            cout << BLUE << table[i] << WHITE << endl;
        else
            cout << table[i] << endl;
    }
    cout << endl;
}
