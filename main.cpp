#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/student-attendance-record-i/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool checkRecord(string &s) {
        bool absent = false;
        int late2 = 0;
        for (auto c: s) {
            switch (c) {
                case 'A':
                    if (absent)
                        return false;
                    else
                        absent = true;
                    late2 = 0;
                    break;
                case 'L':
                    if (late2 == 2) return false;
                    ++late2;
                    break;
                default:
                    late2 = 0;
            }
        }
        return true;
    }
};

void test1() {
    string s = "PPALLP";

    cout << "1 ? " << Solution().checkRecord(s) << endl;
    s = "PPALLL";
    cout << "0 ? " << Solution().checkRecord(s) << endl;
}

void test2() {

}

void test3() {

}