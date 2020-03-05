/*
	C++의 캡슐화 기법

	캡슐화란 객체 지향 프로그래밍 기법에서 중요한 키워드
	캡슐화의 기본 원리는 관련된 함수 및 멤버들은 되도록이면
	하나의 클래스에서 관리하는 것이다. 또한 같이 실행되어야 하는 기능들도
	하나의 클래스에 넣어서 각 객체가 응집된 기능을 가질 수 있도록 해야합니다.
*/

/*
	프랜드

	C++에서는 기본적으로 멤버 변수에 접근하기 위해서 public 멤버 함수를 이용해야 한다.
	다만 특정한 객체의 멤버 함수가 아닌 경우에도 private 멤버에 접근해야 할 때가 있다.
	이 때 프렌드 키워드를 이용하면 특정한 객체의 모든 멤버에 접근할 수 있다.
	 
	프랜드 함수는 기존의 함수 앞에 friend 키워드를 붙인 형태로 사용할 수 있다.
*/

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	int studentId;
	string name;
public:
	Student(int studentId, string name)
		: studentId(studentId), name(name) {}

	//Student operator +(const Student& other) {
	//	return Student(studentId, name + " & " + other.name);

	// 매개변수 두 개를 필히 써야 하는 경우 friend를 반드시 붙어라
	// student 와 other 각각의 private 멤버 변수들에게 접근 가능하다!

	friend Student operator +(const Student& student, const Student& other) {
		return Student(student.studentId, student.name + " & " + other.name); // friend 키워드를 이용해 이름에 접근
	}

	void showName() { cout << "이름: " << name << endl; }
};

int main() {
	Student student(1, "유영재");
	Student result = student + student;
	result.showName();
	system("pause");
}