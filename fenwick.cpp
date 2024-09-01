#include<bits/stdc++.h>
using namespace std;
class fenwickTree{
    vector<int>bit;
    fenwickTree(int n){
         bit.resize(n+1);
         for(int i=1;i<=n;i++){
             cin>>bit[i];
             update(n,i,bit[i]);
         }
    }

    void update(int n,int id,int val){
        while(id <= n){
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query(int id){
        int ans = 0;
        while(id > 0){
            ans += bit[id];
            id -= (id & -id);
        }
        return ans;
    }
};

int main(){
    int n,q;
    cin>>n>>q;
    fenwickTree fen(n);
    
    while(q--){
        int type ;
        cin>>type;

        if(type == 1){
            int l,r;
            cin>> l >> r;
            int ans = fen.query(r) - fen.query(l-1);
            cout<<ans<<endl;
        }

        else{
            int id,val;
            cin>>id>>val;
            fen.update(n,id,);

        }
    }
}
