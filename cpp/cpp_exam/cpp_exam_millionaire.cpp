#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

#define YELLOW "\033[33m"
#define WHITE "\033[37m"
#define BLUE "\033[34m"
#define totalQuestions 15
#define totalAnswers 4

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
    while (questionIndex < totalQuestions)
    {
        if (continuePlaying)
        {

            Question current = questionsList[questionIndex];
            cout << YELLOW << questionIndex + 1 << ". " << current.question << WHITE << endl;
            int correctIndex = getAnswers(current, help);
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
                if (helpCount < 3 && !help)
                {
                    help = true;
                    helpCount++;
                }
                else if (helpCount < 3 && help)
                {
                    cout << setw(26) << setfill('=') << "" << endl;
                    cout << "Hint already taken!" << endl;
                    cout << setw(26) << setfill('=') << "" << endl;
                }
                else
                {
                    cout << setw(26) << setfill('=') << "" << endl;
                    cout << "Sorry! No more hints left." << endl;
                    cout << setw(26) << setfill('=') << "" << endl;
                }
            }
            else if (!isdigit(answer[0]) || answer.length() > 1)
            {
                cout << "Wrong Input! Try Again" << endl;
            }
            else if ((stoi(answer) < 0 || stoi(answer) > totalAnswers))
            {
                cout << "Wrong input. Try again" << endl;
            }
            else if (answerInt == correctIndex)
            {
                if (help)
                    help = false;
                printWinningTable(questionIndex, winningTable);
                questionIndex++;
                if (questionIndex == totalQuestions)
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
            cout << "Congratulations! You've won " << winningTable[questionIndex - 1] << "$" << endl;
            return 0;
        }
    }

    for (int i{}; i < totalQuestions; ++i)
    {
        delete[] questionsList[i].incorrectAnswers;
    }
    delete[] questionsList;
    delete[] winningTable;
    return 0;
}

int getAnswers(Question question, bool help)
{
    string answers[totalAnswers];
    srand(time(nullptr));
    int corretQuestionIndex = rand() % totalAnswers + 0;
    answers[corretQuestionIndex] = question.correctAnswer;
    int index{};
    for (int i{}; i < totalAnswers; ++i)
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
                answers[i] = question.incorrectAnswers[rand() % (totalAnswers - 1) + 0];
                break;
            }
        }
    }
    printAnswers(answers);
    return corretQuestionIndex + 1;
}

void printAnswers(const string answers[])
{
    for (int i{}; i < totalAnswers; ++i)
    {
        cout << i + 1 << ". " << answers[i] << endl;
    }
}

Question *initQuestionsData()
{
    Question *questionsList = new Question[totalQuestions];
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
    int *table = new int[totalQuestions]{
        100,
        200,
        300,
        500,
        1000,
        2000,
        4000,
        8000,
        16000,
        32000,
        64000,
        125000,
        500000,
        1000000};
    return table;
}

void printWinningTable(int index, int *table)
{
    for (int i{totalQuestions - 1}; i >= 0; --i)
    {
        if (i == index)
            cout << BLUE << table[i] << WHITE << endl;
        else
            cout << table[i] << endl;
    }
    cout << endl;
}
