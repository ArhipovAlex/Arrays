#include <iostream>
using namespace std;

#define tab "\t"
//либо RANDOM либо UNIQ_RANDOM
//#define RANDOM //простая генерация массива
#define UNIQ_RANDOM //генерация уникальных чисел в диапазоне 70-80

#define SORT_ARR //сортировка массива из RANDOM или UNIQ_RANDOM по возрастанию
#define DECIMAL_BIN//перевод десятичного числа в двоичное
#define DECIMAL_HEX//перевод десятичного числа в шестнадцатеричное

void main(){
	setlocale(LC_ALL, "Russian");
#ifdef RANDOM
	const int n = 5;//размерность массива
	int arr[n];
	int MinRand;//минимум для рандома
	int MaxRand;//максимум для рандома
	cout << "Миммальное и максимальное значения случайных чисел: "; cin >> MinRand >> MaxRand;
	if (MaxRand < MinRand) {//проверка что значения в своих переменных
		int buff = MinRand;
		MinRand = MaxRand;
		MaxRand = buff;
	}
	if (MaxRand - MinRand < 10) {//проверка что в диапазоне минимум 10 значений
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
	cout << "Массив из уникальных чисел из диапазона [70,80]:\n";
	const int n = 7;//размерность массива
	int arr[n];
	int i = 0;//счетчик движения по массиву
	bool uniq_value;//контроль уникальности сгенерированного числа
	int rand_num = 0;//переменная для хранения случайного числа перед записью в массив
	do {
		rand_num = rand() % 10 + 70;
		uniq_value = true;//предположим что число уникально
		for (int j = 0; j < n; j++) {//проверка на уникальность
			if (rand_num == arr[j]) {
				uniq_value = false;
				break;
			}
		}
		if (uniq_value) {//если уникально делаем запись в массив
			arr[i++] = rand_num;
		}
	} while (i < n);//продолжаем цикл пока не заполним весь массив
	for (int i = 0; i < n; i++) {
		cout << arr[i] << tab;
	}
	cout << endl;
#endif
#ifdef SORT_ARR
	cout << "Отсортированный массив по возрастанию:\n";
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
	cout << "Введите число для перевода в двоичную систему счисления: "; cin >> number;
	const int max_bin_capacity = 32; //максимальная разрядность двоичного числа
	bool digit_bin[max_bin_capacity]={};//разряды двоичного числа
	int k = 0;//счетчик движения по массиву
	while (number) {
		digit_bin[k++] = number % 2;//записываем разряд двоичного числа
		number /= 2;//убираем записанный разряд из числа
	}
	while (k % 8 != 0) { //доращиваем пустые разряды для вывода целых Байтов
		k++; 
	}
	for (k--; k >= 0; k--) {
		cout << digit_bin[k];
		if (k % 8 == 0) cout << " ";//разбивка на Байты
		if (k % 4 == 0) cout << " ";//разбивка по тетрады
	}
	cout << endl;
#endif
#ifdef DECIMAL_HEX
	int decimal;
	cout << "Введите число для перевода в шестнадцатеричную систему счисления: "; cin >> decimal;
	const int max_hex_capacity = 8;//для хранения одной цифры в 16-системе нужно 4 бита, 32 бита int, 32/4=8 символов
	char digit_hex[max_hex_capacity] = {'0','0','0','0','0','0','0','0'};//массив символьного типа для хранения цифр числа в 16-системе
	int count=0;//счетчик движения по массиву
	int buffer;//буфер для хранения и перевода числа в нужный символ перед записью в массив
	while (decimal) {
		buffer = decimal % 16;
		decimal /= 16;
		//далее можно использовать либо swith case, либо несколько if
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