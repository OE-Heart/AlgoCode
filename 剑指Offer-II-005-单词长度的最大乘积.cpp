class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int states[n];
        for (int i = 0; i < n; i++) {
            states[i] = 0;
            for (int j = 0; j < words[i].size(); j++) {
                states[i] |= (1<<(words[i].at(j)-'a'));
            }
        }

        int max = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if ((states[i]&states[j]) != 0) continue;
                int mul = words[i].length()*words[j].length();
                if (mul > max) max = mul;
            }
        }

        return max;
    }
};