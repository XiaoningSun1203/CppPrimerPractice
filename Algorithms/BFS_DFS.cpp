/**
 * bilibili上深度搜索与广度搜索的练习
 * 创建一个容器用来装曾经出现过的元素，可以是个set
 * while（队列不为空）：
 *     vertex = 队列头元素
 *     pop（队列头元素）；
 *     塞入vertex的邻接点（保证这些邻接点没有出现过），且放进seen中
 */
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

void BFS(map<char, string> &graph, char start){
    set<char> seen;     //seen用来放“曾经进过队列”的元素
    queue<char> que;
    //首先把人为选中的root放入seen和队列中
    que.push(start);
    seen.insert(start);
    
    while(!que.empty()){
        char vertex = que.front();  //把队列“头元素”保存在vertex后再弹出
        que.pop();                  
        for(const char point : graph[vertex]){   //把邻接点（未进过队列）塞入队列中
            if(seen.find(point) == seen.end()){
                que.push(point);
                seen.insert(point);    //把这些邻接点记录为“已进过”
            }
        }
        cout << vertex <<"->";    //A->B->C->D->E->F->
    }
}
int main(){
    std::map<char, string> graph = {
        {'A', "BC"},
        {'B', "ACD"},
        {'C', "ABDE"},
        {'D', "BCEF"},
        {'E', "CD"},
        {'F', "D"}
    };
    char start = 'A';
    BFS(graph, start);
    return 0;
}

void DFS(map<char, string> &graph, char start){
    set<char> seen;     //seen用来放“曾经进过栈”的元素
    stack<char> stk;
    //首先把人为选中的root放入seen和栈stk中
    stk.push(start);
    seen.insert(start);
    
    while(!stk.empty()){
        char vertex = stk.top();  //把stk“头元素”保存在vertex后再弹出
        stk.pop();                  
        for(const char point : graph[vertex]){   //把邻接点（未进过栈）塞入stk中
            if(seen.find(point) == seen.end()){
                stk.push(point);
                seen.insert(point);    //把这些邻接点记录为“已进过”
            }
        }
        cout << vertex <<"->";    //A->C->E->D->F->B->
    }
}

void runDFSExample(){
    std::map<char, string> graph = {
        {'A', "BC"},
        {'B', "ACD"},
        {'C', "ABDE"},
        {'D', "BCEF"},
        {'E', "CD"},
        {'F', "D"}
    };
    char start = 'A';
    DFS(graph, start);
    return;
}

// //g++ main.cpp --std=c++11
