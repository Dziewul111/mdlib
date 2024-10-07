#include<bits/stdc++.h>
using namespace std;

template<class T> 
class kolejka_monotoniczna_min{
	deque<pair<T, int>> que;
public:
    void push(T x){
        int cnt = 0;
        while(!que.empty() && que.back().first >= x){
            cnt += que.back().second + 1;
            que.pop_back();
        }
        que.push_back({x, cnt});
    }

    void pop(){
        if (que.front().second == 0) {
            que.pop_front();
        } else {
            que.front().second--;
        }
    }

    T max(){
        return que.front().first;
    }
};

int main(){
}
