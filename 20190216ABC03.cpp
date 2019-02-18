#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

//ユークリッドの互除法
int gcd(int A, int B){
    int temp = 0;
    if(B > A){
        temp = A;
        A = B;
        B = temp;
    }
    if(A % B == 0){
        return B;
    }else{
        return gcd(B , A % B);
    }
}

//int moreGcd

int main(){

    int N = 0;
    cin >> N;

    vector<int> A(N, 0);

    int temp = 0;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    std::sort(A.begin(),A.end());

    if(N == 2){
        cout << gcd(A[0], A[1]);
    }else{
        for(int i = N - 1; i > 0; i--){
            //cout << i - 1;
            if(i == N - 1){
                temp = gcd(A[i], A[i - 1]);
            }else{
                temp = gcd(A[i - 1], temp);
            }
            //std::cout << temp << std::endl;
        }
        cout << temp;
    }

}