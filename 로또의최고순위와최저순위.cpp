#include <string>
#include <vector>

using namespace std;
#define lotto_count (6)
int arr[46] = { 0, };
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same_count = 0;
    int dontknow_count = 0;

    for (int i = 0; i < lotto_count; i++) {
        arr[win_nums[i]] = 1;
    }
    for (int i = 0; i < lotto_count; i++) {
        if (lottos[i] == 0) {
            dontknow_count++;
            continue;
        }
        if (arr[lottos[i]] == 1)same_count++;
    }
    int high_same = same_count + dontknow_count;
    int high_result = (7 - high_same) > 6 ? 6: (7 - high_same);
    int low_result = (7 - same_count) > 6 ? 6 : (7 - same_count);

    answer.push_back(high_result);
    answer.push_back(low_result);

    return answer;
}
//int main() {
//    vector<int>lotto = { 44, 1, 0, 0, 31, 25 };
//    vector<int>win = { 31, 10, 45, 1, 6, 19 };
//    vector<int>answer=solution(lotto, win);
//    for (int i = 0; i < answer.size(); i++) {
//        printf("%d ", answer[i]);
//    }
//
//
//    return 0;
//}