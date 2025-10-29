#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

class Player
{
private:
    string name;
    string nickname;
    int age;
    string team;

    int* scores;
    int matchesCount;

public:
    Player(string n, string nick, int a, string t, int mCount)
        : name(n),
        nickname(nick),
        age(a),
        team(t),
        matchesCount(mCount)
    {
        scores = new int[matchesCount];
        for (int i = 0; i < matchesCount; ++i)
        {
            scores[i] = 0;
        }
    }

    Player()
        : name("Неизвестно"),
        nickname("Неизвестно"),
        age(0),
        team("-"),
        scores(nullptr),
        matchesCount(0)
    {}

    void setName(const string& n)
    {
        name = n;
    }

    void setNickname(const string& nick)
    {
        nickname = nick;
    }

    void setAge(int a)
    {
        if (a > 0 && a < 100) age = a;
    }

    void setTeam(const string& t)
    {
        team = t;
    }

    void setScores(int* newScores, int count)
    {
        delete[] scores;
        matchesCount = count;
        scores = new int[matchesCount];
        for (int i = 0; i < matchesCount; ++i)
        {
            scores[i] = newScores[i];
        }
    }

    string getName() const
    {
        return name;
    }

    string getNickname() const
    {
        return nickname;
    }

    int getAge() const
    {
        return age;
    }

    string getTeam() const
    {
        return team;
    }

    int getMatchesCount() const
    {
        return matchesCount;
    }

    int* getScores() const
    {
        return scores;
    }

    void printScores() const
    {
        cout << "Очки за последние " << matchesCount << " матчей: ";
        for (int i = 0; i < matchesCount; i++)
        {
            cout << scores[i] << " ";
        }
        cout << endl;
    }

    double calculateAverageScore() const
    {
        if (matchesCount == 0 || scores == nullptr)
            return 0.0;

        double sum = 0;
        for (int i = 0; i < matchesCount; i++) {
            sum += scores[i];
        }
        return sum / matchesCount;
    }

    void printInfo() const
    {
        cout << "Игрок: " << name << " (\"" << nickname << "\"), "
            << age << " лет, команда: " << team << endl;

        if (matchesCount > 0 && scores != nullptr) {
            cout << "Очки за последние " << matchesCount << " матчей: ";
            for (int i = 0; i < matchesCount; i++) {
                cout << scores[i] << " ";
            }
            cout << endl;
            cout << "Среднее арифметическое: " << calculateAverageScore() << endl;
        }
    }

    double getAverageScore() const
    {
        return calculateAverageScore();
    }

    ~Player()
    {
        delete[] scores;
        cout << "Объект " << name << " " << nickname << " УДАЛЕН." << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int matchCount;
    cout << "Введите количество матчей: ";
    cin >> matchCount;

    Player p1("йцукен", "фывап", 16, "ясчфс", matchCount);
    Player p2("hfnncjurf", "zxc", 15, "gbgb", matchCount);
    Player p3("qwerty", "adsf", 14, "Svdvny", matchCount);

    cout << "Ввод очков для " << p1.getName() << endl;
    int* scores1 = new int[matchCount];
    for (int i = 0; i < matchCount; ++i)
    {
        cout << "Очки за матч " << i + 1 << ": ";
        cin >> scores1[i];
    }
    p1.setScores(scores1, matchCount);

    cout << "Ввод очков для " << p2.getName() << endl;
    int* scores2 = new int[matchCount];
    for (int i = 0; i < matchCount; ++i)
    {
        cout << "Очки за матч " << i + 1 << ": ";
        cin >> scores2[i];
    }
    p2.setScores(scores2, matchCount);

    cout << "Ввод очков для " << p3.getName() << endl;
    int* scores3 = new int[matchCount];
    for (int i = 0; i < matchCount; ++i)
    {
        cout << "Очки за матч " << i + 1 << ": ";
        cin >> scores3[i];
    }
    p3.setScores(scores3, matchCount);

    p1.printInfo();
    p2.printInfo();
    p3.printInfo();

    return 0;
}
