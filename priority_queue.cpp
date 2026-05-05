#include <queue>
#include <iostream>
#include <vector>

using namespace std;

// write the compare function like this
struct compare {
    bool operator()(const pair<int,int> & a , const pair<int,int> & b){
        if(a.first == a.second){
            return a.second > b.second; // ascending order of second
        }
        return a.first < b.first; // descending order of first
    }
};

int main(){

    cout << "Default priority queue " << endl;

    // by default behaves as max heap
    priority_queue<int> p;
    p.push(3);
    p.push(1);
    p.push(2);
    p.push(4);


    while(!p.empty()){
        cout << p.top() << endl;
        p.pop();
    }

    cout << "Custom priority queue with custom comparator function" << endl;
    
    priority_queue<pair<int, int> , vector<pair<int,int>> , compare> pq;
    
    pq.push({1, 2});
    pq.push({1, 2});
    pq.push({2, 3});
    pq.push({3, 0});
    pq.push({3, 2});

    while (!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}