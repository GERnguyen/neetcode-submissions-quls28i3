class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b) {
        return a.first > b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.emplace_back(position[i], speed[i]);
        }

        sort(cars.begin(), cars.end(), comp);
        int fleets = cars.size();
        double aheadCarTime = double((target - cars[0].first)) / cars[0].second;
        for (int i = 1; i < cars.size(); i++) {
            double thisCarTime = double((target - cars[i].first)) / cars[i].second;
            cout<<"this: "<<thisCarTime<<" ahead: "<<aheadCarTime<<endl;
            if (thisCarTime <= aheadCarTime) {
                cars[i] = cars[i - 1];
                fleets--;
            }
            else {
                aheadCarTime = thisCarTime;
            }
        }

        return fleets;
    }
};
