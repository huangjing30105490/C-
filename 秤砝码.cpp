#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    vector<int> counts(n);

    // ��ȡ��������
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    // ��ȡ��������
    for (int i = 0; i < n; i++) {
        cin >> counts[i];
    }

    unordered_set<int> possibleWeights;
    possibleWeights.insert(0);  // ��ʼʱ���ԳƳ�0����

    // ����ÿ������
    for (int i = 0; i < n; i++) {
        int weight = weights[i];
        int count = counts[i];

        // ��ʱ���ϴ洢�µ�����
        unordered_set<int> temp = possibleWeights;

        // ����ʹ��1��count����ǰ����
        for (int j = 1; j <= count; j++) {
            int currentWeight = j * weight;

            // ����ǰ�����������������
            for (int w : possibleWeights) {
                temp.insert(w + currentWeight);
            }
        }

        // ���¿��ܵ���������
        possibleWeights = temp;
    }

    // �����ͬ����������
    cout << possibleWeights.size() << endl;

    return 0;
}
