#include<stdio.h>

int main() {
	int num;
	scanf_s("%d", &num);

	int a[100][100] = { 0 };
	int ident_rc = 0;
	// 0 이면 column, 1이면 row

	int ident_pm = 1;
	// 1이면 양수 방향, -1이면 음수 방향

	int row_col[2] = { 0, 0 };

	int num_cy = num;
	int shift_num = num;
	for (int i = 1; i <= num * num; i++) {
		if (i == num_cy) {
			if (ident_rc == 1) {
				ident_pm *= -1;
				shift_num += 1;
			}
			ident_rc = (ident_rc + 1) % 2;
			shift_num = shift_num - 1;
			num_cy += shift_num;

		}
		a[row_col[0]][row_col[1]] = i;
		row_col[ident_rc] += ident_pm;
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%4d  ", a[j][i]);
		}
		printf("\n");
	}
}