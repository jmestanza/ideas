#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<int, pii> piii;
typedef vector<piii> vpiii;
typedef pair<int,piii> piiii;
typedef vector<piiii> vpiiii;

int appointments[10000+5];

int find_first_index(deque<pii> candidates, map<int,bool> &visited){
    for(int i=0 ; i < candidates.size() ; i++){
        int person = candidates[i].second;
        if(visited.find(person) == visited.end()){ // not found -> got my index!
           return i;
        }
    }
    return -1;
}


bool canAssignAllAppointments(map<int, vector<pair<int,int>>> freqs, map<int, bool> visited){
    for (auto i = freqs.begin(); i != freqs.end(); i++)
    {
        int li = distance(i, freqs.end());
        vector<pii> candidates = i->second;
        std::sort(candidates.begin(), candidates.end());
        deque<pii> candidates_queue;
        for(pii cand: candidates){
            candidates_queue.push_back(cand);
        }
        int count = 1;
        while(!candidates_queue.empty()){
            pii curr = candidates_queue.front();
            int person = curr.second; // now it's chosen, must delete this as a future candidate
            int idx = find_first_index( candidates_queue, visited);
            if(idx == -1) return false;
            candidates_queue.pop_front();
            visited[person] = true;
            appointments[count] = person;
            count++;
        }
    }
    return true;
}

int main() {
    int t, n, li, ri;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "new case" << endl;
        cin >> n;
        vpii intervals;
        vpiii info;
        map<int, vector<pair<int,int>>> freqs; // it saves start -> ri, person
        memset(appointments, 0, (10000+5)*sizeof(appointments[0]));
        map<int, bool> visited;
        for (int j = 0; j < n; j++) {
            cin >> li;
            cin >> ri;
            int person = j+1;
            pii pair2add = pii(ri,person);
            if(freqs.find(li) != freqs.end()){ // if found
                freqs[li].push_back(pair2add);
            } else { // if not found
                freqs[li] = vector<pii>(1,pair2add);
            }
        }
        if(canAssignAllAppointments(freqs, visited)){
            for (int j = 1; j <= n; j++) {
                string last_str = j == n? "": " ";
                cout << appointments[j] << last_str;
            }
            cout << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}
