      vl segTree,v;
void BuildSegTree(int i,int l,int r){
    if(l==r){
        segTree[i]=v[l];
       return;
    }
    int mid=(l+r)/2;
    BuildSegTree(2*i+1,l,mid);
    BuildSegTree(2*i+2,mid+1,r);
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

void Update(int ind,int val,int i,int l,int r){

    if(l==r){
        segTree[i]=val;
        return;
    }
    int mid=(l+r)/2;
    if(ind<=mid){
        Update(ind,val,2*i+1,l,mid);
    }
    else{
        Update(ind,val,2*i+2,mid+1,r);
    }
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];

}

ll Query(int start,int end,int i,int l,int r){

    if(start>r||end<l) return 0;

    if(l>=start&&r<=end) return segTree[i];

    int mid=(l+r)/2;
    return Query(start,end,2*i+1,l,mid)+Query(start,end,2*i+2,mid+1,r);
}
