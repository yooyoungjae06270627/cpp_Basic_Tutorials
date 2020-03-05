/*
	002. C++�� �����ڿ� �Ҹ��� 
	- C++�� �����ڿ� �Ҹ��ڴ� ��ü�� �ʱ�ȭ �ϰų� ������ �� ����� �� �ִ� ����

	C++������ ������(Constructor)�� �̿��� ��ü�� �����԰� ���ÿ�
	��� ������ �ʱ�ȭ�� �� �ִ�. �����ڴ� Ư���� �޼ҵ��,
	Ŭ������ �̸��� ������ �̸��� �޼ҵ�� �����ȴ�.

	�����ڴ� ��ȯ ���� ����. �����ڴ� ���� �� ���ǵǾ� �پ��� �������
	��ü�� �ʱ�ȭ �� �� �ִ�.

	C++�� �⺻ ������
	C++���� ������ �����ڸ� �������� ������ �⺻ ������(Default Constructor)�� ���ȴ�.
	�⺻ �����ڴ� �Ű� ������ ������ ������ ��� ������ 0,NULL���� ������ �ʱ�ȭ �ȴ�.

	C++�� ���� ������
	�ٸ� �ν��Ͻ��� ����(Reference)�� �μ��� �޾Ƽ�, �� ������ �̿���
	�ڽ��� �ν��Ͻ��� �ʱ�ȭ �� �� �ֵ��� ���ش�. ��ǥ���� ���� ����� ���� ����(Deep Copy)��
	�̿��� ������� �ν��Ͻ��� ������ �ν��Ͻ��� �ٸ� �޸� ������ �Ҵ�Ǿ� �������̴�.


	C++�� �Ҹ���
	
	C++�� �Ҹ���(Destructor)�� ��ü�� ������ ������ �� ��ü�� �����ϱ� ���� �������� ���˴ϴ�.
	��ü�� ������ ������ �� �ڵ����� �����Ϸ��� �Ҹ��� �Լ��� ȣ���մϴ�.

	C++�� �Ҹ��� ���� ������ó�� Ŭ������ �̸��� �����ϸ� ���� ��ȣ(~)�� �̿��� ������ �� �ִ�.
*/

#include <iostream>
#include <string>

using namespace std;

// �⺻ ������ ����غ���

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
//	Character character = Character(); // �⺻ ������ ���
//	character.Show();
//	system("pause");
//}

// [0] 0 0


// ���� ������ ����غ���
// �ٸ� �ν��Ͻ��� ���� �״�� �ڽ��� ������ �Ű� �� ���� �ִ�.
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
		cout << "[��ü�� �Ҹ�˴ϴ�.] " << endl;
	}

	void pointUp() { ragePoint++; }
	void show()
	{
		cout << name << "[" << ragePoint << "] " << hp << " " << damage << endl;
	}
};

int main()
{
	Character* character1 = new Character("������", 10, 20);
	character1->pointUp();
	Character character2(*character1);
	character2.pointUp();
	character1->show();
	character2.show();

	delete character1;    // �����Ҵ��� �̿������Ƿ� ���������� �Ҹ��
	//delete &character2;   // �����Ҵ��� �̿����� �ʾ����Ƿ� ������ �߻���
	system("pause");
}

