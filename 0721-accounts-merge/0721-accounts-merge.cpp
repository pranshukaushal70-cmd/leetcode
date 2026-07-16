class Solution {
public:
    vector<int> parent, rankv;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (rankv[a] < rankv[b])
            swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b])
            rankv[a]++;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        unordered_map<string, int> emailToIndex;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (!emailToIndex.count(email))
                    emailToIndex[email] = i;
                else
                    Union(i, emailToIndex[email]);
            }
        }
        unordered_map<int, vector<string>> mergedEmails;
        for (auto &it : emailToIndex) {
            string email = it.first;
            int idx = it.second;
            int p = find(idx);
            mergedEmails[p].push_back(email);
        }
        vector<vector<string>> ans;
        for (auto &it : mergedEmails) {
            auto &emails = it.second;
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(accounts[it.first][0]);
            for (string &email : emails)
                account.push_back(email);
            ans.push_back(account);
        }
        return ans;
    }
};