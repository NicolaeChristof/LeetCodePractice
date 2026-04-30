// https://leetcode.com/problems/implement-trie-prefix-tree
#include <string>
#include <array>

struct TrieNode
{
    std::array<TrieNode*, 26> children{};
    bool isWord = false;

    TrieNode(){}
};

class Trie
{
    TrieNode* root;

    void deleteNode(const TrieNode* node)
    {
        if (node == nullptr) return;
        for (int i = 0; i < node->children.size(); ++i) deleteNode(node->children[i]);
        delete node;
    }
public:
    Trie()
    {
        root = new TrieNode();
    }

    ~Trie()
    {
        deleteNode(root);
    }

    void insert(std::string word)
    {
        TrieNode* current = root;
        for (const char letter : word)
        {
            const int index = letter - 'a';
            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isWord = true;
    }

    bool search(std::string word) const
    {
        TrieNode* current = root;
        for (const char letter : word)
        {
            const int index = letter - 'a';
            if (current->children[index] == nullptr) return false;
            current = current->children[index];
        }
        return current != nullptr && current->isWord;
    }

    bool startsWith(std::string prefix) const
    {
        TrieNode* current = root;
        for (const char letter : prefix)
        {
            const int index = letter - 'a';
            if (current->children[index] == nullptr) return false;
            current = current->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */