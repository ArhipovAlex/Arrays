#include <iostream>
using namespace std;

#define tab "\t"
//���� RANDOM ���� UNIQ_RANDOM
//#define RANDOM //������� ��������� �������
#define UNIQ_RANDOM //��������� ���������� ����� � ��������� 70-80

#define SORT_ARR //���������� ������� �� RANDOM ��� UNIQ_RANDOM �� �����������
#define DECIMAL_BIN//������� ����������� ����� � ��������
#define DECIMAL_HEX//������� ����������� ����� � �����������������

void main(){
	setlocale(LC_ALL, "Russian");
#ifdef RANDOM
	const int n = 5;//����������� �������
	int arr[n];
	int MinRand;//������� ��� �������
	int MaxRand;//�������� ��� �������
	cout << "���������� � ������������ �������� ��������� �����: "; cin >> MinRand >> MaxRand;
	if (MaxRand < MinRand) {//�������� ��� �������� � ����� ����������
		int buff = MinRand;
		MinRand = MaxRand;
		MaxRand = buff;
	}
	if (MaxRand - MinRand < 10) {//�������� ��� � ��������� ������� 10 ��������
		MaxRand = MinRand + 10;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (MaxRand - MinRand) + MaxRand;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << tab;
	}
	cout << endl;
#endif
#ifdef UNIQ_RANDOM
	cout << "������ �� ���������� ����� �� ��������� [70,80]:\n";
	const int n = 7;//����������� �������
	int arr[n];
	int i = 0;//������� �������� �� �������
	bool uniq_value;//�������� ������������ ���������������� �����
	int rand_num = 0;//���������� ��� �������� ���������� ����� ����� ������� � ������
	do {
		rand_num = rand() % 10 + 70;
		uniq_value = true;//����������� ��� ����� ���������
		for (int j = 0; j < n; j++) {//�������� �� ������������
			if (rand_num == arr[j]) {
				uniq_value = false;
				break;
			}
		}
		if (uniq_value) {//���� ��������� ������ ������ � ������
			arr[i++] = rand_num;
		}
	} while (i < n);//���������� ���� ���� �� �������� ���� ������
	for (int i = 0; i < n; i++) {
		cout << arr[i] << tab;
	}
	cout << endl;
#endif
#ifdef SORT_ARR
	cout << "��������������� ������ �� �����������:\n";
	for (i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int buff = arr[j];
				arr[j] = arr[i];
				arr[i] = buff;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << tab;
	}
	cout << endl;
#endif
#ifdef DECIMAL_BIN
	int number;
	cout << "������� ����� ��� �������� � �������� ������� ���������: "; cin >> number;
	const int max_bin_capacity = 32; //������������ ����������� ��������� �����
	bool digit_bin[max_bin_capacity]={};//������� ��������� �����
	int k = 0;//������� �������� �� �������
	while (number) {
		digit_bin[k++] = number % 2;//���������� ������ ��������� �����
		number /= 2;//������� ���������� ������ �� �����
	}
	while (k % 8 != 0) { //���������� ������ ������� ��� ������ ����� ������
		k++; 
	}
	for (k--; k >= 0; k--) {
		cout << digit_bin[k];
		if (k % 8 == 0) cout << " ";//�������� �� �����
		if (k % 4 == 0) cout << " ";//�������� �� �������
	}
	cout << endl;
#endif
#ifdef DECIMAL_HEX
	int decimal;
	cout << "������� ����� ��� �������� � ����������������� ������� ���������: "; cin >> decimal;
	const int max_hex_capacity = 8;//��� �������� ����� ����� � 16-������� ����� 4 ����, 32 ���� int, 32/4=8 ��������
	char digit_hex[max_hex_capacity] = {'0','0','0','0','0','0','0','0'};//������ ����������� ���� ��� �������� ���� ����� � 16-�������
	int count=0;//������� �������� �� �������
	int buffer;//����� ��� �������� � �������� ����� � ������ ������ ����� ������� � ������
	while (decimal) {
		buffer = decimal % 16;
		decimal /= 16;
		//����� ����� ������������ ���� swith case, ���� ��������� if
		switch (buffer)
		{
			case 0: digit_hex[count++] = '0'; break;
			case 1: digit_hex[count++] = '1'; break;
			case 2: digit_hex[count++] = '2'; break;
			case 3: digit_hex[count++] = '3'; break;
			case 4: digit_hex[count++] = '4'; break;
			case 5: digit_hex[count++] = '5'; break;
			case 6: digit_hex[count++] = '6'; break;
			case 7: digit_hex[count++] = '7'; break;
			case 8: digit_hex[count++] = '8'; break;
			case 9: digit_hex[count++] = '9'; break;
			case 10: digit_hex[count++] = 'A'; break;
			case 11: digit_hex[count++] = 'B'; break;
			case 12: digit_hex[count++] = 'C'; break;
			case 13: digit_hex[count++] = 'D'; break;
			case 14: digit_hex[count++] = 'E'; break;
			case 15: digit_hex[count++] = 'F'; break;
		}
	}
	for (count--; count >= 0; count--) {
		cout << digit_hex[count];
	}
	cout << endl;
#endif
}