class BIT:
    def __init__(self,N):
        self.N=N
        self.bit=[0]*(N+1)
        self.b=1<<N.bit_length()-1
    def add(self,a,w):
        x=a
        while(x<=self.N):
            self.bit[x]+=w
            x+=x&-x
    def get(self,a):
        ret,x=0,a-1
        while(x>0):
            ret+=self.bit[x]
            x-=x&-x
        return ret
    def cum(self,l,r):
        return self.get(r)-self.get(l) 
    def lowerbound(self,w):
        if w<=0:
            return 0
        x=0
        k=self.b
        while k>0:
            if x+k<=self.N and self.bit[x+k]<w:
                w-=self.bit[x+k]
                x+=k
            k//=2
        return x+1

N=int(input())
A=list(map(int,input().split()))
dic={}
for i in range(N):
    dic[A[i]]=i+1
bit=BIT(N)
ans=0
for i in range(1,N+1):
    d=dic[i]
    bit.add(d,1)
    c=bit.get(d+1)
    L=bit.lowerbound(c-1)
    R=bit.lowerbound(c+1)
    ans+=(R-d)*(d-L)*i
print(ans)
