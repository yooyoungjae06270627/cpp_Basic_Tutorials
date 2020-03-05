/*
	C++로 작성된 소스 코드를 프로그램으로 만드는 빌드 작업은 세 단계를
	거친다. ( 전처리 단계(preprocess))에서는 소스 코드에 담긴 메타 정보를
	처리한다. -> ( 컴파일 단계 ) 에서는 소스 코드를 머신이 읽을 수 있는 오브젝트
	(목적) 파일로 변환한다. 마지막 (링크 단계)에서는 앞에서 변환한 여러
	오브젝트 파일을 애플리케이션으로 엮는다.

	이 세단계를 수행하는 프로그램을 각각 전처리기, 컴파일러, 링커라 부른다.
*/


/*
	C++의 기본부터 세부적인 내용에서 C++17 내용을 추가해서 공부함
	프로그래밍 방법론, 재사용 가능한 디자인 패턴, 바람직한 프로그래밍
	스타일까지 익혔습니다.

	C++가 담당하던 많은 영역을 자바를 비롯한 다른 언어가 가져갔지만
	프로그램의 모든 영역을 최대한 예측 가능하고 제어할 수 있게 만들면서
	성능 최적화를 추구하는 이들의 수요는 일정하게 유지되고 있다.
	텐서플로 내부 연산 부분 C++ / 겉으로는 파이썬만 사용할 줄 알지만 내부적으로는
	핵심 연산을 C++로 처리하는 API도 많다.
*/


/*
001.C++의 클래스 : 객체 지향 프로그래밍을 위한 기본적인 단위이다.

구조체와 클래스의 차이점

일반적으로 C++의 클래스 (Class)는 구조체보다
더 효과적인 문법이다. 구조체와 클래스는 거의 흡사하게
동작하지만, 클래스에서는 내부적으로 '함수'등을 포함할 수 있다.

또한 클래스는 상속(Inheritance)등을 개념을 프로그래밍에서 그대로 이용할 수
있다는 점에서 객체지향 프로그래밍 (Object-Oriented Progamming)을 가능하도록
해주는 기본적인 단위이다.
*/

#include <iostream>
#include <string>

using namespace std;

//struct student
//{
//	string name;
//	int score;
//};

//int main()
//{
//	struct student a;
//	a.name = "유영재";
//	a.score = 100;
//	cout << a.name << " : " << a.score << "점\n";
//	system("pause");
//
//}

//class Student
//{
//private:
//	string name;
//	int score;
//
//public:
//	Student(string n, int s) { name = n; score = s; }
//	void Show() { cout << name << " : " << score << "점\n"; }
//};
//
//int main()
//{
//	// 'a'는 인스턴스
//	Student a = Student("유영재", 100);
//	a.Show();
//	system("pause");
//}

// 유영재 : 100점

 /*
	객체 지향 프로그래밍의 특징
	C++은 클래스(Class)를 이용해 '현실 세계의 사물'인 객체(Object)를
	프로그램 내에서 구현할 수 있도록 해주며, 객체 지향 프로그래밍은 다음과 같은
	특징 때문에 소스코드를 보다 간결하고 생산성 높게 만들어 준다.

	1) 추상화(Abstract)
	2) 캡슐화(Encapulation)
	3) 상속성(Inheritance)
	4) 정보 은닉(Data Hiding)
	5) 다형성(Polymorphism)

	C++의 클래스 : 멤버(Member)
	
	- 멤버 변수를 속성, 혹은 (Property) 라고도 부른다.
	- 멤버 함수를 메소드(Method)라고도 부른다.

	C++의 클래스 : 인스턴스(Instance)

	- C++에서는 클래스를 활용해 만든 변수를 인스턴스라고 한다.
	- 실제로 프로그램 상에서 객체가 살아서 동작하도록 해준다.
	- 하나의 클래스에서 여러 개의 서로 다른 인스턴스를 만들 수 있다.

	C++의 클래스 : 접근 한정자

	-public : 클래스, 멤버 등을 외부로 공개한다. 해당 객체를 사용하는 어떤 곳에서도 접근할 수 있다.
	-private: 클래스, 멤버 등을 내부에서만 활용한다. 외부에서 해당 객체에 접근할 수 없다.

	클래스는 기본적으로 멤버를 private 형태로 간주한다. 반대로 구조체는 기본적으로 멤버를 public으로 간주한다.
	따라서 클래스에서 'private:'부분을 제외하면 멤버는 자동으로 private 문법을 따른다


	C++의 클래스 : this 포인터

	기본적으로 하나의 클래스에서 생성된 인스턴스(Instance)는 서로 독립된 메모리 영역에 멤버 변수를 저장하고,
	관리한다. 
	다만 멤버 함수는 모든 인스턴스가 공유한다는 점에서, 함수 내에서 인스턴스를 구분할 필요가 있다.

	C++의 this 포인터는 포인터 자료형으로, '상수'라는 점에서 값을 변경할 수 없다.
 */


class Student
{
private:
	string name;
	int englishScore;
	int mathScore;
	int getSum() { return englishScore + mathScore; }

public:
	Student(string name, int englishScore, int mathScore)
	{
		this->name = name;   // 자기 자신의 멤버 변수의 접근
		this->englishScore = englishScore;
		this->mathScore = mathScore;
	}

	void Show() { cout << name << " : [합계 " << getSum() << "점]" << endl; }
};

int main()
{
	Student a = Student("유영재", 100, 98);
	a.Show();
	system("pause");
	// cout << a.getSum() -> 에러 : private 접근 한정자는 외부에서 접근할 수 없음. (오류 발생)
}

