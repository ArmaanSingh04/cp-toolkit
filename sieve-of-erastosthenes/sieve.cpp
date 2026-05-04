// find all prime number from 1 - n
// sieve algorithm does it in O(n * log2(log2(n)))

#include <bits/stdc++.h>
#define ll long long

using namespace std;

/*
This function is a advanced implementation of sieve
the initial vector assignment takes O(n) 
but the calculation takes O(n log(log(n)))
*/

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

    /*
    This function is simple to understand and basic concept of sieve
    This takes O(n) to initially assign the values to 1
    and then O(n) to calculate the values
    */
    auto basicSieve = [](int n) -> vector<bool>{
        vector<bool> primes(n+1 , 1); 

        primes[0] = false;
        primes[1] = false;

        for(int i=2 ; i<=n ; i++){
            if(primes[i] == true){
                for(int j=2*i ; j<=n ; j += i){
                    primes[j] = false;
                }
            }
        }

        return primes;
    };

    vector<bool> primes = basicSieve(n);
    for(int i=1; i<=n ; i++){
        if(primes[i] == true){
            cout << i << " ";
        }
    }
    return 0;
}