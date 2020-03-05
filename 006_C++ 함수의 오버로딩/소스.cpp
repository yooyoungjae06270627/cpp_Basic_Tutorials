/*
	함수 오버로딩
	C++은 동일한 이름의 멤버 함수를 다양한 방식으로 활용하기 위해서
	오버로딩을 사용할 수 있다.

	C++에서는 함수 오버로딩을 통해서 동일한 이름의 함수를 약간씩 변형하여 사용할 수 있다.
	C++에서는 자주 이루어지는 특정한 계산을 연산자 오버로딩을 통해서 정리할 수 있다.

*/

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string name;
public:
	Person() { name = "곽민선"; }
	Person(string name) : name(name) { }
	Person operator +(const Person& other) { return Person(name + " & " + other.name); }
	void showName() { cout << "이름: " << name << endl; }
};

int main() {
	Person person1;
	person1.showName();
	Person person2("유영재");
	person2.showName();
	
	Person result = person1 + person2;
	result.showName();
	system("pause");

}

/*
이름: 곽민선
이름: 유영재
이름: 곽민선 & 유영재
*/
/*
	오버로딩(Overloading) : 같은 이름의 메서드 여러개를 가지면서 매개변수의 유형과 개수가 다르도록 하는 기술
	오버라이딩(Overriding) : 상위 클래스가 가지고 있는 메서드를 하위 클래스가 재정의해서 사용

	오버로딩(Overloading)

    오버로딩은 메서드 오버로딩과 생성자 오버로딩이 있습니다. 하지만 둘 다 같은 개념이에요.
    같은 이름의 함수(메서드)를 여러개 정의하고, 매개변수의 유형과 개수를 다르게 하여 다양한 유형의 호출에 응답할 수 있게됩니다.

	오버라이딩(Overriding)

    상위 클래스가 가지고 있는 멤버변수가 하위 클래스로 상속되는 것처럼 상위 클래스가 가지고 있는 메서드도 하위 클래스로 상속되어 하위 클래스에 사용할 수 있습니다. 
	또한, 하위 클래스에서 메서드를 재정의해서도 사용할 수 있습니다.
    쉽게 말해 메서드의 이름이 서로 같고, 매개변수가 같고, 반환형이 같을 경우에 상속받은 메서드를 덮어쓴다고 생각하시면 됩니다. ' 부모클래스의 메서드는 무시하고, 자식 클래스의 메서드 기능을 사용하겠다'와 같습니다.

	오버로딩(Overloading)과 오버라이딩(Overriding) 성립조건

    구분       오버로딩  오버라이딩

 메서드 이름     동일      동일

 매개변수,타입   다름      동일

 리턴 타입     상관없음    동일

*/