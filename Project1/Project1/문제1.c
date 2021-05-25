#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE* f1;
	FILE* f2;

	if ((fopen_s(&f1, "input.txt", "r") != 0) || (fopen_s(&f2, "output.txt", "w") != 0)) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}
	int n;
	fscanf(f1, "%d", &n);
	int* ary;
	ary = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d", &ary[i]);
	}

	int* bry;
	bry = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d", &bry[i]);
	}

	int* cry;
	
	cry = ary;
	ary = bry;
	bry = cry;
	fclose(f1);

	fprintf(f2, "\n");
	for (int j = 0; j < n; j++) {
		fprintf(f2, "%d ", ary[j]);
	}
	fprintf(f2, "\n");
	for (int j = 0; j < n; j++) {
		fprintf(f2, "%d ", bry[j]);
	}

	fclose(f2);

	free(ary);
	free(bry);
	

	printf("완료");
	return 0;
}