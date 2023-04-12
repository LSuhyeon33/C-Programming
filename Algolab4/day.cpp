// Problem: 요일 계산하기
// 국민대학교 과학기술대학 정보보안암호수학과 3학년 20202101 이수현

// 일요일: 0, 월요일: 1, 화요일: 2, 수요일: 3, 목요일: 4, 금요일: 5, 토요일: 6

#include <iostream>
using namespace std;

int GREGORIAN = 1582;
int dayArry[] = { 0, 1, 2, 3, 4, 5, 6 };    // 요일

// year. 1. 1 요일 계산하기
int startDay(int year) {
    int total = 0, answer = 0;

    for (int i = GREGORIAN; i < year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            total += 366;
        }
        else {
            total += 365;
        }
    }
    answer = (total + 5) % 7;
  
    return dayArry[answer];
}

int getDay(int year, int month, int day) {
    int total_day = 0;
    int answer_day = 0, start_day = 0;
    int month_day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };    // 요일별 마지막 날짜

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        month_day[1] = 29;
    }

    for (int i = 1; i < month; i++) {
        total_day += month_day[i - 1];
    }
    total_day += (day - 1);

    start_day = startDay(year);
    answer_day = (start_day + total_day) % 7;

    return dayArry[answer_day];
}

int main() {
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int y = 0, m = 0, d = 0;
        cin >> y >> m >> d;

        cout << getDay(y, m, d) << endl;
    }
    return 0;
}