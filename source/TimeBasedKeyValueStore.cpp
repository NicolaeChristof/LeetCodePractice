// https://leetcode.com/problems/time-based-key-value-store
#include <string>
#include <unordered_map>

class TimeMap
{
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> timeMap;
public:
    TimeMap(){}

    void set(std::string key, std::string value, int timestamp)
    {
        timeMap[key].emplace_back(timestamp, value);
    }

    std::string get(std::string key, int timestamp)
    {
        if (!timeMap.contains(key)) return "";

        const std::vector<std::pair<int, std::string>>& timeVector = timeMap[key];
        if (timeVector.empty()) return "";

        std::string result = "";

        int low = 0;
        int high = timeVector.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (timeVector[mid].first <= timestamp)
            {
                result = timeVector[mid].second;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */