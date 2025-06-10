#include <bits/stdc++.h>
using namespace std;

vector<int> parse_ip(const string& s) {
    vector<int> parts;
    string current;
    for (char c : s) {
        if (c == '.') {  
            // �����㣬����ǰ����
            if (current.empty()) return {}; // �ղ��֣��Ƿ�
            for (char digit : current) {
                if (!isdigit(digit)) return {}; // �������ַ����Ƿ�
            }
            int num = stoi(current);
            if (num < 0 || num > 255) return {}; // ������Χ���Ƿ�
            parts.push_back(num);
            current.clear();
        } else {
            current += c; // �����ַ�
        }
    }
    
    // �������һ����
    if (current.empty()) return {};
    for (char digit : current) {
        if (!isdigit(digit)) return {};
    }
    int num = stoi(current);
    if (num < 0 || num > 255) return {};
    parts.push_back(num);
    
    // ����Ƿ�ǡ��Ϊ4����
    if (parts.size() != 4) return {};
    
    return parts;
}

bool valid_mask(const vector<int>& mask) {
    string binary;
    for (int num : mask) {
        binary += bitset<8>(num).to_string();
    }
    int first_zero = binary.find('0');
    if (first_zero == string::npos) return false;
    int last_one = binary.rfind('1');
    return last_one < first_zero;
}

bool is_private(const vector<int>& ip) {
    if (ip[0] == 10) return true;
    if (ip[0] == 172 && ip[1] >= 16 && ip[1] <= 31) return true;
    if (ip[0] == 192 && ip[1] == 168) return true;
    return false;
}

int main() {
    int A = 0, B = 0, C = 0, D = 0, E = 0, error = 0, private_ip = 0;
    string line;
    while (getline(cin, line)) {
        size_t pos = line.find('~');
        if (pos == string::npos) {
            error++;
            continue;
        }
        string ip_str = line.substr(0, pos);//��ѯ�ɹ���
        string mask_str = line.substr(pos + 1);
        
        vector<int> ip = parse_ip(ip_str);
        vector<int> mask = parse_ip(mask_str);
        
        if (ip.empty() || mask.empty()) {
            error++;
            continue;
        }
        
        if (ip[0] == 0 || ip[0] == 127) continue;
        
        if (!valid_mask(mask)) {
            error++;
            continue;
        }
        
        if (ip[0] >= 1 && ip[0] <= 127) A++;
        else if (ip[0] >= 128 && ip[0] <= 191) B++;
        else if (ip[0] >= 192 && ip[0] <= 223) C++;
        else if (ip[0] >= 224 && ip[0] <= 239) D++;
        else if (ip[0] >= 240 && ip[0] <= 255) E++;
        
        if (is_private(ip)) private_ip++;
    }
    cout << A << " " << B << " " << C << " " << D << " " << E << " " << error << " " << private_ip << endl;
    return 0;
}
