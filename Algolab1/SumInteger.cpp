// Problem: 주어진 정수의 합 구하기
// 국민대학교 과학기술대학 정보보안암호수학과 3학년 20202101 이수현

#include <iostream>
using namespace std;

int main()
{
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int numData, data;
        int sum = 0;

        cin >> numData;

        if ((1 <= numData) && (numData <= 100)) {
            for (int j = 0; j < numData; j++) {
                cin >> data;
                sum += data;
            }
            cout << sum << endl;
        }
        else {
            cout << "Error: 1이상 100이하의 정수를 입력하시오.";
        }
    }

    return 0;
}