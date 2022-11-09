using namespace std;
#include <iostream>
#include <vector>
#include <omp.h>

vector<int> simple_vec_sum(const vector<int>& a, const vector<int>& b, int n){
    vector<int> rez(n);

    double start; 
    double end; 

    start = omp_get_wtime(); 

    for (int i = 0; i < n; ++i) {
        rez[i] = a[i]+b[i];
    }

    end = omp_get_wtime(); 

    cout << "Simple work took " << end - start << " seconds" << endl;
    return(rez);
}

vector<int> parallel_vec_sum(const vector<int>& a, const vector<int>& b, int n){
    vector<int> rez(n);

    double start; 
    double end; 

    start = omp_get_wtime();

    #pragma omp parallel for
        for (int i = 0; i < n; ++i) {
            rez[i] = a[i]+b[i];
        }

    end = omp_get_wtime(); 

    cout << "Parallel work took " << end - start << " seconds" << endl;
    return(rez);
}

void is_vec_match(const vector<int>& rez1, const vector<int>& rez2){
    int f = 1;

    if (rez1.size() != rez2.size()) {
        cout << "Vectors don`t match" << endl;
        return;
    }

    for (int i=0; i<rez1.size(); ++i){
        if (rez1[i] != rez2[i]){
            f = 0;
        }
    }
    if (f){
        cout << "Vectors match" << endl;
    } else {
        cout << "Vectors don`t match" << endl;
    }
}

vector<int> simple_matr_mult(const vector<int>& a, const vector<int>& b, int n){
    vector<int> rez(n * n);
    int running_sum;
    double start; 
    double end; 

    start = omp_get_wtime();

    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            running_sum = 0;
            for (int k=0; k<n; ++k){
                running_sum = running_sum + a[i*n + k] *b [j + k*n];
            }
            rez[i*n + j] = running_sum;
        }
    }
    end = omp_get_wtime(); 

    cout << "Simple work took " << end - start << " seconds" << endl;
    return rez;
}

vector<int> parallel_matr_mult(const vector<int>& a, const vector<int>& b, int n){
    vector<int> rez(n * n);
    int running_sum;
    double start; 
    double end; 

    start = omp_get_wtime();

    #pragma omp parallel for shared(a, b, rez)
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            running_sum = 0;
            for (int k=0; k<n; ++k){
                rez[i*n + j] += running_sum + a[i*n + k] * b [j + k*n];
            }
        }
    }
    end = omp_get_wtime(); 

    cout << "Parallel work took " << end - start << " seconds" << endl;
    return rez;
}

void is_matr_match(const vector<int>& rez1, const vector<int>& rez2){
    int f = 1;

    if (rez1.size() != rez2.size()) {
        cout << "Matrices don`t match" << endl;
        return;
    }

    for (int i=0; i < rez1.size(); ++i){
        if (rez1[i] != rez2[i]){
            f = 0;
        }
    }

    if (f){
        cout << "Matrices match" << endl;
    } else {
        cout << "Matrices don`t match" << endl;
    }
}