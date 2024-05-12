#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

enum enQlevel
{
    easy = 1,
    mid = 2,
    hard = 3,
    Levelmix = 4
};

enum enOperationType
{
    add = 1,
    sub = 2,
    mult = 3,
    divid = 4,
    OpTypeMix = 5
};

enum enFinalResult
{
    pass = 1,
    fail = 2
};

struct stQuizOption
{
    short QuestionsNumber;
    enQlevel QuestionLevel;
    enOperationType OpType;
};

struct strQuizData
{
    short Number1;
    short Number2;
    enOperationType OpType;
    short UserAnswer;
    short CorrectAnswer;
    bool checkAnswer;
};
// clear the screen And return to the main color (black):
void RestScreen()
{
    // clear the screen
    system("cls");
    // return the color to black color:
    system("color 0F");
}

void setAnswerScreenColor(enFinalResult result)
{
    switch (result)
    {
    case enFinalResult::pass:
        system("color 2F"); // turn screen to Green
        break;

    case enFinalResult::fail:
        system("color 4F"); // turn screen to Red
        cout << "\a";
        break;
    }
}

// get random number in range:
int RandomNumber(int from, int to)
{
    int random = rand() % (to - from + 1) + from;

    return random;
};

// ask the user how many question he want to answer:
short ReadHowManyQuestion()
{
    short QNumber = 0;

    cout << "how many question do you want to answer ? " << endl;
    cin >> QNumber;

    return QNumber;
};

enQlevel ReadQuestionLevel()
{
    short QLevel;

    do
    {
        cout << "enter question level:  [1]:easy , [2]:mid , [3]:hard , [4]:mix ? " << endl;
        cin >> QLevel;

    } while (QLevel < 0 || QLevel > 4);

    return (enQlevel)QLevel;
}

enOperationType ReadOperationType()
{
    short OpType;

    do
    {
        cout << "enter operation type: [1]:add , [2]:sub , [3]:mult , [4]:div , [5]:mix ?\n";
        cin >> OpType;

    } while (OpType < 0 || OpType > 5);

    return (enOperationType)OpType;
}

stQuizOption FillQuizOption()
{
    stQuizOption QuizOptin;
    QuizOptin.QuestionsNumber = ReadHowManyQuestion();
    QuizOptin.OpType = ReadOperationType();
    QuizOptin.QuestionLevel = ReadQuestionLevel();
    return QuizOptin;
}

enOperationType MixOpType(enOperationType OpType)
{

    enOperationType arrOpType[5] = {add, sub, mult, divid};

    int index = RandomNumber(0, 4);

    return arrOpType[index];
}

enOperationType OpType(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::add:
        return enOperationType::add;
        break;

    case enOperationType::sub:
        return enOperationType::sub;
        break;

    case enOperationType::mult:
        return enOperationType::mult;
        break;

    case enOperationType::divid:
        return enOperationType::divid;
        break;

    default:
        return MixOpType(OpType);
        break;
    }
}

short NumberForMixLevel()
{
    int arrMixRandomNumbers[3] = {
        RandomNumber(1, 10),
        RandomNumber(10, 100),
    };

    short index = RandomNumber(0, 1);

    return arrMixRandomNumbers[index];
};

strQuizData DifficultyLevel(stQuizOption quizOption)
{

    strQuizData QuizData;

    switch (quizOption.QuestionLevel)
    {
    case enQlevel::easy:
        QuizData.Number1 = RandomNumber(1, 10);
        QuizData.Number2 = RandomNumber(1, 10);
        QuizData.OpType = OpType(quizOption.OpType);
        break;
    case enQlevel::mid:
        QuizData.Number1 = RandomNumber(1, 10);
        QuizData.Number2 = RandomNumber(10, 100);
        QuizData.OpType = OpType(quizOption.OpType);
        break;
    case enQlevel::hard:
        QuizData.Number1 = RandomNumber(10, 100);
        QuizData.Number2 = RandomNumber(10, 100);
        QuizData.OpType = OpType(quizOption.OpType);
        break;
    default:
        QuizData.Number1 = NumberForMixLevel();
        QuizData.Number2 = NumberForMixLevel();
        QuizData.OpType = OpType(quizOption.OpType);
        break;
    }
    return QuizData;
}

strQuizData FillQuizData(stQuizOption QuizOption)
{
    strQuizData quizData = DifficultyLevel(QuizOption);

    return quizData;
}

char CheckOperationType(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::add:
        return '+';
        break;
    case enOperationType::sub:
        return '-';
        break;
    case enOperationType::mult:
        return '*';
        break;
    case enOperationType::divid:
        return '/';
        break;
    default:
        return 'x';
        break;
    };
}

