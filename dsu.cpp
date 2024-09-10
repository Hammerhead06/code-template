class DisjointSet{
public:
vector<int>parent,size;
DisjointSet(int n){
parent.resize(n);
size.resize(n,1);
for(int i=0;i<n;i++) parent[i]=i;
}
int findUPar(int node){
if(parent[node]==node) return node;
return parent[node]=findUPar(parent[node]);
}
    
void unionbysize(int u,int v){
int x=findUPar(u);
int y=findUPar(v);
if(x==y) return;
if(size[x]>size[y]){
parent[y]=x;
size[y]+=size[x];
}
else{
parent[x]=y;
size[x]+=size[y];
}
}
};
