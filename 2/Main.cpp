#include "Vector.h"
#include "Fraction.h"
#include "Conditioner.h"
#include <stdio.h>

// ������� 1
//�������� ������ Vector � Matrix ��� �������� � ��������� ���������� �
//��������� ��������, ��������������.����������� ������� 2 ������������ ������ �1
//� ������� ��������� �������.��� ������� �������� � ���� ������� �������.
//� ���� �������� ��������� :
//- ��������� � ������������ ������������ ������ ����������� � ������������� �
//������������ �������, ��������������.
//- � ������ Vector ����������� �������� ����������[].� ������ Matrix ��������
//������ T at(int i, int j) const � setAt(int i, int j, T val), �������
//��������� �������� � ���������� �������� �������� ������� � ��������[i][j], T �
//��� ��� ��������� ������� �� ��������(int ��� double).
//- ����������� ��������� ���������� � ����������(��� �����������, ��� �
//������������).����� ���������� / ���������� ����� ������� ����������� �
//���������� / ���������� ������� �������� �������.



//  ������� 2
//�������� ����� Fraction ��� ������������� ������������ ������(��� ���������
//���� ����� ����� x / y).����������� ��������� + , -, *, / ��� ������.����������� �����
//void reduce() ��� ���������� �����, � ����� ����������� ������ :
//- int gcd(int n, int m)
//������� ��� ���������� ����������� ������ �������� ����� n � m;
//- void printAsFraction(double decimal_fraction)
//- void printAsFraction(char* decimal_fraction)
//������������� ������ ������ ���������� ����� � ���� ������������
//(��������, ��� �������� decimal_fraction = 0.43 �� ������ ������
//	��������� 43 / 100, ��� 0.25 � 1 / 4 � �.�.).
//����� ����������� � ���� ������������ ����� ������ ������� ���� ��������� ��
//������ ������ � ��������� ����������� ������.
//������������������ ������ ���������� ������.������� ��������� �������� ������.
//���������� �������� ��������, ���������, ��������� � ������� ������.�������
//�� ����� ����������.�������� ����� ���������� ������ ����������� ������� ������.


 // ������� 3
 //   �������� ����������� �����, � ������������ � ���������.������������������ � ����
	//������������ ������, ���������� ������������� ��� ���������� � � �����������
	//��� ������������� ������.����� ������ ��������� ����� serialize() ���
	//���������� ������ ������ � ���� � ����� deserialize() ��� ������ ������ ������
	//�� ����� �� ��������� � ������� ����������, � ����� ������������� ������
	//serialize(const std::string & filename) � deserialize(const std::string &
	//filename) ��� ������ � ������ � ��������� � ��������� ������.

	//������� �5
	//����� �����������.
	//������: �����, ������, ���, �����������, �����, ��� �������.
	//������� 2 ������������ � ���� � ������������������� �� � ������� ������������� �
	//�����������. ��� ���� ����������� ������� �������� � ����� � ���������� ��� ������
	//� ������� ��������. � ������� ������� �������������� ��������� �������������
	//���������� ��������� � ���������� ������� �����; ���� ������ ����� ����������,
	//�� ���������� ����� �����������. ��������� ��� ��������� ��� ����. �������
	//���������� �� ������������� ������������� � �����, � ������� �� ������ ������
	//�������� �������, ������� ��������� ����������� �� ���� ������ ���������.
	

void Exercise1() {
	printf("Exercise 1\n");

	Vector* Vect = new Vector(18);
	(*Vect).print();
	(*Vect).sort();
	(*Vect).print();
	++(*Vect);
	(*Vect).print();
	--(*Vect);
	(*Vect).print();
	(*Vect)--;
	(*Vect).print();
	(*Vect)++;
	(*Vect).print();
	Matrix matriks = (*Vect).convertToMatrix(2, 9);
	matriks.print();
	matriks++;
	matriks.print();
	matriks--;
	matriks.print();
	(++matriks).print();
	(--matriks).print();
}

int	Fraction::counter = 0;
void Exercise2() {
	printf("\n\nExercise two");


	Fraction x(0.09);
	Fraction y(.6);
	Fraction a(.0008);
	Fraction b(14.08);

	y.reduce();					// 1/5
	a.reduce();					// 1/2500
	b.reduce();					// 10 1/20

	x.printAsFract(2.3231);  // 2 3231/10000
	x.printAsFract();		// 5/100
	x.reduce();
	x.printAsFract();		// 1/20

	char t[] = "3.14";
	x.printAsFract(t);		//3 14/100

	Fraction d = (x + y);
	d.printAsFract();		// 25/100
	d.reduce();
	d.printAsFract();		// 1/4

	Fraction e = (x - y);
	e.printAsFract();		// -15/100
	e.reduce();
	e.printAsFract();		// 3/-20

	Fraction i = (x * y);
	i.printAsFract();		// 1/100
	i.reduce();
	i.printAsFract();		// 1/100

	Fraction h = (x / y);
	h.printAsFract();		// 25/100
	h.reduce();
	h.printAsFract();		// 1/4

	printf("\n\nAmount Of elements fraction: %d", Fraction::counter);
}

void Exercise3() {
	printf("\n\nExercise 3\n");
	Conditioner* conditionerHeap_1 = new Conditioner("Philips", "DSK_1", 50, 21, 0, "2004");
	Conditioner* conditionerHeap_2 = new Conditioner("LG", "KL-2000", 88, 31, 1, "2007");

	Conditioner conditionerStack;
	conditionerStack.setFirm("Philips");
	conditionerStack.setMass(50);
	conditionerStack.setModel("DSK-1");
	conditionerStack.setReleaseYear("2004");
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