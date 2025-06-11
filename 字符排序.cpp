#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    // 提取所有字母并记录它们的位置
    vector<pair<char, int>> letters;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            letters.push_back({s[i], i});
        }
    }

    // 按照字母表顺序排序（不区分大小写），并保持相同字母的原始顺序
    stable_sort(letters.begin(), letters.end(), [](const pair<char, int>& a,
    const pair<char, int>& b) {
        char lowerA = tolower(a.first);
        char lowerB = tolower(b.first);

        // 如果小写字母相同，则按原始位置排序
        if (lowerA == lowerB) {
            return a.second < b.second;  // 原始位置较小的排在前面
        }

        // 否则按小写字母排序
        return lowerA < lowerB;
    });

    // 构建结果字符串
    string result = s;
    int letterIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            // 将排序后的字母放回原位置
            result[i] = letters[letterIndex].first;
            letterIndex++;
        }
    }

    cout << result << endl;
    return 0;
}
