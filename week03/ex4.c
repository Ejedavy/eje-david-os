#include <stdio.h>
#include <stdlib.h>

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b) {
	void* output;
        int sum = *((int*) a) + *((int*) b);
        output = &sum;
        return output;
}

void* addDouble(const void* a, const void* b) {
	void* output;
        double sum = *((double*) a) + *((double*) b);
        output = &sum;
        return output;
}

void* mulInt(const void* a, const void* b) {
	void* output;
        int product = *((int*) a) * *((int*) b);
   	output = &product;
	return output;
}

void* mulDouble(const void* a, const void* b) {
	void* output;
        double product = *((double*) a) * *((double*) b);
        output = &product;
        return output;
}

void* meanInt(const void *a, const void* b) {

}

void* meanDouble(const void* a, const void* b) {

}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)) {
        void* ans;
        if (size == sizeof(int)) { // base is a pointer to an integer
                if (opr == meanInt) {
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
                if (opr == meanDouble) {
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
        const int n = 5;
        int* ints = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
                *(ints + i) = 2 * (i + 1); 
        }
        
        double* doubles = malloc(sizeof(double) * n);
        for (int i = 0; i < n; i++) {
                *(doubles + i) = 3.5 * (i + 1);
	}


        int add_int_initial_value = 0;
        int* add_int_initial = &add_int_initial_value;

        double add_double_initial_value = 0.0;
        double* add_double_initial = &add_double_initial_value;

        int mul_int_initial_value = 1;
        int* mul_int_initial = &mul_int_initial_value;

        double mul_double_initial_value = 1.0;
        double* mul_double_initial = &mul_double_initial_value;

        // Addition
        int* result1a = aggregate(ints, sizeof (int), n, add_int_initial, &addInt);
        printf("%d\n", *result1a);

        double* result2a = aggregate(doubles, sizeof (double), n, add_double_initial, &addDouble);
        printf("%f\n", *result2a);

        // Multiplication
        int* result1m = aggregate(ints, sizeof (int), n, mul_int_initial, &mulInt);
        printf("%d\n", *result1m);
        double* result2m = aggregate(doubles, sizeof (double), n, mul_double_initial, &mulDouble);
        printf("%f\n", *result2m);

        // Mean
        int* result1mean = aggregate(ints, sizeof (int), n, add_int_initial, &meanInt);
        printf("%d\n", *result1mean);
        double* result2mean = aggregate(doubles, sizeof (double), n, add_double_initial, &meanDouble);
        printf("%f\n", *result2mean);

        // Free pointers

        free(ints);
        free(doubles);

        return EXIT_SUCCESS;
}
