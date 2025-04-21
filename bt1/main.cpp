#include <iostream>
#include <vector>
#include <string>
using namespace std;

string minimalRotation(const string& s) {
    int len = s.length();
    if (len == 0) return;
    string str = s;
    vector<string> lst = {};
    string min_str = "";
    lst.push_back(s);
    for (int i = 0; i < len - 1; i++) {
        str = str.substr(1) + str[0];
        lst.push_back(str);
    }
    for (int i = 0; i < len; i++) {
        vector<string> new_lst = {};
        auto ind = lst.begin();
        char min_chr = (*(ind))[i];
        auto min_ind = ind;
        new_lst.push_back(*(ind));
        while (ind != lst.end()) {
            char c = (*(ind))[i];
            if (min_chr > c) {
                new_lst.clear();
                min_chr = c;
                min_ind = ind;
                new_lst.push_back(*(ind));
            }
            else if (min_chr == c) {
                new_lst.push_back(*(ind));
            }
            ind++;
        }
        if (new_lst.size() == 1) {
            return new_lst[0];
        }
        else {
            lst = new_lst;
        }
    }
    return lst[0];
}

int main() {
    string s;
    cin >> s;
    cout << minimalRotation(s);
}