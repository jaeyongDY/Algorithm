#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>

using namespace std;

#define MAX 1000000;

int bfs(int start, map<int, vector<int>>& graph);

int main() {

    int N, M;

    cin >> N;
    cin >> M;

    map<int, vector<int>> graph;

    int minValue = MAX;

    int resutlperson = -1;

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(const auto& data : graph) {
        int value = bfs(data.first, graph);
        if(value < minValue) {
            minValue = value;
            resutlperson = data.first;
        }
    }

    cout << resutlperson << endl;
    return 0;
}

int bfs(int start, map<int, vector<int>>& graph) {

    queue<int, list<int>> _queue;
    
    vector<int> visitDist(graph.size()+1, -1);

    _queue.push(start);
    if(start > 0) {
        visitDist[start] = 0;
    }

    int cnt = 0;
    int currentCnt = 0;
    
    map<int, int> tempdata;

    while(!_queue.empty()) {
        int data = _queue.front();
        _queue.pop();
        vector<int> _data = graph[data];
        
        for(const auto& d : _data) {
            if(visitDist[d] == -1) {
                visitDist[d] = visitDist[data] + 1;
                _queue.push(d);
            }
        }
    }
    for(const auto& dist : visitDist) {
        cnt += dist;
    }
    return cnt;
}
