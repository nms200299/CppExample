/*
* 작성자 : 2N (nms200299)
* 작성일 : 2026.08.11
* 특이사항 : ch04는 C언어와 동일한 분기/반복문 내용을 담고 있음으로 생략
* 
* 1. 예외 처리 (try, throw, catch)
* 2. 처리 못하는 예외 발생 (try, throw, catch)
* 3. 모든 예외 처리 (try, throw, catch)
* 4. 스택 풀기 (stack unwinding)
* 5. 디버그 모드 예외 처리 (assertion)
* 6. 예외 처리 생략 (noexcept)
* 7. 예외 처리 실패 대응 (set_terminate)
*/

#include <iostream>
#include <cassert> // assert
#include <Windows.h> // pause

void Func6() { std::cout << "set_terminate Func6() Called" << std::endl; }
void Func5() noexcept {throw -2;}
// noexcept 키워드 명시 및 예외 발생
void Func4() noexcept {}
// noexcept 키워드 명시 및 예외 미발생
void Func3() { throw -1; exit(1); }
// 정수형 예외 발생 (throw 이후 코드는 미실행)
void Func2() { Func3(); } // Func3 호출
void Func1() { Func2(); } // Func2 호출

int main() {
    /* ================================================*/
    std::cout << "[1. 예외 처리 (try, throw, catch)]\n";
    int iInput;
    std::cout << "Input : ";
    std::cin >> iInput;

    try {
        if (iInput > 0) {
            std::cout << "throw int(1)" << std::endl;
            throw 1; // 정수형 예외 발생
        } else if (iInput < 0) {
            std::cout << "throw float(1.0)" << std::endl;
            throw 1.0f; // 부동소수형 예외 발생
        } else {
            std::cout << "throw char(a)" << std::endl;
            throw 'a'; // 문자형 예외 발생
        }
    }
    catch (int iErrCode) {
        std::cout << "catch int(" << iErrCode << ")" << std::endl;
    } // 정수형 예외 처리
    catch (float fErrCode) {
        std::cout << "catch float(" << fErrCode << ")" << std::endl;
    } // 부동소수형 예외 처리
    catch (char chErrCode) {
        std::cout << "catch char(" << chErrCode << ")" << std::endl;
    } // 문자형 예외 처리



    /* ================================================*/
    std::cout << "\n[2. 처리 못하는 예외 발생 (try, throw, catch)]\n";
    //try {
    //    throw 1; // 정수형 예외 발생
    //}
    //catch (char chErrCode) {
    //    std::cout << "catch char(" << chErrCode << ")" << std::endl;
    //} // 문자형 예외 처리
    //// 해당하는 형의 catch문이 없으면 abort() VC++ 에러 발생

    /* ================================================*/
    std::cout << "\n[3. 모든 예외 처리 (try, throw, catch)]\n";
    try {
        if (iInput > 0) {
            std::cout << "throw int(1)" << std::endl;
            throw 1; // 정수형 예외 발생
        }
        else if (iInput < 0) {
            std::cout << "throw float(1.0)" << std::endl;
            throw 1.0f; // 부동소수형 예외 발생
        }
        else {
            std::cout << "throw char(a)" << std::endl;
            throw 'a'; // 문자형 예외 발생
        }
    }
    catch (...) {
        std::cout << "catch all" << std::endl;
    } // 자료형에 관계 없이 모든 예외 처리

    /* ================================================*/
    std::cout << "\n[4. 스택 풀기 (stack unwinding)]\n";
    try {
        Func1();
        // Func1 호출 -> Func2 호출 -> Func3 호출 -> throw -1 예외 발생
    }
    catch (int iErrCode) {
        std::cout << "catch Func3{int("<< iErrCode <<")}" << std::endl;
    } // Func3 -> Func2 -> Func1 예외 미처리로 위 catch에서 처리

     /* ================================================*/
    std::cout << "\n[5. 디버그 모드 예외 처리 (assertion)]\n";
    //assert(&iInput == NULL);
    //// Debug 모드 컴파일 시, 예외 메시지가 발생하지 않을 조건을 지정
    //// (Release 모드에서는 수행되지 않으므로 로직에 관여하는 코드 금지)

     /* ================================================*/
    std::cout << "\n[6. 예외 처리 생략 (noexcept)]\n";
    try {
        std::cout << "noexcept Func3 : " << noexcept(Func3()) << std::endl;
        std::cout << "noexcept Func4 : " << noexcept(Func4()) << std::endl;
        std::cout << "noexcept Func5 : " << noexcept(Func5()) << std::endl;
        // 각 함수의 noexcept 키워드 명시 유무 확인

        Func4(); // noexcept 키워드 명시 및 예외 미발생
        //Func5(); // noexcept 키워드 명시 및 예외 발생 이후 런타임 에러 발생

    }
    catch (int iErrCode) {
        std::cout << "catch Func5(noexcept) int(" << iErrCode << ")}" << std::endl;
    } // 예외 처리

     /* ================================================*/
    std::cout << "\n[7. 예외 처리 실패 대응 (set_terminate)]\n";
    set_terminate(Func6);
    throw 1;            // 예외 처리문이 없어 set_terminate한 함수가 호출됨
    //std::terminate();   // set_terminate 함수 호출 이후, std::abort 함수가 호출되고 프로그램이 종료됨
    //return 0;           // set_terminate한 함수 호출 안됨
    //std::exit(0);       // set_terminate한 함수 호출 안됨
    //std::abort();       // set_terminate한 함수 호출 안됨



    system("pause");
}
