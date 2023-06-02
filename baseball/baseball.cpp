#include <stdexcept>
#include <string>

using namespace std;

class Result
{
public:
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	Baseball(string question) : question(question)
	{
	}

	Result guess(string guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
			return { true, 3, 0 };

		Result result;
		result.solved = false;
		result.strikes = getStrikesCount(guessNumber);
		result.balls = getBallCount(guessNumber);

		return result;
	}

private:
	bool isDuplicatedNumber(string guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	bool isCharIncluded(string guessNumber)
	{
		for(char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}

	void assertIllegalArgument(string guessNumber)
	{
		if (guessNumber == "")
		{
			throw invalid_argument("���� �־�� �մϴ�.");
		}
		if (guessNumber.length() != 3)
		{
			throw invalid_argument("�ڸ��� ����");
		}
		if (isCharIncluded(guessNumber))
		{
			throw invalid_argument("���ڷθ� �����Ǿ����� �ʽ��ϴ�");
		}
		if (isDuplicatedNumber(guessNumber))
		{
			throw invalid_argument("���� ���� ������ �ȵ˴ϴ�");
		}
	}

	int getStrikesCount(string guessNumber)
	{
		int result = 0;
		for (int i = 0; i < 3; i++)
		{
			int index = question.find(guessNumber[i]);
			if (index == -1) continue;
			if (index != i) continue;
			result++;
		}
		return result;
	}

	int getBallCount(string guessNumber)
	{
		int result = 0;
		for (int i=0; i < 3;i++)
		{
			int index = question.find(guessNumber[i]);
			if (index == -1) continue;
			if (index == i) continue;
			result++;
		}
		return result;
	}

	string question;
};
