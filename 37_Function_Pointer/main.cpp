//
//  main.cpp
//  37_Function_Pointer
//
//  Created by 세광 on 2021/07/30.
//

#include <iostream>

using namespace std;

bool compare(int a, int b) {
    return a == b;
}

// 함수에 임의의 함수를 가리키는 포인터를 받아서 호출할 수 있음
// 매개변수의 타입과 리턴 타입이 일치한다면 어떤 함수든지 가리킬 수 있음
int arrFnMin(const int arr[], int n, int (*f)(int)) {
    int min = f(arr[0]);
    for (int i = 0; i < n; i++) {
        if (f(arr[i]) < min) {
            min = f(arr[i]);
        }
    }
    return min;
}

int square(int x) { return x * x; }
int myFunc(int x) { return x * (x - 15) / 2; }
int cube(int x) { return x * x * x; }

int main() {
    bool (*fp)(int, int); // 함수 포인터의 선언 (fp는 int 2개를 받고 bool을 리턴하는 함수를 가리키는 포인터)
    fp = &compare; // [fp = compare;와 같음] compare의 주소값을 fp에 담겠다는 의미
    // bool (*fp)(int, int) = compare; 또는 bool (*fp)(int, int) = &compare;와 같이 사용할 수 있음
    bool res = (*fp)(2, 2); // [bool res = fp(2, 3);과 같음] fp를 역참조한 결과를 통해서 fp가 가리키고 있는 함수 호출
    cout << res << endl;
    
    int arr[7] = { 3, 1, -4, 1, 5, 9, -2 };
    cout << arrFnMin(arr, 7, square) << endl;
    cout << arrFnMin(arr, 7, myFunc) << endl;
    cout << arrFnMin(arr, 7, cube) << endl;
}
