#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    vector<int> counts(n);

    // 读取砝码重量
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    // 读取砝码数量
    for (int i = 0; i < n; i++) {
        cin >> counts[i];
    }

    unordered_set<int> possibleWeights;
    possibleWeights.insert(0);  // 初始时可以称出0重量

    // 遍历每种砝码
    for (int i = 0; i < n; i++) {
        int weight = weights[i];
        int count = counts[i];

        // 临时集合存储新的重量
        unordered_set<int> temp = possibleWeights;

        // 尝试使用1到count个当前砝码
        for (int j = 1; j <= count; j++) {
            int currentWeight = j * weight;

            // 将当前砝码与已有重量组合
            for (int w : possibleWeights) {
                temp.insert(w + currentWeight);
            }
        }

        // 更新可能的重量集合
        possibleWeights = temp;
    }

    // 输出不同重量的数量
    cout << possibleWeights.size() << endl;

    return 0;
}