void ShowQuizzQues(strQuizData QuizData, stQuizOption QuizOption, int Qnumber)
{

    cout << "\nQuestion [" << Qnumber + 1 << "/" << QuizOption.QuestionsNumber << "]" << endl;
    cout << QuizData.Number1 << endl;
    cout << QuizData.Number2 << "    " << CheckOperationType(QuizData.OpType);
    cout << "\n_______\n";
};

short ReadPlayerAsnwer()
{
    int Answer;

    cin >> Answer;

    return Answer;
}

short GetCorrectAnswer(short number1, short number2, enOperationType OpType)
{

    switch (OpType)
    {
    case enOperationType::add:
        return number1 + number2;
        break;
    case enOperationType::sub:
        return number1 - number2;
        break;
    case enOperationType::mult:
        return number1 * number2;
        break;
    case enOperationType::divid:
        return number1 / number2;
        break;
    default:
        return -1;
        break;
    }
};

bool CheckTheAnswer(short PlayerAnswer, short correctAnswer)
{
    return PlayerAnswer == correctAnswer;
}

void showAnswerResult(bool CheckAnswer, short RightAnswer)
{
    if (CheckAnswer)
    {
        cout << "Right Answer :)" << endl;
    }
    else
    {
        cout << "Wrong Answer :(";

        cout << "\nThe Right Answer Is: " << RightAnswer << endl;
    }
}

string FinalResult(short WrongA, short RightA)
{
    if (WrongA > RightA)
    {
        return "Fail";
    }
    else
    {
        return "Pass";
    };
};

string ShowQustionType(enQlevel Qlevel)
{
    switch (Qlevel)
    {
    case enQlevel::easy:
        return "Easy";
        break;

    case enQlevel::mid:
        return "Mid";
        break;

    case enQlevel::hard:
        return "Hard";
        break;

    default:
        return "Mix";
        break;
    };
};

string ShowOperationChoice(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::add:
        return "ADDITION (+)";
        break;

    case enOperationType::divid:
        return "DIVIDED (/)";
        break;

    case enOperationType::mult:
        return "MULTIPLICATION (*)";
        break;

    default:
        return "Mix (+ , * , / , -)";
        break;
    };
}

void ShowFinalResult(stQuizOption QuizOption, short WrongAnswer, short RightAnswers)
{

    cout << "\n______________________________________________\n";
    cout << "Final Result Is " << FinalResult(WrongAnswer, RightAnswers) << endl;
    cout << "\n______________________________________________\n";
    cout << "number of question     : " << QuizOption.QuestionsNumber << endl;
    cout << "question level         : " << ShowQustionType(QuizOption.QuestionLevel) << endl;
    cout << "operation type         : " << ShowOperationChoice(QuizOption.OpType) << endl;
    cout << "number of wronge answer: " << WrongAnswer << endl;
    cout << "number of right answer : " << RightAnswers << endl;
    cout << "\n______________________________________________\n";
}

void PlayGame()
{
    stQuizOption QuizOption = FillQuizOption();

    short NumberWrongAnswer = 0,
          NumberRightAnswer = 0,
          CorrectAnswer = 0,
          PlayerAnswer = 0;

    for (short i = 0; i < QuizOption.QuestionsNumber; i++)
    {
        strQuizData QuizData = FillQuizData(QuizOption);

        ShowQuizzQues(QuizData, QuizOption, i);

        PlayerAnswer = ReadPlayerAsnwer();

        CorrectAnswer = GetCorrectAnswer(QuizData.Number1, QuizData.Number2, QuizData.OpType);

        showAnswerResult(CheckTheAnswer(PlayerAnswer, CorrectAnswer), CorrectAnswer);

        if (CheckTheAnswer(PlayerAnswer, CorrectAnswer))
        {
            NumberRightAnswer++;
            setAnswerScreenColor(enFinalResult::pass);
        }
        else
        {
            NumberWrongAnswer++;
            setAnswerScreenColor(enFinalResult::fail);
        }
    };

    ShowFinalResult(QuizOption, NumberWrongAnswer, NumberRightAnswer);
}

void StartGame()
{
    char PlayAgain = 'y';

    do
    {
        RestScreen();

        PlayGame();

        cout << "\nDo you want to play again? Y/N? \n";
        cin >> PlayAgain;

    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}

int main()
{

    // Seeds the random number generator in C++, called only once

    srand((unsigned)time(NULL));

    StartGame();

    return 0;
};