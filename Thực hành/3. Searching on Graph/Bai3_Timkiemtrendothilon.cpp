#include <iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<vector>
using namespace std;

bool ktraDinhKe(string v1, string v2)
{
    int dem = 0;
    if (v1.length() != v2.length()) return false;
    for (int i=0; i<v1.length(); i++)
        if (v1.at(i) != v2.at(i)) dem++;
    if (dem == 1) return true;
    else
        return false;
}

void nhapDuLieu(char *filename, TREE &DS)
{
    ifstream f;
    f.open(filename);
    while (!f.eof()){
        string temp;
        f >> temp;
        DS.push_back(temp);
    }
    return;
}

void Taovectordanhdau(vector<bool> &danhDau, int n)
{
    danhDau.resize(n, false);
    return;
}

void explore(TREE DS, vector<bool> &Ktra, int top)
{
    Ktra.at(top) = true;
    for (int i=0; i<DS.size(); i++)
    if (ktraDinhKe(DS.at(i),DS.at(top))){ 
        if (!Ktra.at(i)) explore(DS,Ktra,i); 
    }
    return;
}
int  dfs(TREE DS, vector<bool> &Ktra)
{
    int cc = 0;
    for (int i=0; i<DS.size(); i++)
        if (!Ktra.at(i)){
            explore(DS,Ktra,i);
            cc = cc + 1;
        }
    return cc;
}
int main()
{
    TREE tree;
    nhapDuLieu("sgb-works.txt",tree);
    vector<bool> danhDau;
    Taovectordanhdau(danhDau,tree.size());
    int soTPLT = dfs(tree,danhDau); 
    cout << soTPLT;
    /*
    for (int i=0; i<Top.size();i++)
        cout << Top.at(i) << " ";
    */
    return 0;
}
