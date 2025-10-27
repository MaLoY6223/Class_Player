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

    int arefmetic;

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
        cout << "Очки за последие " << matchesCount << " матчей: ";
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
            cout << "Средняя арифметическая: " << calculateAverageScore() << endl;
        }
    }

    double getAverageScore() const 
    {
        return calculateAverageScore(); 
    }

    bool compareByAverage(const Player& a, const Player& b)
    {
        return a.getAverageScore() > b.getAverageScore();
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

    int* matchScores = new int[matchCount];
    for (int i = 0; i < matchCount; ++i) 
    {
        cout << "Очки за матч " << i + 1 << ": ";
        cin >> matchScores[i];
    }

    Player p1("qwerty", "asdfg", 16, "zxc", matchCount);
    p1.setScores(matchScores, matchCount);
    p1.printInfo();

    Player p2("asdfg", "qwert", 15, "zc", matchCount);
    p2.setScores(matchScores, matchCount);
    p2.printInfo();

    Player p3("fdsvfvdfv", "asdscc", 14, "xc", matchCount);
    p3.setScores(matchScores, matchCount);
    p3.printInfo();

    delete[] matchScores;

    return 0;
}
