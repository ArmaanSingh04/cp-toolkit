#include <bits/stdc++.h>
using namespace std;

int main(){

    auto checkprime = [](int n) -> bool{
        if(n == 0 || n == 1) return false;

        for(int i=2 ; i*i<=n ; i++){
            if(n%i == 0){
                return false;
            }
        }

        return true;
    };

    cout << checkprime(2) << endl;
    return 0;
}