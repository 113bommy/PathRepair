class BITree:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def calc(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

Q=int(input())
query=[list(map(int,input().split())) for i in range(Q)]
tmp=[]
for i in range(Q):
    seq=query[i]
    if len(seq)==1:
        continue
    else:
        tmp.append((seq[1],i))
tmp.sort()
X=[(-1,-1) for i in range(Q)]
for i,sq in enumerate(tmp):
    X[sq[1]]=(i+1,sq[0])
N=len(tmp)
Idx=BITree(N)
Clc=BITree(N)
Btm=0
nowindex=0
for i in range(Q):
    if X[i]==(-1,-1):
        left=1
        right=N
        mid=(left+right)//2
        while(left<=right):
            mid=(left+right)//2
            if Idx.calc(mid)<=(nowindex+1)//2:
                left=mid+1
            else:
                right=mid-1
        k=right
        x=(Clc.calc(k)-Clc.calc(k-1))
        ans=Clc.calc(N)-2*Clc.calc(k)-x*(Idx.calc(N)-2*Idx.calc(k))+Btm
        print(x,ans)
    else:
        Idx.add(X[i][0],1)
        Clc.add(X[i][0],X[i][1])
        Btm+=query[i][2]
        nowindex+=1

