/*
	C++�� ĸ��ȭ ���

	ĸ��ȭ�� ��ü ���� ���α׷��� ������� �߿��� Ű����
	ĸ��ȭ�� �⺻ ������ ���õ� �Լ� �� ������� �ǵ����̸�
	�ϳ��� Ŭ�������� �����ϴ� ���̴�. ���� ���� ����Ǿ�� �ϴ� ��ɵ鵵
	�ϳ��� Ŭ������ �־ �� ��ü�� ������ ����� ���� �� �ֵ��� �ؾ��մϴ�.
*/

/*
	������

	C++������ �⺻������ ��� ������ �����ϱ� ���ؼ� public ��� �Լ��� �̿��ؾ� �Ѵ�.
	�ٸ� Ư���� ��ü�� ��� �Լ��� �ƴ� ��쿡�� private ����� �����ؾ� �� ���� �ִ�.
	�� �� ������ Ű���带 �̿��ϸ� Ư���� ��ü�� ��� ����� ������ �� �ִ�.
	 
	������ �Լ��� ������ �Լ� �տ� friend Ű���带 ���� ���·� ����� �� �ִ�.
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

	// �Ű����� �� ���� ���� ��� �ϴ� ��� friend�� �ݵ�� �پ��
	// student �� other ������ private ��� �����鿡�� ���� �����ϴ�!

	friend Student operator +(const Student& student, const Student& other) {
		return Student(student.studentId, student.name + " & " + other.name); // friend Ű���带 �̿��� �̸��� ����
	}

	void showName() { cout << "�̸�: " << name << endl; }
};

int main() {
	Student student(1, "������");
	Student result = student + student;
	result.showName();
	system("pause");
}