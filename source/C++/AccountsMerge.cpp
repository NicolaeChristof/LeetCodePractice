// https://leetcode.com/problems/accounts-merge
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class DisjointSetUnion
{
    std::vector<int> parents;
public:
    DisjointSetUnion(const int size)
    {
        parents.reserve(size);
        for (int i = 0; i < size; ++i) parents[i] = i;
    }

    int Find(const int i)
    {
        if (parents[i] == i) return i;
        return parents[i] = Find(parents[i]);
    }

    void Unite(const int i, const int j)
    {
        int rootI = Find(i);
        int rootJ = Find(j);
        if (rootI != rootJ) parents[rootI] = rootJ;
    }
};

class Solution
{
public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts)
    {
        DisjointSetUnion disjointSetUnion(accounts.size());
        std::unordered_map<std::string, int> accountMap; // email address, account index email first appeared

        // map emails to account index and merge shared accounts
        for (int accountIndex = 0; accountIndex < accounts.size(); ++accountIndex)
        {
            for (int emailIndex = 1; emailIndex < accounts[accountIndex].size(); ++emailIndex)
            {
                const std::string& email = accounts[accountIndex][emailIndex];
                if (accountMap.contains(email))
                {
                    // found duplicate account
                    disjointSetUnion.Unite(accountIndex, accountMap[email]);
                }
                else
                {
                    accountMap[email] = accountIndex;
                }
            }
        }

        // group emails by root account index
        std::unordered_map<int, std::vector<std::string>> groupedEmails;
        for (const auto& [email, accountIndex] : accountMap)
        {
            const int root = disjointSetUnion.Find(accountIndex);
            groupedEmails[root].emplace_back(email);
        }

        // format result
        std::vector<std::vector<std::string>> result;
        for (auto& [root, emails] : groupedEmails)
        {
            sort(emails.begin(), emails.end());

            std::vector<std::string> mergedAccount = { accounts[root][0] };
            mergedAccount.reserve(emails.size() + 1);
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());

            result.emplace_back(mergedAccount);
        }

        return result;
    }
};