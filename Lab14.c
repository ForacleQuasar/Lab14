#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//1
double* full_elements(double* array, int size) {
	double x = 1;
	double y;
	int i = 0;
	while (i < size) {
		y = x * x * x - 4 * x * x + 2;
		array[i] = y;
		x += 0.2;
		i += 1;
	}
	return array;
}
double put_elements(double* array, int size) {
	int i = 0;
	while (i < size) {
		printf("array[%i]=%lf\n", i + 1, array[i]);
		i += 1;
	}
}
double* calc_elements(double* array, int size) {
	int i = 0;
	while (i < size) {
		printf("��������� array[%i]=%lf\n", i + 1, array[i] * -1);
		i += 1;
	}
}
//2
double sum_elements(double* array, int begin, int end) {
	int i = 0;
	int repeat = end - begin;
	double sum=0;
	while (i < repeat) {
		sum += array[begin];
		begin += 1;
		i += 1;
	}
	return sum;
}
int find_element(double* array, int size, double element) {
	for (int i = 0; i < size; i++) {
		if (array[i] == element) {
			return i + 1;
			break;
		}
		else return -1;
	}
}
//3
int number_element(double* array, int size, int k) {
	for (int i = 0; i < size; i++) {
		if ((int)array[i] % k == 0)printf("���������� ����� �������� �������� %i > %i\n", k, i + 1);
	}

}
//��
double max_element(double* array, int size, int K, int L) {
	int i = L - K;
	int i1 = K-1;
	double maximum = -10;
	while (i > 0) {
		if (array[i1] > maximum) {
			maximum = array[i1];
			i--;
			i1++;
		}
		else {
			i--;
			i1++;
		}
	}
	return maximum;
}
void main() {
	setlocale(LC_CTYPE, "RUS");
	double array[10];
	int size;
	printf("������� ������ ������� > ");
	scanf("%d", &size);
	//1
	full_elements(array, size);
	put_elements(array, size);
	calc_elements(array, size);
	//2
	int begin = 0;
	int end = size;
	double element;
	printf("����� ��������� ������� � %i �� %i > %lf\n",begin, end, sum_elements(array, begin, end));
	printf("������� ������� ��� ������ � ������� > ");
	scanf("%lf", &element);
	printf("����� ������� ��������� ��� �������� - %i\n", find_element(array, size, element));
	//3
	int k;
	printf("������� ��������� ��� ������ � ������� > ");
	scanf("%i", &k);
	number_element(array, size, k);
	//��
	int K;
	int L;
	printf("������� ������ ��������� > ");
	scanf("%i", &K);
	printf("������� ����� ��������� > ");
	scanf("%i", &L);
	printf("������������ �������� � ��������� > %lf", max_element(array, size, K, L));
}