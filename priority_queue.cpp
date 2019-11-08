#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <initializer_list>

using namespace std;

struct Node {
    int value;
    int idx;
    Node (int v, int i): value(v), idx(i) {}
    friend bool operator < (const struct Node &n1, const struct Node &n2) ; 
};

inline bool operator < (const struct Node &n1, const struct Node &n2) {
    return n1.value < n2.value;
}

priority_queue<Node> maxHeap; // 此时pq为最大堆


struct Node2 {
    int value;
    int idx;
    Node2 (int v, int i): value(v), idx(i) {}
//  friend bool operator < (const struct Node2 &n1, const struct Node2 &n2) ;
    friend bool operator > (const struct Node2 &n1, const struct Node2 &n2) ;
}; 

inline bool operator > (const struct Node2 &n1, const struct Node2 &n2) {
    return n1.value > n2.value;
}

priority_queue<Node2, vector<Node2>, greater<Node2> > minHeap; // 此时greater会调用 > 方法来确认Node的顺序，此时pq是最小堆


template <typename T> void print_queue(T& q){
    while(!q.empty()){
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

// maxHeap.push( -1 * v1) ; //
// maxHeap.push( -1 * v2) ; //
// maxHeap.push( -1 * v3) ; // 分别是插入v1, v2, v3变量的相反数，那么pq其实也就变相成为了最小堆，只是每次从pq取值后，要再次乘以-1即可


int main() {
    std::priority_queue<int> q;
 
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);
 
    print_queue(q);
 
    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
 
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);
 
    print_queue(q2);
 
    // 用 lambda 比较元素。
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
 
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q3.push(n);
 
    print_queue(q3);
 
}


/*
9 8 7 6 5 4 3 2 1 0 
0 1 2 3 4 5 6 7 8 9 
8 9 6 7 4 5 2 3 0 1
*/