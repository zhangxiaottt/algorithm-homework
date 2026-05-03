#include <iostream>
#include <vector>
using namespace std;
int weigh_cnt = 0;
int findFake(vector<int>& coins, int l, int r) {
    if (l == r) return l;
    int len = r - l + 1;
    int part = len / 3;
    if (part == 0) {
        weigh_cnt++;
        if (coins[l] > coins[r]) return l;
        else return r;
    }
    weigh_cnt++;
    int sum_l = 0, sum_m = 0;
    for (int i = l; i < l + part; i++) sum_l += coins[i];
    for (int i = l + part; i < l + 2 * part; i++) sum_m += coins[i];
    if (sum_l > sum_m) return findFake(coins, l, l + part - 1);
    else if (sum_l < sum_m) return findFake(coins, l + part, l + 2 * part - 1);
    else return findFake(coins, l + 2 * part, r);
}
int main() {
    vector<int> coins(14, 1);
    coins[12] = 2;
    int fake_id = findFake(coins, 0, 13);
    cout << "¼Ù±Ò±àºÅ£º" << fake_id << endl;
    cout << "³ÆÖØ´ÎÊý£º" << weigh_cnt << endl;
    system("pause");
    return 0;
}