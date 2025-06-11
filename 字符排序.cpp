#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    // ��ȡ������ĸ����¼���ǵ�λ��
    vector<pair<char, int>> letters;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            letters.push_back({s[i], i});
        }
    }

    // ������ĸ��˳�����򣨲����ִ�Сд������������ͬ��ĸ��ԭʼ˳��
    stable_sort(letters.begin(), letters.end(), [](const pair<char, int>& a,
    const pair<char, int>& b) {
        char lowerA = tolower(a.first);
        char lowerB = tolower(b.first);

        // ���Сд��ĸ��ͬ����ԭʼλ������
        if (lowerA == lowerB) {
            return a.second < b.second;  // ԭʼλ�ý�С������ǰ��
        }

        // ����Сд��ĸ����
        return lowerA < lowerB;
    });

    // ��������ַ���
    string result = s;
    int letterIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            // ����������ĸ�Ż�ԭλ��
            result[i] = letters[letterIndex].first;
            letterIndex++;
        }
    }

    cout << result << endl;
    return 0;
}
