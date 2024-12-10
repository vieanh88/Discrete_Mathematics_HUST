#include <iostream>
#include<vector>
using namespace std;
typedef vector<vector<int> > Tree;

int deg(Tree vect, int node)
{
    return vect[node].size(); 
}

void Deledge(Tree &vect, int node)
{
    for (int i=0; i<vect.size(); i++)
        for (int j=0; j<vect[i].size(); j++)
            if (vect[i][j] == node) vect[i].erase(vect[i].begin()+j);
    return;
}

void Delnode(Tree &vect, int node)
{
    vect[node].clear(); 
    Deledge(vect,node); 
    return;
}

int Demnode(Tree vect)
{
    int sum = 0;
    for (int i=0; i<vect.size(); i++)
        if (deg(vect,i) > 0) sum++;
    return sum;
}

/* vector<int> luutru;
/*In ma prufer code*/
void printprufercode(Tree vect)
{
    int i;
    /*
    if (Demnode(vect) == 1)
    {
        for (i=0; i<luutru.size(); i++)
            cout << luutru[i] << " ";
    }
    */
    if (Demnode(vect) > 2)    {
        /*
        for (i=0; i<vect.size(); i++)
        cout << deg(vect,i) << " ";
        cout << endl;
        */

        for (i=1; i<vect.size(); i++)
            if (deg(vect,i) == 1) break; 
        int v = vect[i][0]; /* luutru.push_back(v); */
        cout << v << " ";         Delnode(vect,i);
        printprufercode(vect);
    }
    return;
}
int main()
{
    int edge;
    int allnode;
    cin >> edge;
    allnode = edge + 1;

    Tree vect;
    vect.resize(allnode);
    for (int i=0; i<edge; i++)
    {
        int v1; 
        int v2; 
        cin >> v1;
        cin >> v2;
        vect[v1].push_back(v2);
        vect[v2].push_back(v1); 
    }
    /*
    for (int i=0; i<allnode; i++)
        cout << deg(vect,i);
        cout << endl;
        cout << vect.size() << endl;
    Delnode(vect,0);
    for (int i=0; i<allnode; i++)
        cout << deg(vect,i);
        cout << endl;
        cout << vect.size();
    */
    printprufercode(vect);
    return 0;
}
