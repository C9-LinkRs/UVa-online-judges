#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const int &i, const int &j){
    if(i > j) return true;
    return false;
}

int main(){
    int tc, n, m, time, priority, indexPP;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &m);
        queue<pair<int, bool>> cola;
        vector<int> printPriority;
        for(int i = 0; i < n; i++){
            cin >> priority;
            if(i == m) cola.push(make_pair(priority, true));
            else cola.push(make_pair(priority, false));
            printPriority.push_back(priority);
        }
        time = 0;
        indexPP = 0;
        sort(printPriority.begin(), printPriority.end(), cmp);
        while(!cola.empty()){
            int prior = cola.front().first;
            bool myJob = cola.front().second;
            cola.pop();
            if(prior == printPriority[indexPP]){
                time++;
                if(myJob) break;
                indexPP++;
            }else cola.push(make_pair(prior, myJob));
        }
        printf("%d\n", time);
    }
    return 0;
}
/*
    La estrategia es usar un vector y una queue, el vector me tiene organizado las prioridades y en la queue guardo
    las prioridades tambien, esta a su vez la inicializo con pair para guardar un booleano a cada prioridad y asi
    identificar "my job". El vector lo organizo de la mayor prioridad a la menor.
*/