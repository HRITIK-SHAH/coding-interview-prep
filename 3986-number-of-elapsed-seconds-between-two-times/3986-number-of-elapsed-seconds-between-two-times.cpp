class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        return seconds(endTime) - seconds(startTime);
    }

private:
    int seconds(string str) {
        int cnt = 0;

        cnt += stoi(str.substr(0, 2)) * 60 * 60;
        cnt += stoi(str.substr(3, 2)) * 60;
        cnt += stoi(str.substr(6, 2));

        return cnt;
    }
};