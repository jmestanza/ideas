#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class SubElement{
private:
public:
    string Name;
    string Father;
    int guysinmydiv;
    int allbelowincludingme;
    friend ostream& operator<<(ostream& os, const SubElement& dt);

};
ostream& operator<<(ostream& os, const SubElement& dt)
{
    os << dt.Name << " " << dt.Father << " " << dt.guysinmydiv << " " << dt.allbelowincludingme ;
    return os;
}

int main() {
    string s1 , s2;
    while(cin >> s1  >> s2 ) {

        count = 0;
        maxlvl = 0;
        maxpos = 0;

        node *three = recu(s1, s2);

        vector<node *> node_list;
        vector<vector<node *>> levels;

        three->compute_count();

        for (int i = 0; i <= maxlvl; i++) {
            levels.push_back(vector<node *>());
        }
        //or i in range(maxlvl +1):


        for (int i = 0; node_list.size(); i++) {
            levels[node_list[i]->lvl].push_back(node_list[i]);
        }

        maxpos = node_list.size();
        /*
        for i in range(len(node_list)):
# node_list[i].place = i
        levels[ node_list[i].lvl ].append(node_list[i])

        maxpos = len(node_list)
#print(levels)
        for level in levels:
        showlvl = []
        for i in range(maxpos):
        showlvl.append(" ")

        for node in level:
        showlvl[node.place] = node.char

                ans = ""
        for i in range(len(showlvl)):
        ans += showlvl[i]

        print(ans)
    }*/
    }

    return 0;
}