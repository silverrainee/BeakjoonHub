#include<iostream>

using namespace std;

int main() {
    char num[41];
    cin >> num;

    int dp[41] = {}; int i = 0;
    for(i = 0; num[i] != '\0'; i++){
        if(i >= 1){
            if(num[i - 1]!= '0' && ((num[i - 1] == '3' && num[i] <= '4') || num[i - 1] < '3')){
                if(i == 1) dp[i]++;
                else dp[i] += dp[i - 2];
            }
        }
        if(i >= 0){
            if(num[i] != '0'){
                if(i == 0) dp[i]++;
                else dp[i] += dp[i - 1];
            }
        }
    }

    cout << dp[i - 1];
}