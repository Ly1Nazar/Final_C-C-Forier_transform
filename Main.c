#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#define N 3
#define pi 3.14159265358979
void input() {
    FILE* filepoint;
    errno_t err,err_2;
    if ((err = fopen_s(&filepoint, "im_input.txt", "w")) != 0) {
        printf("error of openning");
    }
    else {
        srand(11);
        char v1;
        for (int i = 0; i < N; i++) {
            v1 = rand()%10;
            fprintf(filepoint,"%d\n", v1);
        }
        fclose(filepoint);
    }
    FILE* filepoint2;
    if ((err_2 = fopen_s(&filepoint2, "re_input.txt", "w")) != 0) {
        printf("error of openning");
    }
    else {
        srand(15);
        char v2;
        for (int i = 0; i < N; i++) {
            v2 = rand() % 10;
            //printf("v2 = %d\n", v2);
            fprintf(filepoint2, "%d\n", v2);
        }
        fclose(filepoint2);
    }
}

double* get_data(int a) {
    if (a == 0) {
        FILE* filepoint;
        char str[N];
        static double real[N];
        char* estr;
        errno_t err;
        int j = 0;
        err = fopen_s(&filepoint, "re_input.txt", "r");
        if ((err) != 0) {
            printf("err");
        }
        else {
            if (filepoint == NULL) { printf("error1\n"); return -1; }
            while (1)
            {
                estr = fgets(str, sizeof(str), filepoint);
                if (estr == NULL)
                {
                    if (feof(filepoint) != 0)
                    {
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                sscanf_s(str, "%lf", &real[j]);
                //real[j] = atoi(str);convert to str -> int 
                j++;
            }
        }
        fclose(filepoint);
        return real;
    }
    else if (a == 1) {
        FILE* filepoint2;
        char str2[N];
        static double imag[N];
        char* estr_2;
        errno_t err_2;
        int j1 = 0;
        err_2 = fopen_s(&filepoint2, "im_input.txt", "r");
        if ((err_2) != 0) {
            printf("err_2");
        }
        else {
            if (filepoint2 == NULL) { printf("error1\n"); return -1; }
            while (1)
            {
                estr_2 = fgets(str2, sizeof(str2), filepoint2);
                if (estr_2 == NULL)
                {
                    if (feof(filepoint2) != 0)
                    {
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                imag[j1] = atoi(str2);
                j1++;
            }
        }
        fclose(filepoint2);
        return imag;
    }
    else if (a == 2) {
        FILE* filepoint3;
        char str3[N];
        static double fo_imag[N];
        char* estr_3;
        errno_t err_3;
        int j1 = 0;
        err_3 = fopen_s(&filepoint3, "im_fourie.txt", "r");
        if ((err_3) != 0) {
            printf("err_3");
        }
        else {
            if (filepoint3 == NULL) { printf("error1\n"); return -1; }
            else printf("done\n");
            while (1)
            {
                estr_3 = fgets(str3, sizeof(str3), filepoint3);
                if (estr_3 == NULL)
                {
                    if (feof(filepoint3) != 0)
                    {
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                fo_imag[j1] = atoi(str3);
                j1++;
            }
        }
        fclose(filepoint3);
        return fo_imag;
    }
    else if (a == 3) {
    FILE* filepoint4;
    char str4[N];
    static double fo_real[N];
    char* estr_4;
    errno_t err_4;
    int j1 = 0;
    err_4 = fopen_s(&filepoint4, "re_fourie.txt", "r");
    if ((err_4) != 0) {
        printf("err_4");
    }
    else {
        if (filepoint4 == NULL) { printf("error1\n"); return -1; }
        else printf("done\n");
        while (1)
        {
            estr_4 = fgets(str4, sizeof(str4), filepoint4);
            if (estr_4 == NULL)
            {
                if (feof(filepoint4) != 0)
                {
                    break;
                }
                else
                {
                    break;
                }
            }
            fo_real[j1] = atoi(str4);
            j1++;
        }
    }
    fclose(filepoint4);
    return fo_real;
    }
}

void Forier() {
    int a;
    double* point = get_data(a = 0);
    double* point2 = get_data(a = 1);
    double real[N], imag[N];
    errno_t err;
    FILE* im_Fur;
    err = fopen_s(&im_Fur, "im_fourie.txt", "w");
    errno_t err2;
    FILE* re_Fur;
    err = fopen_s(&re_Fur, "re_fourie.txt", "w");
    if (err != 0) {
        printf("error occured");
    }
    for (int i = 0; i < N; i++) {
        real[i] = *(point + i); 
        imag[i] = *(point2 + i);
    }
    for (int k = 0; k < N; k++) {
        double result = 0;
        double Imag_result = 0;
        for (int n = 0; n < N; n++) {
            double temp_re = 0;
            double temp_im = 0;
            temp_re = real[n] * cos(2 * pi * k * n / N) + imag[n] * sin(2 * pi * k * n / N);
            temp_im = imag[n] * cos(2 * pi * k * n / N) - real[n] * sin(2 * pi * k * n / N);
            result += temp_re;
            Imag_result += temp_im;
        }
        fprintf(re_Fur, "%lf\n", result);
        fprintf(im_Fur, "%lf\n", Imag_result);
    }
    fclose(re_Fur);
    fclose(im_Fur);
}

void rev_Forier() {
    double* ipoint = get_data(2);
    double* rpoint = get_data(3);
    double real[N], imag[N];
    errno_t err;
    FILE* im_rev;
    err = fopen_s(&im_rev, "im_rev.txt", "w");
    errno_t err2;
    FILE* re_rev;
    err2 = fopen_s(&re_rev, "re_rev.txt", "w");
    if (err != 0) {
        printf("error occured");
    }

    for (int i = 0; i < N; i++) {
        real[i] = *(rpoint + i);
        imag[i] = *(ipoint + i);
    }
    for (int k = 0; k < N; k++) {
        double re_result = 0;
        double Imag_result = 0;
        for (int n = 0; n < N; n++) {
            double temp_re = 0;
            double temp_im = 0;
            temp_re = real[n] * cos(2 * pi * k * n / N) + imag[n] * sin(2 * pi * k * n / N);
            printf("\ntempre =%lf\n", temp_re);
            temp_im = imag[n] * cos(2 * pi * k * n / N) - real[n] * sin(2 * pi * k * n / N);
            re_result += (temp_re / N);
            printf("reres %lf\n", re_result);
            Imag_result += (temp_im / N);
            printf("%lf\n", Imag_result);
        }
        fprintf(re_rev, "%lf\n", re_result);
        fprintf(im_rev, "%lf\n", Imag_result);
    }
    fclose(re_rev);
    fclose(im_rev);
}

int main() {
	//srand(time(NULL));
	input();
	Forier();
	rev_Forier();
}
