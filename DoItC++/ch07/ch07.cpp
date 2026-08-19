/*
* 작성자 : 2N (nms200299)
* 작성일 : 2026.08.19
* 특이사항 : ch06은 객체 지향 개념에 대한 내용을 담고 있음으로 생략
*
* 1. 클래스 접근 지정자
* 2. 다중 상속 및 메서드 오버라이딩
* 3. 메서드 오버로딩
* 4. 가상 함수 및 생성자
* 5. 값을 전달받는 생성자
* 6. 멤버 변수 초기화
*/

#include <iostream>

class Cls1 {
public: // 다른 클래스에서 접근 가능
    void Print() {
        Plus();
        std::cout << "a=" << a << " / b=" << b << std::endl;
    }
    void Init() {
        a = 0;
        b = 0;
    }
private: // 클래스 내 멤버 함수에서만 접근 가능
    void Plus() {
        a++;
        b++;
    }
protected: // 클래스 내 멤버 함수나 상속 관계 클래스에서 접근 가능
    int a, b;
}; // 1. 클래스 접근 지정자

class Cls2 {
public:
    void Print() {
        c++;
        d++;
        std::cout << "c=" << c << " / d=" << d << std::endl;
    }
protected:
    int c, d;
};

class Cls3 :public Cls1, public Cls2 { // 다중 상속
public:
    void Print() {
        // 메소드 오버라이딩
        a = 1;
        b = 2;
        c = 3;
        d = 4;
        std::cout << "a=" << a << " / b=" << b << std::endl;
        std::cout << "c=" << c << " / d=" << d << std::endl;
        Cls2::Print(); // 상위 클래스 메소드 호출
    }
}; // 2. 다중 상속 및 메서드 오버라이딩


class Cls4 {
public:
    void Print() {
        std::cout << "Hello" << std::endl;
    }
    void Print(int num) {
        std::cout << "Hello " << num << std::endl;
    }
    void Print(std::string str) {
        std::cout << "Hello " << str << std::endl;
    }
}; // 3. 메서드 오버로딩


class Cls5 {
public:
    Cls5() {
        std::cout << "Cls5 Constructor" << std::endl;
    }
    virtual void VirFunc() {};
};

class Cls6 :public Cls5 {
public:
    virtual void VirFunc() override {
        std::cout << "Cls6 VirFunc1" << std::endl;
    };
};

class Cls7 :public Cls5 {
public:
    virtual void VirFunc() override {
        std::cout << "Cls7 VirFunc2" << std::endl;
    };
};
// 4. 가상 함수 및 생성자

class Cls8 {
public:
    int arg[2];
    Cls8() : Cls8(1, 2) {
    } // 기본 생성자에서 값을 전달받는 다른 생성자 호출

    Cls8(int arg1, int arg2) : arg{ arg1 , arg2 } {
        std::cout << "Cls8 arg1=" << arg1 << " / arg2=" << arg2 << std::endl;
    } // 값을 전달받는 생성자
};
// 5. 값을 전달받는 생성자

class Cls9 {
public:
    Cls9() :
        szStr("Init"), // 직접 초기화
        iValArr{ 1,2 }, // 유니폼 초기화
        iValConst(3), // 상수 변수 초기화
        piValPtr(&iVal) // 레퍼런스 변수 초기화
    {
        iVal = 4; // 복사 초기화
        piDnStr = new char[10]; // 동적 메모리 할당

        std::cout << "Cls9 " << szStr << std::endl;
        std::cout << "Cls9 " << iValArr[0] << " " << iValArr[1] << std::endl;
        std::cout << "Cls9 " << iValConst << std::endl;
        std::cout << "Cls9 " << piValPtr << " " << *piValPtr << std::endl;
        std::cout << "Cls9 " << static_cast<void*>(piDnStr) << std::endl;
    }
private:
    std::string szStr;
    int iVal;
    int iValArr[2];
    const int iValConst;
    int* piValPtr;
    char* piDnStr;

};
// 6. 멤버 변수 초기화


int main() {
    /* ================================================*/
    std::cout << "[1. 클래스 접근 지정자]\n";
    Cls1 Class1;
    Class1.Init();
    Class1.Print();

    std::cout << "\n[2. 다중 상속 및 메서드 오버라이딩]\n";
    Cls3 Class3;
    Class3.Print();

    std::cout << "\n[3. 메서드 오버로딩]\n";
    Cls4 Class4;
    Class4.Print();
    Class4.Print(123);
    Class4.Print("World!");

    std::cout << "\n[4. 가상 함수 및 생성자]\n";
    Cls5* pClass5;
    Cls6 Class6;
    Cls7 Class7;
    pClass5 = &Class6;
    pClass5->VirFunc();
    pClass5 = &Class7;
    pClass5->VirFunc();

    std::cout << "\n[5. 값을 전달받는 생성자]\n";
    Cls8 Class8;
    Cls8 Class9(3, 4);

    std::cout << "\n[6. 멤버 변수 초기화]\n";
    Cls9 Class10;

    system("pause");
}
