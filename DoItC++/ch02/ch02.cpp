/*
* 작성자 : 2N (nms200299)
* 작성일 : 2026.08.10
* 
* 1. ANSI 입출력
*     cin, cout
* 2. 유니코드 입출력
*     wcin, wcout
* 3. 실수 출력
*     numeric_limits
* 4. 지역/전역 변수 참조
*     ::
* 5. 명시적 형변환
*     int()
* 6. string 자료형
*     string
*     wstring
* 7. 사용자 정의 리터럴
*     operator
* 8. bitset 라이브러리 활용
*     bitset
*/

#include <iostream>
#include <Windows.h> // pause
#include <iomanip> // setprecision
#include <bitset> // bitset

using namespace std; // 네임 스페이스 생략 가능
int iVal = 2;

long double operator"" _km(long double val) {
    return val;
} // _km 사용자 리터럴 정의

long double operator"" _mi(long double val) {
    const long double km_per_mi = 1.609344L;
    return val * km_per_mi;
} // _mi 사용자 리터럴 정의


int main() {
    /* ================================================*/
    std::cout << "[1. ANSI 입출력]\n";
    char szStr[100];

    std::cout << "Input String : ";
    std::cin >> szStr;
    std::cout << szStr << std::endl;
    // 네임 스페이스 생략 없이 입출력

    cout << "Input String : ";
    cin >> szStr;
    cout << szStr << endl;
    // 네임 스페이스 생략하여 입출력

    /* ================================================*/

    std::cout << "\n[2. 유니코드 입출력]\n";
    wchar_t wszStr[100];

    std::wcout << "Input String : ";
    std::wcin >> wszStr;
    std::wcout << wszStr << std::endl;
    // wcout, wcin으로 유니코드 입출력

    /* ================================================*/

    std::cout << "\n[3. 실수 출력]\n";
    float fVal = 9.87654321f;
    double dVal = 9.87654321987654321;

    std::cout << fVal << std::endl;
    std::cout << dVal << std::endl;
    // 기본 정밀도 6자리까지만 출력됨

    std::cout << std::setprecision(numeric_limits<float>::digits10 + 1) << fVal << std::endl;
    std::cout << std::setprecision(numeric_limits<double>::digits10 + 1) << dVal << std::endl;
    // 자료형의 유효 자릿수 만큼 정밀도를 조정하여 출력

    /* ================================================*/

    std::cout << "\n[4. 지역/전역 변수 출력]\n";
    int iVal = 1;
    std::cout << iVal << std::endl; // 지역 변수 출력
    std::cout << ::iVal << std::endl; // 전역 변수 출력

    /* ================================================*/

    std::cout << "\n[5. 명시적 형변환]\n";
    float iVal2 = 1.23f;
    std::cout << int(iVal) << std::endl; // 지역 변수 출력

    /* ================================================*/

    std::cout << "\n[6. string 자료형]\n";
    std::string strString("basic string");
    std::wstring wstrString(L"unicode string");
    std::cout << strString << std::endl;
    std::wcout << wstrString << std::endl;
    // ANSI 문자열과 UNICODE 문자열 출력

    /* ================================================*/

    std::cout << "\n[7. 사용자 정의 리터럴]\n";
    long double dist1 = 1.0_km; // _km 리터럴
    long double dist2 = 1.0_mi; // _mi 리터럴
    std::cout << dist1 + dist2 << "km" << std::endl;

    /* ================================================*/

    std::cout << "\n[8. bitset 라이브러리 활용]\n";
    int iBitSetA = 10;
    int iBitSetB = 31;
    int iBitSetOr = iBitSetA | iBitSetB;
    int iBitSetAnd = iBitSetA & iBitSetB;
    int iBitSetXor = iBitSetA ^ iBitSetB;

    std::cout << iBitSetOr << " = " << bitset<8>(iBitSetOr) << std::endl;
    std::cout << iBitSetAnd << " = " << bitset<8>(iBitSetAnd) << std::endl;
    std::cout << iBitSetXor << " = " << bitset<8>(iBitSetXor) << std::endl;

    /* ================================================*/

    system("pause");
}
