class SegmentTree: #1-indexed
    def __init__(self,list,f=lambda x,y:x+y,inf=0):
        self.height=(len(list)-1).bit_length()+1 #木の高さ
        self.zero=2**(self.height-1) #最下段に添字を合わせる用
        self.id=inf #単位元
        self.tree=[self.id]*(2**self.height) #木を単位元で初期化
        self.f=f
        for i in range(len(list)):
            self.tree[self.zero+i]=list[i]
        for i in range(self.zero-1,0,-1):
            self.tree[i]=self.f(self.tree[2*i],self.tree[2*i+1])
        
    def update(self,i,x): #i番目の要素をxに変更
        i+=self.zero
        self.tree[i]=x
        while i>1:
            i//=2
            self.tree[i]=self.f(self.tree[2*i],self.tree[2*i+1])
    
    def query(self,l,r): #区間[l,r)
        l+=self.zero
        r+=self.zero
        lf,rf=self.id,self.id
        while l<r:
            if l&1:
                lf=self.f(lf,self.tree[l])
                l+=1
            if r&1:
                r-=1
                rf=self.f(self.tree[r],rf)
            l//=2
            r//=2
        return self.f(lf,rf)

    '''
    FFFFTTTTとしたときの最小のTを求める
    '''
    def BinarySearch(self,l,r,f): #fの返り値はboolにする
        if not f(self.query(l,r)): #そもそも区間内にTがなければ右端をreturn
            return r
        l+=self.zero
        while True:
            if f(self.tree[l]):
                if l>=self.zero:
                    return l-self.zero+1 #最下段ならreturn
                else:
                    l*=2 #左の子供を見る
            else:
                if l%2==0:
                    l+=1 #左の子なら右を見る
                else:
                    l=(l//2)+1 #右の子なら親の右を見る

n,k=map(int,input().split())
a=[int(input()) for _ in range(n)]
am=300005
S=SegmentTree([0]*am,max)
for i in range(n):
    x=S.query(max(0,a[i]-k-1),min(a[i]+k+1,am))+1
    S.update(a[i]-1,x)
print(S.query(0,am))