
#include <string>
#include <vector>

using namespace std;
int arr[101][101] = { 0, };
int m, n;
int minNumber = 10001;
void init(int row,int col) {
    m = row, n = col;
    int num = 1;
    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            arr[i][j] = num++;
        }
    }
}
void selectMin(int number) {
    if(minNumber>number)minNumber = number;
}
void rotfun(int a, int b, int c, int d) {

    int righthigh = arr[a][d];
    for (int i = d;i >= b + 1;i--) {
        arr[a][i] = arr[a][i - 1];
        selectMin(arr[a][i]);
    }

    int rightlow = arr[c][d];
    for (int i = c;i >= a+2;i--) {
        arr[i][d] = arr[i - 1][d];
        selectMin(arr[i][d]);
    }
    arr[a + 1][d] = righthigh;
    selectMin(arr[a + 1][d]);

    int leftlow = arr[c][b];
    for (int i = b;i<=d-2;i++) {
        arr[c][i] = arr[c][i + 1];
        selectMin(arr[c][i]);
    }
    arr[c][d - 1] = rightlow;
    selectMin(arr[c][d - 1]);

    for (int i = a;i <= c - 2;i++) {
        arr[i][b] = arr[i + 1][b];
        selectMin(arr[i][b]);
    }
    arr[c - 1][b] = leftlow;
    selectMin(arr[c - 1][b]);

}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    init(rows, columns);

    for (int q = 0;q < queries.size();q++) {
        minNumber = 10001;
        int startR = queries[q][0];
        int startC = queries[q][1];
        int lastR = queries[q][2];
        int lastC = queries[q][3];
        rotfun(startR, startC, lastR, lastC);
        answer.push_back(minNumber);
    }
    return answer;
}
