class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        char prev = sentence[0];
        int ind = 1;

        for (; ind < n; ind++) {
            if(sentence[ind] != ' ') {
                prev = sentence[ind];
            } else {
                if(sentence[ind+1] != prev) {
                    return false;
                } else {
                    prev = sentence[ind+1];
                }
            }
        }

        return sentence[0] == sentence.back();

    }
};