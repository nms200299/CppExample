/*
* 작성자 : 2N (nms200299)
* 작성일 : 2026.08.11
*
* 1. 동적 메모리 할당 (new, delete)
* 2. 문자열 변환 (to_string)
* 3. 정적 변수 (static)
* 4. 상수 변수 (const)
* 5. 레퍼런스 변수 (&)
*/


#include <iostream>
#include <Windows.h> // pause
#include <string> // to_string


void StaticTest() {
    int iA = 0; // stack 영역에 저장
    static int s_iB = 0; // data 영역에 저장
    iA++;
    s_iB++;
    std::cout << "A: " << iA << " / B:" << s_iB << std::endl;
}

int main() {
    /* ================================================*/
    std::cout << "[1. 동적 메모리 할당 (new, delete)]\n";
    int* piDnVal = new int;
    int* piDnValArr = new int[2];
    // 동적 메모리 할당

    *piDnVal = 100;
    piDnValArr[0] = 200;
    piDnValArr[1] = 300;

    std::cout << "piDnVal(" << piDnVal << ") = " << *piDnVal << std::endl;
    std::cout << "piDnValArr[0](" << &piDnValArr[0] << ") = " << piDnValArr[0] << std::endl;
    std::cout << "piDnValArr[1](" << &piDnValArr[1] << ") = " << piDnValArr[1] << std::endl;

    delete piDnVal;
    delete[] piDnValArr;
    // 동적 메모리 해제

    /* ================================================*/
    std::cout << "\n[2. 문자열 변환 (to_string)]\n";
    float fPi = 3.141592f;
    std::cout << "파이 : " + std::to_string(fPi) << std::endl;

    /* ================================================*/
    std::cout << "\n[3. 정적 변수 (static)]\n";
    StaticTest();
    StaticTest();
    StaticTest();

    /* ================================================*/
    std::cout << "\n[4. 상수 변수 (const)]\n";
    int iA = 0;
    const int iB = 1; // 읽기 전용 변수
    // c_iB = 0; // 컴파일 에러 발생

    const int* piA = &iA; // 값 읽기 전용 포인터
    std::cout << *piA << std::endl;
    iA = 2; // 성공
    piA = &iB; // 성공
    //*piA = 1; // 컴파일 에러 발생
    std::cout << *piA << std::endl;

    int* const piB = &iA; // 주소 고정 포인터
    //piB = &iB; // 컴파일 에러 발생
    std::cout << *piB << std::endl;
    *piB = 3; // 성공
    std::cout << *piB << std::endl;

    /* ================================================*/
    std::cout << "\n[5. 레퍼런스 변수 (&)]\n";
    int &iRefA = iA;
    std::cout << iA << std::endl;
    iRefA = 4;
    std::cout << iA << std::endl;
    // 특정 변수의 별칭과 같은 역할로 값을 바꾸면 동일하게 변경됨.

    /* ================================================*/
    system("pause");
}