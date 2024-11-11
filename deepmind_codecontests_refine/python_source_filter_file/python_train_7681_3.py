class segtree():
    def segfunc(x,y):
        return min(x,y)
    #####単位元######
    ide_ele = -1
    n=1
    init_val=[0]*n
    #num:n以上の最小の2のべき乗
    num =2**(n-1).bit_length()
    seg=[ide_ele]*2*num
    
    def __init__(self,INIT_VAL,SEGFUNC,IDE_ELE):
        self.ide_ele=IDE_ELE
        self.init_val=[i for i in INIT_VAL]
        self.segfunc=SEGFUNC
        self.n=len(self.init_val)
        self.num =2**(self.n-1).bit_length()
        self.seg=[self.ide_ele]*2*self.num

        #set_val
        for i in range(self.n):
            self.seg[i+self.num-1]=self.init_val[i]    
        #built
        for i in range(self.num-2,-1,-1) :
            self.seg[i]=self.segfunc(self.seg[2*i+1],self.seg[2*i+2]) 
        
    def update(self,k,x):
        k += self.num-1
        self.seg[k] = x
        while k+1:
            k = (k-1)//2
            self.seg[k] = self.segfunc(self.seg[k*2+1],self.seg[k*2+2])
        
    def query(self,p,q):
        if q<=p:
            return self.ide_ele
        p += self.num-1
        q += self.num-2
        res=self.ide_ele
        while q-p>1:
            if p&1 == 0:
                res = self.segfunc(res,self.seg[p])
            if q&1 == 1:
                res = self.segfunc(res,self.seg[q])
                q -= 1
            p = p//2
            q = (q-1)//2
        if p == q:
            res = self.segfunc(res,self.seg[p])
        else:
            res = self.segfunc(self.segfunc(res,self.seg[p]),self.seg[q])
        return res
class UnionFind():
    n=1
    par=[0]
    rnk=[0]
    def __init__(self,size):
        self.n=size
        self.par=[i for i in range(self.n)]
        self.rnk=[0 for i in range(self.n)]
    def find(self,vertex1):
        if self.par[vertex1]==vertex1:
            return vertex1
        else:
            self.par[vertex1]=self.find(self.par[vertex1])
            return self.par[vertex1]
    def unite(self,vertex1,vertex2):
        vertex1=self.find(vertex1)
        vertex2=self.find(vertex2)
        if vertex1==vertex2:
            return
        if (self.rnk[vertex1]<self.rnk[vertex2]):
            self.par[vertex1]=vertex2
        else:
            self.par[vertex2]=vertex1
            if(self.rnk[vertex1]==self.rnk[vertex2]):
                self.rnk[vertex1]+=1
    def same(self,vetrex1,vertex2):
        return self.find(vetrex1)==self.find(vertex2)

N,K=map(int,input().split())
P=[int(i) for i in input().split()]
mintree=segtree(P,min,N)
maxtree=segtree(P,max,-1)
G=UnionFind(N-K+1)
for i in range(N-K):
    m=mintree.query(i+1,i+K)
    M=maxtree.query(i+1,i+K)
    #print(m,M)
    if P[i]<m and M<P[i+K]:
        G.unite(i,i+1)
aaa=[G.find(i) for i in range(N-K+1)]
Q=[1 for i in range(N)]
for i in range(N-1):
    if P[i]<P[i+1]:
        Q[i+1]=Q[i]+1
    else:
        Q[i+1]=1
tmp=0
for i in range(N):
    if Q[i]>=K:
        tmp+=1
if tmp>0:
    tmp-=1
print(len(set(aaa))-tmp)