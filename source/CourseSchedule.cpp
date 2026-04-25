// https://leetcode.com/problems/course-schedule
#include <vector>
#include <unordered_map>
#include <queue>

class Solution
{
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        std::unordered_map<int, std::vector<int>> dependencyMap;
        std::vector<int> inDegree(numCourses, 0);
        for (const std::vector<int>& prerequisite : prerequisites)
        {
            // dependencyMap keeps track of which courses are waiting on the 'key' course to be completed first
            // useful to quickly access which dependents need to decrement inDegree later
            dependencyMap[prerequisite[1]].push_back(prerequisite[0]);
            ++inDegree[prerequisite[0]];
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0) q.push(i);
        }

        std::vector<int> result;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            result.push_back(course);

            for (int dependent : dependencyMap[course])
            {
                --inDegree[dependent];
                if (inDegree[dependent] == 0) q.push(dependent);
            }
        }

        return result.size() == numCourses;
    }
};