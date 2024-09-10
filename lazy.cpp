
      vl segTree,lazy;
void buildSegTree(int i,int l,int r){

    if(l==r){
        segTree[i]=v[l];return;
    }
    int mid=(l+r)/2;
    buildSegTree(2*i+1,l,mid);
    buildSegTree(2*i+2,mid+1,r);
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

void updateRange(int start,int end,int val,int i,int l,int r){

    if(lazy[i]!=0){
        segTree[i]+=(r-l+1)*lazy[i];
        if(l!=r){
        lazy[2*i+1]+=lazy[i];
        lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }

    if(r<start||l>end) return;
    if(l>=start&&r<=end){
        segTree[i]+=(r-l+1)*val;

        if(l!=r){
        lazy[2*i+1]+=val;
        lazy[2*i+2]+=val;
        }
        return;
   }

    int mid=(l+r)/2;
    updateRange(start,end,val,2*i+1,l,mid);
    updateRange(start,end,val,2*i+2,mid+1,r);

    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

ll Query(int start,int end,int i,int l,int r){
     if(lazy[i]!=0){
        segTree[i]+=(r-l+1)*lazy[i];
        if(l!=r){
        lazy[2*i+1]+=lazy[i];
        lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }

   if(l>end||r<start) return 0;

   if(start<=l&&end>=r){
   return segTree[i];
  }

   int mid=(l+r)/2;
  return Query(start,end,2*i+1,l,mid)+Query(start,end,2*i+2,mid+1,r);

}
