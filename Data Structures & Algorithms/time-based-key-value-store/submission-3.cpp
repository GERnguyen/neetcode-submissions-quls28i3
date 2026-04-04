class TimeMap {
private:
    unordered_map<string, vector<string>> *mp;
public:
    TimeMap() {
        mp = new unordered_map<string, vector<string>>;
    }
    
    void set(string key, string value, int timestamp) {
        if ((*mp).find(key) == (*mp).end()) (*mp)[key] = vector<string>(1001, "");
        (*mp)[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if ((*mp).find(key) == (*mp).end()) return "";
        while (timestamp > 1000) timestamp--;
        while ((*mp)[key][timestamp] == "" && timestamp > 0) {
            timestamp--;
        }
        return (*mp)[key][timestamp];
    }
};
