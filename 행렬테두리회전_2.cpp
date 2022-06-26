#include <string>
#include <vector>

using namespace std;
int arr[101 * 101] = { 0, };
int m = 0, n = 0;
int minNumber;
void init(int row, int col) {
    m = row;
    n = col;
    minNumber = 100001;
    int num = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i * n + j] = num++;
        }
    }
}
void selectMin(int number) {
    if (minNumber > number)minNumber = number;
}
void rotfun(int x1, int y1, int x2, int y2) {
    vector<int>saveIndexs;
    for (int i = y1; i < y2; i++) saveIndexs.push_back(x1 * n + i);
    for (int i = x1; i < x2; i++) saveIndexs.push_back(i * n + y2);
    for (int i = y2; i > y1; i--) saveIndexs.push_back(x2 * n + i);
    for (int i = x2; i > x1; i--) saveIndexs.push_back(i * n + y1);

    int temp = arr[saveIndexs[saveIndexs.size() - 1]];
    for (int i = saveIndexs.size() - 1; i > 0; i--) {
        arr[saveIndexs[i]] = arr[saveIndexs[i - 1]];
        selectMin(arr[saveIndexs[i]]);
    }

    arr[saveIndexs[0]] = temp;
    selectMin(temp);
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    init(rows, columns);
    for (int q = 0; q < queries.size(); q++) {
        minNumber = 100001;
        int startR = queries[q][0];
        int startC = queries[q][1];
        int lastR = queries[q][2];
        int lastC = queries[q][3];
        rotfun(startR, startC, lastR, lastC);
        answer.push_back(minNumber);
    }
    return answer;
