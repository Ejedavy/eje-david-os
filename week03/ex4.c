#include <stdio.h>
#include <stdlib.h>

void* aggregate(void* base, size_t size, int n, void* initial_value,
                void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b) {
        int sum = *((int*) a) + *((int*) b);
        int* ret = &sum;
        return (void*) ret;
}

void* addDouble(const void* a, const void* b) {
        double sum = *((double*) a) + *((double*) b);
        double* ret = &sum;
        return (void*) ret;
}

void* mulInt(const void* a, const void* b) {
        int product = *((int*) a) * *((int*) b);
        int* ret = &product;
        return (void*) ret;
}

void* mulDouble(const void* a, const void* b) {
        double product = *((double*) a) * *((double*) b);
        double* ret = &product;
        return (void*) ret;
}

void* mean() {

}

void* aggregate(void* base, size_t size, int n, void* initial_value,
                void* (*opr)(const void*, const void*)) {
        void* ans;
        if (size == sizeof(int)) { // base is a pointer to an integer
                if (opr == mean) {
                        ans = aggregate(base, size, n, initial_value, &addInt);
                        int ret = *((int*) ans) / n;
                        ans = &ret;
                } else {
                        int initial = *((int*) initial_value);
                        ans = &initial;
                        for (int i = 0; i < n; i++) {
                                ans = opr(ans, ((int*) base + i));
                        }
                }
        }  else {
                if (opr == mean) {
                        ans = aggregate(base, size, n, initial_value, &addDouble);
                        double ret = *((double*) ans) / n;
                        ans = &ret;
                } else {
                        double initial = *((double*) initial_value);
                        ans = &initial;
                        for (int i = 0; i < n; i++) {
                                ans = opr(ans, ((double*) base + i));
                        }
                }
        }
        return ans;
}


int main() {
        int n = 5;

        int* ints = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
                *(ints + i) = i + 1; // 1, 2, 3, 4, 5, ...

        double* doubles = malloc(sizeof(double) * n);
        for (int i = 0; i < n; i++)
                *(doubles + i) = i + 2.0; // 2.0, 3.0, 4.0, 5.0, 6.0, ...

        int add_int_initial_value = 0;
        int* add_int_initial = &add_int_initial_value;

        double add_double_initial_value = 0.0;
        double* add_double_initial = &add_double_initial_value;

        int mul_int_initial_value = 1;
        int* mul_int_initial = &mul_int_initial_value;

        double mul_double_initial_value = 1.0;
        double* mul_double_initial = &mul_double_initial_value;

        // Addition

        int* result1a = aggregate(ints, sizeof (int), n,
                                  add_int_initial, &addInt);
        printf("%d\n", *result1a);

        double* result2a = aggregate(doubles, sizeof (double), n,
                                     add_double_initial, &addDouble);
        printf("%f\n", *result2a);

        // Multiplication

        int* result1m = aggregate(ints, sizeof (int), n,
                                  mul_int_initial, &mulInt);
        printf("%d\n", *result1m);

        double* result2m = aggregate(doubles, sizeof (double), n,
                                     mul_double_initial, &mulDouble);
        printf("%f\n", *result2m);

        // Mean

        int* result1mean = aggregate(ints, sizeof (int), n,
                                     add_int_initial, &mean);
        printf("%d\n", *result1mean);

        double* result2mean = aggregate(doubles, sizeof (double), n,
                                        add_double_initial, &mean);
        printf("%f\n", *result2mean);

        // Free pointers

        free(ints);
        free(doubles);

        return EXIT_SUCCESS;
}
