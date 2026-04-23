#include <iostream>
using namespace std;

struct edge{
    int v1, v2;
    double weight;
};

const int SIZE = 100;
int parent[SIZE];   // disjoint set parent

// -------- Bubble Sort (same logic) ----------
void sort_edge(edge g[], int ne){
    for(int i=0;i<ne-1;i++){
        for(int j=0;j<ne-i-1;j++){
            if(g[j].weight > g[j+1].weight){
                edge temp = g[j];
                g[j] = g[j+1];
                g[j+1] = temp;
            }
        }
    }
}

// -------- Find ----------
int find(int k){
    while(parent[k] != k)
        k = parent[k];
    return k;
}

// -------- Union ----------
void UnionSet(int i, int j){
    if(i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

// -------- Main ----------
int main(){

    edge g[SIZE];
    edge mst[SIZE];

    int ne;   // number of edges
    cout<<"Enter number of edges: ";
    cin>>ne;

    // input edges
    for(int i=0;i<ne;i++){
        cout<<"Enter v1 v2 weight: ";
        cin>>g[i].v1>>g[i].v2>>g[i].weight;
    }

    // initialize parent array
    for(int i=0;i<SIZE;i++)
        parent[i] = i;

    // sort edges by weight
    sort_edge(g, ne);

    int i,j,x,y;
    int p,q;

    // Kruskal logic (same as yours)
    for(p=0,q=0;p<ne;p++){      //p-> index for all edge
        i = g[p].v1;            //q-> index for MST edges
        j = g[p].v2;            //ne -> no. of edges

        x = find(i);
        y = find(j);

        if(x != y){
            mst[q].v1 = i;
            mst[q].v2 = j;
            mst[q].weight = g[p].weight;

            UnionSet(x,y);
            q++;
        }
    }

    // print MST
    cout<<"\nEdges in MST:\n";
    for(int k=0;k<q;k++){
        cout<<mst[k].v1<<" - "<<mst[k].v2
            <<"  weight = "<<mst[k].weight<<endl;
    }

    return 0;
}