#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include<stdio.h>
#include<stdlib.h>

struct food {
	char name[20];
	int price;
}food[MAX];

int find_index(struct food*, char* name);
void insert(struct food*);
void print(struct food*);
void delete(struct food*);
void update(struct food*);
void file_save(struct food*);
void file_load(struct food*);

int main() {
	struct food* f = malloc(sizeof(food[MAX]));
	int n;
	int t = 0;
	int num = 0;
	do {
		printf("\n<<1.추가 2.삭제 3.수정 4.목록 5.파일 로드 6.저장 7.종료>>\n");
		printf("==>메뉴선택 : ");
		scanf("%d", &n);
		printf("\n");

		switch (n) {
		case 1: {
			insert(&f[num]);
			num++;
			break;
		}

		case 2: {
			char fn[MAX];
			printf("삭제할 음식 제목을 입력하세요.");
			scanf("%s", fn);
			int count = find_index(f, fn);

			f[num].price = 0;
			delete(&f[count]);
			for (int i = count; i < num - 1; i++) {
				strcpy(f[i].name, f[i + 1].name);
				f[i].price = f[i + 1].price;
			}
			num--;
			break;
		}

		case 3: {
			char fn[MAX];
			printf("수정할 음식 제목을 입력하세요.");
			scanf("%s", fn);

			int count = find_index(f, fn);
			update(&f[count]);
			break;
		}

		case 4: {
			f[num].price = 0;
			print(f);
			break;
		}

		case 5: {
			file_load(f);
			break;
		}

		case 6: {
			f[num].price = 0;
			file_save(f);
			break;
		}

		case 7: {
			printf("\n종료합니다.");
			t++;
			break;
		}

		default:
			printf("\n잘못된 입력입니다.\n");
		}
	} while (t == 0);

	return 0;
}

void insert(struct food* f) {
	char fn[MAX];
	int fp;
	printf("음식 이름을 입력하세요: ");
	scanf("%s", fn);
	strcpy(f->name, fn);

	printf("음식 가격을 입력하세요: ");
	scanf("%d", &fp);
	f->price = fp;
}

int find_index(struct food* f, char* name) {
	int cnt = 0;
	for (int i = 0; i < MAX; i++) {
		if (strcmp(f[i].name, name) == 0) {
			cnt = i;

			break;
			

		}

	}
	return cnt;
}

void delete(struct food* f) {
	strcpy(f->name, "\0");
	f->price = 0;

}




void update(struct food* f) {
	int p;
	printf("수정할 가격을 입력하세요: ");
	scanf("%d", &p);
	f->price = p;
}

void print(struct food* f) {
	printf("		<<음식 정보 출력>>\n\n");
	for (int i = 0; i < MAX; i++) {
		if (f[i].price == 0) {
			break;
		}
		printf("이름: %s, 가격: %d\n", f[i].name, f[i].price);
	}

}
void file_save(struct food* f) {
	FILE* f1;
	if (fopen_s(&f1, "food.txt", "w") != 0) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	for (int i = 0; i < MAX; i++) {
		if (f[i].price == 0) {
			break;
		}
		fprintf(f1, "%s %d", f[i].name, f[i].price);
		fprintf(f1, "\n");
	}
	fclose(f1);
}

void file_load(struct food* f) {
	FILE* f2;
	if (fopen_s(&f2, "food.txt", "w") != 0) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}
	for (int i = 0; i < MAX; i++) {

		fscanf(f2, "%s %d", f[i].name, f[i].price);

	}
	fclose(f2);
}