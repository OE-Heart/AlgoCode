#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        unordered_map<char,int> hs,ht;
        for(auto &c:t) ht[c]++; 
        int l = 0, r = 0, cnt = 0; //l为窗口的左边界，r为窗口的右边界
        for( ; r < s.size(); r++) { //每次循环右边界右移一次
            hs[s[r]]++;
            if (hs[s[r]] <= ht[s[r]]) cnt++; //在找到第一个符合条件的窗口后，这个语句不会再运行了。
                                          //ps.该语句的作用是统计窗口内的有效字符
            //左边界右移                              
            while (hs[s[l]] > ht[s[l]]) { //这个语句会右移左边界，比如这个边界字符不在t里，
                hs[s[l]]--;           //或者符合条件的边界值在后面又增加了一个且和左边界值相同，那么就可以右移左边界
                l++;
            }
            if (cnt == t.size()) { //有效字符等于字符串t的长度，我们可以放入答案；或者对比前窗口的大小和当前的大小，然后决定是否更新res。
                if(res.empty()||r-l+1<res.size()) res=s.substr(l,r-l+1);
            }
        }

        return res;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);
        
        string ret = Solution().minWindow(s, t);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}