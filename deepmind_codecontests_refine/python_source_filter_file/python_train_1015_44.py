n,k=map(int,input().split())

class SegmentTree:
    def __init__(self,n,ele):

        self.ide_ele = ele

        self.num =2**(n-1).bit_length()
        self.seg=[self.ide_ele]*2*self.num


    #####segfunc######
    #クエリに応じて変える
    def segfunc(self,x,y):
        return max(x,y)

    def init(self,init_val):
        #set_val
        for i in range(n):
            self.seg[i+self.num-1]=init_val[i]    
        #built
        for i in range(self.num-2,-1,-1) :
            self.seg[i]=self.segfunc(self.seg[2*i+1],self.seg[2*i+2]) 
        
    def update(self,k,x):
        k += self.num-1
        self.seg[k] = x
        while k:
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

st=SegmentTree(300001,0)
dp=[0]*n
for i in range(n):
    a=int(input())
    dp[i]=max(dp[i],st.query(max(0,a-k),min(300000,a+k)+1)+1)
    st.update(a,dp[i])
    dp[i]=max(dp[i],st.query(0,300001))
print(dp)