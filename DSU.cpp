#include<bits/stdc++.h>
using namespace std;
//Data Types
typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<ll>> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

//Certain Strings using macros
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define mod 1000000007
static const bool Init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();

class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUParent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findUParent(parent[u]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    

};



int main(){
    DisjointSet ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionBySize(3, 7); 

    if(ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
   
}
