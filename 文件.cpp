#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    map<string, int> count; 
    vector<string> v;
    while(getline(cin, s)){
    	if(s.empty()) break; 
    	for(int i=0; i<s.size(); i++){
    		size_t j = s.find_last_of('\\');
    		string s1 ;
			 
//    		if(s[i] == '\\' ) j = i;

    		if(s[i] == ' '){
    			if((i-j) > 16){
    				s1 = s.substr(i-16);
				} else{
					s1 = s.substr(j+1);
				}
				if(count.find(s1) == count.end()){
					v.push_back(s1);
				}
				count[s1]++; 
			}
		}
	}
	int start = max(0, (int)v.size() - 8);
    for (int i = start; i < v.size(); ++i) {
        string s2 = v[i];
        cout << s2 << " " << count[s2] << endl;
    }

}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
