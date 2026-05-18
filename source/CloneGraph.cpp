// https://leetcode.com/problems/clone-graph
#include <vector>
#include <queue>
#include <unordered_map>

// Definition for a Node.
class Node
{
public:
    int val;
    std::vector<Node*> neighbors;
    Node() : val(0)
    {
    }
    Node(int _val) : val(_val)
    {
    }
    Node(int _val, std::vector<Node*> _neighbors) : val(_val), neighbors(_neighbors)
    {
    }
};

class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr) return nullptr;

        std::queue<Node*> q;
        std::unordered_map<Node*, Node*> nodeMap;

        nodeMap[node] = new Node(node->val);
        q.emplace(node);

        while (!q.empty())
        {
            Node* currNode = q.front();
            q.pop();

            for (Node* neighbor : currNode->neighbors)
            {
                if (!nodeMap.contains(neighbor))
                {
                    nodeMap[neighbor] = new Node(neighbor->val);
                    q.emplace(neighbor);
                }
                nodeMap[currNode]->neighbors.emplace_back(nodeMap[neighbor]);
            }
        }
        return nodeMap[node];
    }
};