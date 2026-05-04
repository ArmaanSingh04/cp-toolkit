// Helps to calculate a^b
#include <bits/stdc++.h>
using namespace std;

int main(){

    auto binaryExponentiation = [](int a , int b) -> int{
        // NOTE: this is not handle -ve values of b
        // for that use this as 5^-2 ==> 1/(5^2)
        // you can find 5^2 using this

        if(b == 0) return 1;

        int ans = 1;
        while(b > 0){
            if(b%2 == 0){
                a = a * a;
                b = b/2;
            }
            else{
                ans = ans * a;
                b = b -1;
            }
        }

        return ans;
    };

    cout << binaryExponentiation(2, 6) << endl;
    return 0;
}