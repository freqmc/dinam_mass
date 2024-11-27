#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double* full_elems_random(double* ptr_array, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		double x = rand() % 100;
		ptr_array[i] = -1 + rand() % 2 + x/100;
	}
	return ptr_array;
}

double *full_elems(double *ptr_array, int size) {
	double y = 0;
	double z = 2.1 / size;
	for (int i = 0; i < size; i++) {
		y += z;
		ptr_array[i] = pow(y, 2) - pow(cos(y + 1), 2);
	}
	return ptr_array;
}

int put_elems(double* ptr_array, int size) {
	for (int i = 0; i < size; i++) {
		printf("a[%d] = %.2lf\n", i, ptr_array[i]);
	}
	printf("\n");
}

int delete_k(double *ptr_arr, int size, int k) {
	for (int i = k; i < size; i++) {
		ptr_arr[i] = ptr_arr[i + 1];
	}
	--size;
	return size;
}

double* insert(double* ptr_arr, int* size, int index, double num) {
	int size_n = (*size) + 1;
	if (ptr_arr == NULL) return NULL;
	double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));
	if (ptr_arr_n == NULL) return ptr_arr;
	ptr_arr = ptr_arr_n;
	for (int i = size_n - 1; i > index; i--) {
		ptr_arr[i] = ptr_arr[i - 1];
	}
	ptr_arr[index] = num;
	*size = size_n;
	return ptr_arr;
}


int main() {
	double* ptr_array;
	int size, k;

	setlocale(LC_CTYPE, "RUS");

	printf("¬ведите размер массива\n");
	scanf("%d", &size);
	getchar();
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL) {
		puts("Error");
		return -1;
	}
	full_elems_random(ptr_array, size);
	put_elems(ptr_array, size);
	/*for (int i = 0; i < size; i++) {
		while (ptr_array[i] < 0) {
			k = delete_k(ptr_array, size, i);
			size--;
		}
	}
	/*put_elems(ptr_array, k);*/
	put_elems(insert(ptr_array, size,),size);
	free(ptr_array);
}