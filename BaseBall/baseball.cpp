#include <string>
#include <stdexcept>

using namespace std;

struct Result
{
    bool solved;
    int strike;
    int balls;
};

class Baseball
{
public:
    Baseball(string question)
    {
        question_ = question;
    }

    bool isDuplicatedNumber(std::string guessNumber)
    {
        return guessNumber[0] == guessNumber[1] ||
            guessNumber[0] == guessNumber[2] ||
            guessNumber[1] == guessNumber[2];
    }

    bool isIncludeChar(std::string guessNumber)
    {
        for (auto ch : guessNumber)
        {
            if (ch >= '0' && ch <= '9')
            {
                return true;
            }
        }
    }

    void assertIllegalArguments(std::string guessNumber)
    {
        if (guessNumber == "")
        {
            throw std::invalid_argument("���� �־����.");
        }
        if (guessNumber.length() != 3)
        {
            throw std::invalid_argument("�ڸ��� ����.");
        }
        if (isIncludeChar(guessNumber))
        {
            throw std::invalid_argument("�ڸ��� ����.");
        }
        if (isDuplicatedNumber(guessNumber))
        {
            throw std::invalid_argument("�ߺ��� ����.");
        }
    }

    Result guess(std::string guessNumber)
    {
        assertIllegalArguments(guessNumber);
        if (guessNumber == question_)
        {
            return { true, 3, 0 };
        }

        return { false, 0, 0 };
    }

private:
    string question_;
};