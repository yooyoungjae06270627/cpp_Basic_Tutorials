#include <iostream>
#include <string>

using namespace std;

/*
	C++의 클래스 상속

	상속(Inheritance)은 객체 지향 프로그래밍의 주요한 특성 중 하나이다.
	현실 세계에서의 상속의 개념을 프로그래밍으로 그대로 가져와 사용할 수 있다.
	이를 통해 프로그램의 논리적 구조를 계층적으로 구성할 수 있다.

	흔히 자식이 부모의 속성을 물려 받듯이, 자식 클래스가 부모 클래스의 속성을 그대로
	물려 받아 사용할 수 있다. 그러므로 상속을 활용하여 소스코드의 재사용성을 늘릴 수 있다.

	부모 클래스 <----(상속)------  자식 클래스

	자식 클래스는 파생 클래스(Derived Class)라고도 하며, 부모 클래스의 모든 속성을 물려 받는다.
	자식 클래스는 콜론(:)을 활용하여 부모 클래스와 연결될 수 있다.

    자식 클래스의 인스턴스를 만들 때 가장 먼저 부모 클래스의 생성자가 호출된다.
	이후에 자식 클래스의 생성자가 호출된다.
	또한 자식 클래스의 수명이 다했을 때는 자식 클래스의 소멸자가 먼저 호출된 이후에 부모
	클래스의 소멸자가 호출된다.

*/

// 상속 : 부모 클래스 정의하기

class Person {
private:
	string name;
public:
	Person(string name) : name(name) {}
	
	string getName() {
		return name;
	}
	
	void showName() {
		cout << "이름: " << getName() << endl;
	}
};

// 상속 : 자식 클래스 정의 및 사용하기

class Student : Person {
private:
	int studentID;
public:
	Student(int studentID, string name) : Person(name) {
		this->studentID = studentID;
	}
	void show() {
		cout << "학생 번호: " << studentID << endl;
		cout << "학생 이름: " << getName() << endl;
	}

	void showName() {
		cout << "학생 이름: " << getName() << endl;
	}
};

int main() {
	Student student(1, "유영재");
	student.show();
	student.showName();          // 오버라이딩: 자식클래스 정의 및 사용하기 
	system("pause");
}

/*
학생 번호: 1
학생 이름: 유영재
학생 이름: 유영재
*/

/*
	오버라이딩 :  부모 클래스에서 정의된 함수를 무시하고, 자식 클래스에서 동일한 이름의
	함수를 재정의 하는 문법이다. 오버라이딩을 적용한 함수의 원형은 기존의 함수와
	동일한 매개변수를 전달 받는다.

*/