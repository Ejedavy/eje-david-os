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


        int addition_int_init_v = 0;
        int* addition_integer_init = &addition_int_init_v;

        double addition_double_init_v = 0.0;
        double* addition_double_init = &addition_double_init_v;

        int multiplication_integer_init_v = 1;
        int* multiplication_integer_init = &multiplication_integer_init_v;

        double multiplication_double_init_v = 1.0;
        double* multiplication_double_init = &multiplication_double_init_v;

        // Addition
        int* result_of_addition_int = aggregate(ints, sizeof (int), n, addition_integer_init, &addInt);
        printf("%d\n", *result_of_addition_int);

        double* result_of_addition_double = aggregate(doubles, sizeof (double), n, addition_double_init, &addDouble);
        printf("%f\n", *result_of_addition_double);

        // Multiplication
        int* result_of_multiplication_int = aggregate(ints, sizeof (int), n, multiplication_integer_init, &mulInt);
        printf("%d\n", *result_of_multiplication_int);
        double* result2m = aggregate(doubles, sizeof (double), n, multiplication_double_init, &mulDouble);
        printf("%f\n", *result2m);

        // Mean
        int* result_of_mean_int = aggregate(ints, sizeof (int), n, addition_integer_init, &meanInt);
        printf("%d\n", *result_of_mean_int);
        double* result_of_mean_double = aggregate(doubles, sizeof (double), n, addition_double_init, &meanDouble);
        printf("%f\n", *result_of_mean_double);

        // Free pointers

        free(ints);
        free(doubles);

        return EXIT_SUCCESS;
}
