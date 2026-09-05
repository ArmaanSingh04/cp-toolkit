#include <bits/stdc++.h>

using namespace std;

/*
Its very simple
divide the array from low -> mid , mid+1 -> high
call the same function to sort both the arrays

then just merge the two sorted arrays
*/

void merge(vector<int> & arr , int low , int mid , int high){
    vector<int> temp;
    int i=low , j=mid+1;

    while(i<=mid && j<=high){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }

    int index = 0;
    for(int i=low ; i<=high ; i++){
        arr[i] = temp[index];
        index++;
    }
}

void merge_sort(vector<int> & arr , int low , int high){
    if(low == high){
        return;
    }

    int mid = (low + high) /2;
    merge_sort(arr , low , mid);
    merge_sort(arr , mid+1 , high);

    // merge the array
    merge(arr , low , mid , high);
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0 ; i<n ; i++) cin >> arr[i];

    merge_sort(arr , 0 , n-1);

    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
}