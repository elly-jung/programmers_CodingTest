#include <vector>

using namespace std;
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { -1,1,0,0 };
int useArea[100][100] = { 0, };
int usernumbercount = 0;
int temp = 0;
int arr[100][100] = { 0, };
int checkarea(int a, int b, int m, int n) {
    return (a >= 0) && (b >= 0) && (a < m) && (b < n);
}
void init() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            useArea[i][j] = 0;
        }
    }
}
void copyarea(vector<vector<int>> picture, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = picture[i][j];
        }
    }
}
void dfsfun(int x, int y, int number, int m, int n) {
    if (checkarea(x, y, m, n) != 1) return;
    if (arr[x][y] == 0) return;
    if (useArea[x][y]) return;
    temp++;
    useArea[x][y] = 1;
    for (int  i= 0; i < 4; i++) {
        int newx = x + dx[i], newy = y + dy[i];
        if (checkarea(newx, newy, m, n) == 0)continue;
        if (arr[newx][newy] == number) {
            dfsfun(newx, newy, number, m, n);
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);
    copyarea(picture, m, n);
    init();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            temp = 0;
            if ((useArea[i][j] == 0) && (picture[i][j] != 0)) {
                usernumbercount++;
                //usenumberYN(picture[i][j]);
                dfsfun(i, j, picture[i][j], m, n);
                if (temp > max_size_of_one_area) {
                    max_size_of_one_area = temp;
                }
            }
        }
    }

    answer[0] = usernumbercount;
    answer[1] = max_size_of_one_area;
    return answer;
}