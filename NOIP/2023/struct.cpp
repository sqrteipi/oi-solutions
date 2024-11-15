#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second 
vector<pair< pair<int, int>, string> > occ;
map<string, vector< pair<string, int> > > mp;
map<string, int> mx, memloc;
string tys[4] = {"byte", "short", "int", "long"};
int szs[4] = {1, 2, 4, 8};
signed main(){
    // freopen("struct.in", "r", stdin);
    // freopen("struct.out", "w", stdout);
    int q, lst = 0;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int curmx = 0, k, curlst = 0;
            string name;
            cin >> name >> k;
            vector < pair<string, int> > mem;
            for (int _=0; _<k; _++) {
                int cursz = 0;
                string ty, name2;
                cin >> ty >> name2;
                if (ty == "byte") cursz = 1;
                if (ty == "short") cursz = 2;
                if (ty == "int") cursz = 4;
                if (ty == "long") cursz = 8;
                mem.push_back({name2, cursz});
                curmx = max(curmx, cursz);
            }
            mx[name] = curmx;
            mp[name] = mem;
            for (auto p : mem) {
                while (curlst % p.ss != 0) curlst++;
                curlst += p.ss;
            }
            while (curlst % curmx != 0) curlst++;
            cout << curlst << " " << curmx << "\n";
        }
        else if (op == 2) {
            string name, ty;
            cin >> ty >> name;
            int loc = find(tys, tys + 4, ty) - tys;
            if (loc < 4) {
                int cursz = szs[loc];
                while (lst % cursz != 0) lst++;
                cout << lst << "\n";
                memloc[name] = lst;
                occ.push_back({{lst, lst + cursz - 1}, name});
                lst += cursz;
            }
            else {
                int cursz = mx[ty];
                while (lst % cursz != 0) lst++;
                cout << lst << "\n";
                for (auto p : mp[ty]) {
                    string name2 = p.ff, name3 = name + "." + name2;
                    int cursz2 = p.ss;
                    while (lst % cursz != 0) lst++;
                    memloc[name3] = lst;
                    occ.push_back({{lst, lst + cursz2 - 1}, name3});
                    lst += cursz2;
                }
                
            }
        }
        else if (op == 3) {
            string name;
            cin >> name;
            cout << memloc[name] << "\n";
        }
        else {
            int pos;
            cin >> pos;
            bool ok = false;
            for (auto p : occ) {
                int lind = p.ff.ff, rind = p.ff.ss;
                if (lind <= pos && pos <= rind) {
                    cout << p.ss << "\n";
                    ok = true;
                    break;
                }
            }
            if (!ok) cout << "ERR\n";
        }
    }
}