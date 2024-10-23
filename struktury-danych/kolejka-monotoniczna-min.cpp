#include<bits/stdc++.h>

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
    	assert(!que.empty());
        if (que.front().second == 0) {
            que.pop_front();
        } else {
            que.front().second--;
        }
    }

    T min(){
    	assert(!que.empty());
        return que.front().first;
    }
};


