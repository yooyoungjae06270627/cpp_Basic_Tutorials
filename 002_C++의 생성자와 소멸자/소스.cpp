/*
	002. C++의 생성자와 소멸자 
	- C++의 생성자와 소멸자는 객체를 초기화 하거나 제거할 때 사용할 수 있는 문법

	C++에서는 생성자(Constructor)를 이용해 객체를 생성함과 동시에
	멤버 변수를 초기화할 수 있다. 생성자는 특별한 메소드로,
	클래스의 이름과 동일한 이름의 메소드로 구현된다.

	생성자는 반환 값이 없다. 생성자는 여러 번 정의되어 다양한 방법으로
	객체를 초기화 할 수 있다.

	C++의 기본 생성자
	C++에서 별도로 생성자를 구현하지 않으면 기본 생성자(Default Constructor)가 사용된다.
	기본 생성자는 매개 변수를 가지지 않으며 멤버 변수는 0,NULL등의 값으로 초기화 된다.

	C++의 복사 생성자
	다른 인스턴스의 참조(Reference)를 인수로 받아서, 그 참조를 이용해
	자신의 인스턴스를 초기화 할 수 있도록 해준다. 대표적인 복사 방법은 깊은 복사(Deep Copy)를
	이용해 만들어진 인스턴스는 기존의 인스턴스와 다른 메모리 공간에 할당되어 독립적이다.


	C++의 소멸자
	
	C++의 소멸자(Destructor)는 객체의 수명이 끝났을 때 객체를 제거하기 위한 목적으로 사용됩니다.
	객체의 수명이 끝났을 때 자동으로 컴파일러가 소멸자 함수를 호출합니다.

	C++의 소멸자 또한 생성자처럼 클래스의 이름과 동일하며 물결 기호(~)를 이용해 정의할 수 있다.
*/

#include <iostream>
#include <string>

using namespace std;

// 기본 생성자 사용해보기

//class Character
//{
//private:
//	string name;
//	int ragePoint;
//	int hp;
//	int damage;
//
//public:
//	void Show()
//	{
//		cout << name << "[" << ragePoint << "] " << hp << " " << damage << endl;
//	}
//};
//
//int main()
//{
//	Character character = Character(); // 기본 생성자 사용
//	character.Show();
//	system("pause");
//}

// [0] 0 0


// 복사 생성자 사용해보기
// 다른 인스턴스의 값을 그대로 자신의 값으로 옮겨 올 수가 있다.
class Character
{
private:
	string name;
	int ragePoint;
	int hp;
	int damage;
public:
	Character(string name, int hp, int damage) 
		:name(name), ragePoint(0), hp(hp), damage(damage) {}
	
	Character(const Character& other)
	{
		name      = other.name;
		ragePoint = other.ragePoint;
		hp        = other.hp;
		damage	  = other.damage;
	}

	~Character()
	{
		cout << "[객체가 소멸됩니다.] " << endl;
	}

	void pointUp() { ragePoint++; }
	void show()
	{
		cout << name << "[" << ragePoint << "] " << hp << " " << damage << endl;
	}
};

int main()
{
	Character* character1 = new Character("슬라임", 10, 20);
	character1->pointUp();
	Character character2(*character1);
	character2.pointUp();
	character1->show();
	character2.show();

	delete character1;    // 동적할당을 이용했으므로 성골적으로 소멸됨
	//delete &character2;   // 동적할당을 이용하지 않았으므로 오류가 발생함
	system("pause");
}

