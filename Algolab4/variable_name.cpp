// Problem: 변수이름
// 국민대학교 과학기술대학 정보보안암호수학과 3학년 20202101 이수현

#include <iostream>
using namespace std;

#define MAX     257     // 입력 string 최대 길이

int main() {
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        char variable[MAX];
        bool result = true;
        int index = 0;

        cin >> variable;

        while (variable[index] != 0) {
            if (variable[0] >= '0' && variable[0] <= '9') {    // 첫 문자가 숫자면 false
                result = false;
                break;
            }
            if ((variable[index] >= 'A' && variable[index] <= 'Z') || (variable[index] >= 'a' && variable[index] <= 'z') || (variable[index] >= '0' && variable[index] <= '9') || variable[index] == '_') {    // 문자가 영문자, 숫자, '_'
                index++;
                continue;
            }
            else {
                result = false;
                break;
            }
        }
        (result == true) ? cout << "1" << endl : cout << "0" << endl;
    }
    return 0;
}

/*
#include <cctype>

int main() {
    int numTestCase;
   
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        char variable[MAX];
        bool result = true;
        int index = 0;

        cin >> variable;

        while (variable[index] != 0) {
            if (isdigit(variable[0])) {    // 첫 문자가 숫자면 false
                result = false;
                break;
            }
            if (isalnum(variable[index]) == 0) {    // 문자가 영문자, 숫자가 아님
                if (variable[index] != '_') {     // '_'가 아님
                    result = false;
                    break;
                }
            }
            index++;
        }
        (result == true) ? cout << "1" << endl : cout << "0" << endl;
    }
    return 0;
}
*/
