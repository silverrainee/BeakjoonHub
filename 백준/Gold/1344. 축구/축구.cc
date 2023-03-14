#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int prime[7] = {2,3,5,7,11,13,17};
    double a_arr[7] = {};
    double b_arr[7] = {};
    
    double a,b; cin >> a >> b;
    for(int i=0; i<7; i++){
        a_arr[i] = pow((a/100), prime[i]) * pow((1 - a/100), 18 - prime[i]);
        b_arr[i] = pow((b/100), prime[i]) * pow((1 - b/100), 18 - prime[i]);
        for(int c = 1; c <= prime[i]; c++){
            a_arr[i] *= 19 - c; a_arr[i] /= c;
            b_arr[i] *= 19 - c; b_arr[i] /= c;
        }
    }

    double A = 0; double B = 0;
    for(int i=0; i<7; i++){
        A += a_arr[i];
        B += b_arr[i];
    }

    printf("%.10f", 1 - (1 - A)*(1 - B));
}