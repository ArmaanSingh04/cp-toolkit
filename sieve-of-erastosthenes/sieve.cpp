// find all prime number from 1 - n
// sieve algorithm does it in O(n * log2(log2(n)))

#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<bool> sieve(int n){
    // n + 1 coz it will contain the nth index
    vector<bool> primes(n+1 , true); 
    primes[0] = false;
    primes[1] = false;


    for(int i=2 ; i*i<=n ; i++){
        if(primes[i] == true){
            // a loop to make all the multiples false
            for(int j=i*i ; j<=n ; j+=i){
                primes[j] = false;
            }
        }
    }
    return primes;
}

int main(){
    int n;
    cin >> n;

    vector<bool> primes = sieve(n);
    for(int i=1; i<=n ; i++){
        if(primes[i] == true){
            cout << i << " ";
        }
    }
    return 0;
}