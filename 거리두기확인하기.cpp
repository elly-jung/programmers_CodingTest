
#include <string>
#include <vector>
#include <queue>
#include<utility>
using namespace std;
int arr[5][5];
int check[5][5];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
typedef struct {
    int x;
    int y;
    int count;
}stMove;
void checkInit() {
    for (int j = 0; j < 5; j++) {
        for (int z = 0; z < 5; z++) {
            check[j][z] = 0;
        }
    }
}
void init(vector<vector<string>>& places, int tc_count) {
    checkInit();
    for (int j = 0; j < 5; j++) {
        for (int z = 0; z < 5; z++) {
            if (places[tc_count][j][z] == 'P')arr[j][z] = 0;
            else if (places[tc_count][j][z] == 'O')arr[j][z] = 1;
            else if (places[tc_count][j][z] == 'X')arr[j][z] = 2;
        }
    }
}
int bfs_fun(int x,int y) {
    checkInit();
    queue<stMove>qu;
    stMove cur = { x,y,0 };
    qu.push(cur);
    check[x][y] = 1;

    while (!qu.empty()) {
        stMove temp=qu.front();
        
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int tx = temp.x+dx[i];
            int ty = temp.y+dy[i];
            int cur_count = temp.count;
            stMove NewTemp={ tx ,ty,cur_count+1};
            if (tx < 0 || ty < 0 || tx >= 5 || ty >= 5) continue;
            if (check[tx][ty] == 1) continue;
            if (arr[tx][ty] == 1) { //ºó°ø°£¸¸³µÀ»¶© queue¿¡ ³Ö±â
                qu.push(NewTemp);
            }
            else if (arr[tx][ty] == 0) {//»ç¶÷¸¸³µÀ»¶©
                if ((cur_count+1) <= 2) {
                    return 0;
                }
            }
            check[tx][ty] = 1;
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer_result;
    for (int t = 0; t < places.size(); t++) {
        init(places, t);
        int result = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (arr[i][j] == 0) { //p, »ç¶÷ÀÏ ¶§
                    result &= bfs_fun(i,j);
                }
            }
        }
        answer_result.push_back(result);
    }
    return answer_result;
}
/*
int main() {
    vector<int> answer;
    vector<vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"} ,
                                      {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                      {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                      {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                      {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
    answer = solution(places);
    for (int i = 0; i < places.size(); i++) {
        printf("%d ", answer[i]);
    }
    solution(places);
    return 0;
}*/