#include "Vector.h"
#include "Fraction.h"
#include "Conditioner.h"
#include <stdio.h>

/* ������� 1
	�������� ������ Vector � Matrix ��� �������� � ��������� ���������� �
	��������� ��������, ��������������.����������� ������� 2 ������������ ������ �1
	� ������� ��������� �������.��� ������� �������� � ���� ������� �������.
	� ���� �������� ��������� :
	- ��������� � ������������ ������������ ������ ����������� � ������������� �
	������������ �������, ��������������.
	- � ������ Vector ����������� �������� ����������[].� ������ Matrix ��������
	������ T at(int i, int j) const � setAt(int i, int j, T val), �������
	��������� �������� � ���������� �������� �������� ������� � ��������[i][j], T �
	��� ��� ��������� ������� �� ��������(int ��� double).
	- ����������� ��������� ���������� � ����������(��� �����������, ��� �
	������������).����� ���������� / ���������� ����� ������� ����������� �
	���������� / ���������� ������� �������� �������.
	*/

/* ������� 2
�������� ����� Fraction ��� ������������� ������������ ������(��� ���������
���� ����� ����� x / y).����������� ��������� + , -, *, / ��� ������.����������� �����
void reduce() ��� ���������� �����, � ����� ����������� ������ :
- int gcd(int n, int m)
������� ��� ���������� ����������� ������ �������� ����� n � m;
- void printAsFraction(double decimal_fraction)
- void printAsFraction(char* decimal_fraction)
������������� ������ ������ ���������� ����� � ���� ������������
(��������, ��� �������� decimal_fraction = 0.43 �� ������ ������
	��������� 43 / 100, ��� 0.25 � 1 / 4 � �.�.).
����� ����������� � ���� ������������ ����� ������ ������� ���� ��������� ��
������ ������ � ��������� ����������� ������.
������������������ ������ ���������� ������.������� ��������� �������� ������.
���������� �������� ��������, ���������, ��������� � ������� ������.�������
�� ����� ����������.�������� ����� ���������� ������ ����������� ������� ������.
*/

/* ������� 3
�������� ����������� �����, � ������������ � ���������.������������������ � ����
������������ ������, ���������� ������������� ��� ���������� � � �����������
��� ������������� ������.����� ������ ��������� ����� serialize() ���
���������� ������ ������ � ���� � ����� deserialize() ��� ������ ������ ������
�� ����� �� ��������� � ������� ����������, � ����� ������������� ������
serialize(const std::string & filename) � deserialize(const std::string &
filename) ��� ������ � ������ � ��������� � ��������� ������.

������� �5
����� �����������.
������: �����, ������, ���, �����������, �����, ��� �������.
������� 2 ������������ � ���� � ������������������� �� � ������� ������������� �
�����������. ��� ���� ����������� ������� �������� � ����� � ���������� ��� ������
� ������� ��������. � ������� ������� �������������� ��������� �������������
���������� ��������� � ���������� ������� �����; ���� ������ ����� ����������,
�� ���������� ����� �����������. ��������� ��� ��������� ��� ����. �������
���������� �� ������������� ������������� � �����, � ������� �� ������ ������
�������� �������, ������� ��������� ����������� �� ���� ������ ���������.
*/

void Exercise1() {
	printf("Exercise one\n");

	Vector* vector = new Vector(18);
	(*vector).print();
	(*vector).sort();
	(*vector).print();
	++(*vector);
	(*vector).print();
	--(*vector);
	(*vector).print();
	(*vector)--;
	(*vector).print();
	(*vector)++;
	(*vector).print();
	Matrix math = (*vector).convertToMatrix(2, 9);
	math.print();
	math++;
	math.print();
	math--;
	math.print();
	(++math).print();
	(--math).print();
}

int	Fraction::counter = 0;
void Exercise2() {
	printf("\n\nExercise two");


	Fraction x(0.05);
	Fraction y(.2);
	Fraction a(.0004);
	Fraction b(10.05);

	y.reduce();					// 1/5
	a.reduce();					// 1/2500
	b.reduce();					// 10 1/20

	x.printAsFraction(2.3231);  // 2 3231/10000
	x.printAsFraction();		// 5/100
	x.reduce();
	x.printAsFraction();		// 1/20

	char t[] = "3.14";
	x.printAsFraction(t);		//3 14/100

	Fraction d = (x + y);
	d.printAsFraction();		// 25/100
	d.reduce();
	d.printAsFraction();		// 1/4

	Fraction e = (x - y);
	e.printAsFraction();		// -15/100
	e.reduce();
	e.printAsFraction();		// 3/-20

	Fraction i = (x * y);
	i.printAsFraction();		// 1/100
	i.reduce();
	i.printAsFraction();		// 1/100

	Fraction h = (x / y);
	h.printAsFraction();		// 25/100
	h.reduce();
	h.printAsFraction();		// 1/4

	printf("\n\nAmountOfElements Fraction: %d", Fraction::counter);
}

void Exercise3() {
	printf("\n\nExercise three\n");
	Conditioner* conditionerHeap_1 = new Conditioner("Philips", "NF_2000", 70, 21, 0, "2015");
	Conditioner* conditionerHeap_2 = new Conditioner("LG", "MDKS-134", 88, 31, 1, "2004");

	Conditioner conditionerStack;
	conditionerStack.setFirm("Philips");
	conditionerStack.setMass(70);
	conditionerStack.setModel("NF_2000");
	conditionerStack.setReleaseYear("2015");
	conditionerStack.setState(1);
	conditionerStack.setTemp(30);


	conditionerHeap_1->printState();
	conditionerHeap_2->printState();
	conditionerStack.printState();

	conditionerHeap_1->mode(1, 31);
	conditionerHeap_1->mode(1, 29);
	conditionerHeap_1->mode(0, 22);
	conditionerHeap_1->mode(0, 20);
	conditionerHeap_1->printState();

	conditionerHeap_1->serialize();
	conditionerHeap_1->deserialize();


	conditionerHeap_1->serialize("test.txt");
	conditionerHeap_1->deserialize("test.txt");

	delete conditionerHeap_1;
	delete conditionerHeap_2;
}

int main() {
	
	Exercise1();
	Exercise2();
	Exercise3();

	return 0;
}