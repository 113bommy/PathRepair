N,K=map(int,input().split())
class SegTreeMax:
    def __init__(self,N):
        self.N0=2**(N-1).bit_length()
        self.INF=2**63-1
        self.data=[0]*(2*self.N0)
        self.orig=[0]*N
    def update(self,i,x):
        self.orig[i]=x
        i+=self.N0-1
        self.data[i]=x
        while i>0:
            i=(i-1)//2
            self.data[i]=max(self.data[i*2+1],self.data[i*2+2])
    def max(self,l,r):
        L = self.N0 + l; R = self.N0 + r
        s = -self.INF
        while L < R:
            if R & 1:
                R -= 1
                s = max(s, self.data[R-1])
            if L & 1:
                s = max(s, self.data[L-1])
                L += 1
            L >>= 1; R >>= 1
        return s
X=300000
s=SegTreeMax(X+1)
A=[int(input()) for i in range(N)]
for a in A:
    s.update(a,max(s.max(max(0,a-K),min(X,a+K+1))+1,s.orig[a]))
print(s.max(0,X+1))