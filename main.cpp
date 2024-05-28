#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class Month { January = 1, February, March, April, May, June, July, August, September, October, November, December };

struct Date {
    int day;
    Month month;
    int year;

    Date(int d, Month m, int y) : day(d), month(m), year(y) {}

    bool isValidDate() const {
        static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return year > 0 && static_cast<int>(month) >= 1 && static_cast<int>(month) <= 12 && day >= 1 && day <= daysInMonth[static_cast<int>(month)] && !(month == Month::February && day == 29 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)));
    }

    void printDate() const {
        static const char* monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                                           "September", "October", "November", "December"};
        cout << monthNames[static_cast<int>(month) - 1] << " " << day << ", " << year << endl;
    }

    bool operator<(const Date& other) const {
        return year != other.year ? year < other.year : (month != other.month ? month < other.month : day < other.day);
    }
};

int main() {
    vector<Date> dates = {
        {15, Month::January, 2023},
        {3, Month::February, 2023},
        {25, Month::December, 2022}
    };

    cout << "Original dates:\n";
    for (const auto& date : dates) {
        date.printDate();
    }

    sort(dates.begin(), dates.end());

    cout << "\nSorted dates:\n";
    for (const auto& date : dates) {
        date.printDate();
    }

    return 0;
}
