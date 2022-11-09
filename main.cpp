using namespace std;
#include <iostream>
#include <vector>
#include <omp.h>
#include "source/func.hpp"


int main(int argc, char* argv[])
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 1000 + 1;
        b[i] = rand() % 1000 + 1;
    }

    vector<int> rez1 = simple_vec_sum(a, b, n);
    vector<int> rez2 = parallel_vec_sum(a, b, n);
    is_vec_match(rez1, rez2);


    a = vector<int>(m * m);
    b = vector<int>(m * m);

    for (int i = 0; i < m * m; ++i) {
        a[i] = rand() % 1000 + 1;
        b[i] = rand() % 1000 + 1;
    }

    rez1 = simple_matr_mult(a, b, m);
    rez2 = parallel_matr_mult(a, b, m);
    is_matr_match(rez1, rez2);
}