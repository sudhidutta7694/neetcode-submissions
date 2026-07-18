class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) { 
        if (mp.find(key) == mp.end()) {
            return "";
        }

        vector<pair<string, int>> &val = mp[key];

        int n = val.size();

        int low = 0;
        int high = n-1;

        string ans = "";

        while (low <= high) {
            int mid = low + (high - low)/2;

            if (val[mid].second <= timestamp) {
                ans = val[mid].first;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
