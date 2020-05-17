#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#define N 3
void input() {
	FILE* filepoint;
	FILE* filepoint2;
	errno_t err,err2;
	//randomise();
	if ((err = fopen_s(&filepoint, "re_input.txt", "w")) != 0) {
		printf("error occured");
	}
	else {
		for (int i = 0; i < N; i++) {
			int a = rand(20);
			fprintf(filepoint, a);
		}
	}
	fclose(filepoint);

	if ((err2 = fopen_s(&filepoint2, "im_input.txt", "w")) != 0) {
		printf("errror");
	}
	else {
		for (int j = 0; j < N; j++) {
			int b = rand(20);
			fprintf(filepoint2, b);
		}
		fclose(filepoint2);
	}
	
}
void Forier() {
	int res = 0;
}
void rev_Forier() {
	int res = 0;
}
void output() {
	int res = 0;
}

int main() {
	//srand(time(NULL));
	input();
	Forier();
	rev_Forier();
	output();
}