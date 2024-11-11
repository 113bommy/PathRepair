import sys
read=sys.stdin.buffer.readline

class BIT:
    def __init__(self,N):
        self.N=N
        self.bit=[0]*N
    def add(self,a,w):
        x=a
        while(x<self.N):
            self.bit[x]+=w
            x|=x+1
    def get(self,a):
        ret,x=0,a-1
        while(x>=0):
            ret+=self.bit[x]
            x=(x&(x+1))-1
        return ret
    def cum(self,l,r):
        return self.get(r)-self.get(l)

def main():
    def update(x,i):
        if good[x]==-1:
            good[x]=i
            bit.add(i,1)
        else:
            bit.add(good[x],-1)
            good[x]=i
            bit.add(good[x],1)
        return
    
    N,Q=map(int,read().split())
    c=tuple(map(int,read().split()))
    li=[list(map(lambda x:int(x)-1,read().split()))+[i] for i in range(Q)]
    Query=[(li[i][0],li[i][1],i) for i in range(Q)]
    Query.sort(key=lambda x:x[1])
    ans=[-1]*Q
    good=[-1]*(N+1)
    bit=BIT(N)

    i=0
    for L,R,w in Query:
        while(i<=R):
            update(c[i],i)
            i+=1
        ans[w]=bit.cum(L,R+1)

    print(*ans,sep='\n')
    return
    
if __name__=='__main__':
    main()
