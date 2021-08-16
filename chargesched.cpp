#include <bits/stdc++.h>
using namespace std;
#define  w(t)                      int t;  cin>>t;  while(t--)
#define  mod1                      1000000007
#define  mod2                      998244353
#define  int                        long long int
#define  fastIO                    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void getVector(vector<int> &A) { for (auto &i : A) { cin >> i; }}
struct Job {
    int deadline, duration, idx;
    bool operator<(Job o) const {
        return deadline < o.deadline;
    }
};

vector<pair<int, pair<int, int>>> compute_schedule(vector<Job> jobs) {
    sort(jobs.begin(), jobs.end());
    set<pair<int, int>> s;
    vector<pair<int, pair<int, int>>> schedule;
    int last = jobs.back().deadline;
    for (int i = jobs.size() - 1; i >= 0; i--) {
        int t = jobs[i].deadline - (i ? jobs[i - 1].deadline : 0);
        s.insert(make_pair(jobs[i].duration, jobs[i].idx));
        while (t && !s.empty()) {
            auto it = s.begin();
            if (it->first <= t) {
                t -= it->first;
                schedule.push_back({it->second, {last - it->first, last}});
                last = last - it->first;
            } else {
                s.insert(make_pair(it->first - t, it->second));
                schedule.push_back({it->second, {last - t, last}});
                last = last - t;
                t = 0;
            }
            s.erase(it);
        }
        last = (i ? jobs[i - 1].deadline : 0);
    }
    return schedule;
}
void run_case()
{
    int N;
    cin >> N;
    vector<Job> jobs(N);
    for (int i = 0; i < N; i++)
    {
        cin >> jobs[i].duration;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> jobs[i].deadline;
        jobs[i].idx = i + 1;
    }
    vector<pair<int, pair<int, int>>> ans = compute_schedule(jobs);
    cout << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x.first << " " << x.second.first << " " << x.second.second << "\n";
    }
    return;
}
int32_t main()
{
    fastIO
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    w(t)
    {
        run_case();
    }
    return 0;
}