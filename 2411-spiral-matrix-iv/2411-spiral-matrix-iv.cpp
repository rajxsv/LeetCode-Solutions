/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int next(ListNode* &head) {
        if (head) {
            int val=head->val;
            head=head->next;
            return val;
        }
        return -1;
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int sr=0,sc=0,er=m-1,ec=n-1;
        int nums=m*n;
        vector<vector<int>> res(m, vector<int>(n,-1));

        while (head) {
            for (int j=sc; j<=ec&&nums; j++,nums--) {
                res[sr][j]=next(head);
            }
            sr++;
            for (int i=sr; i<=er&&nums; i++,nums--) {
                res[i][ec]=next(head);
            }
            ec--;
            for (int j=ec; j>=sc&&nums; j--,nums--) {
                res[er][j]=next(head);
            }
            er--;
            for (int i=er; i>=sr&&nums; i--,nums--) {
                res[i][sc]=next(head);
            }
            sc++;
        }

        return res;
        
    }
};