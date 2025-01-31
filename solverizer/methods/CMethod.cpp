#include "CMethod.h"

void BubbleSort::sort(int* mass, int size) {
  for (int i = 0; i < size - 1; i++) {
    int all_good = true;
    for (int j = 0; j < size - i - 1; j++) {
      if (mass[j + 1] < mass[j]) {
        int tmp = mass[j + 1];
        mass[j + 1] = mass[j];
        mass[j] = tmp;
        all_good = false;
      }
    }
    if (all_good) break;
  }
}

void CountingSort::sort(int* mass, int size) {
  int max = mass[0], min = mass[0];
  for (int i = 0; i < size; i++) {
    if (mass[i] > max) max = mass[i];
    if (mass[i] < min) min = mass[i];
  }

  int* count = new int[max - min + 1];
  for (int i = 0; i < max - min + 1; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[mass[i] - min] += 1;
  }

  for (int i = 0, j = 0; i < size; j++) {
    while (count[j] != 0) {
      mass[i] = min + j;
      count[j] -= 1;
      i++;
    }
  }

  delete[] count;
}

void QuickSort::qsort(int *mass, int left, int right) {
  if (left < right) {
    // ��������� � ������ � � ����� �������
    int i = left;
    int j = right;

    // ����������� ������� �������
    int base = mass[(right + left) / 2];

    // ����� ������
    do {
      // ��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
      while (mass[i] < base) { i++; }
      while (mass[j] > base) { j--; }

      // ������ �������� �������
      if (i <= j) {
        int tmp = mass[i];
        mass[i] = mass[j];
        mass[j] = tmp;
        i++;
        j--;
      }
    } while (i <= j);

    qsort(mass, left, j);
    qsort(mass, i, right);
  }
}

void SelectionSort::sort(int* mass, int size) {
    int i, j, min_indx, temp;
    
    for (i = 0; i < size - 1; i++) {
        min_indx = i;
        for (j = i + 1; j < size; j++)
            if (mass[j] < mass[min_indx])
                min_indx = j;
        temp = mass[min_indx];
        mass[min_indx] = mass[i];
        mass[i] = temp;
    }
};
