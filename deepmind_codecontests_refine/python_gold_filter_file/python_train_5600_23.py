import itertools
class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
def invnum(n,a):
    bit=Bit(n)
    res=0
    for j in range(n):
        res+=j-bit.sum(a[j])
        bit.add(a[j],1)
    return res
N=int(input())
A=[int(i) for i in input().split()]
B=[int(i) for i in input().split()]
flag=0
M=-1
if N%2==0:
    M=N//2
else:
    M=N//2+1
ans=(N*(N-1))//2
for seq in itertools.combinations(range(N),M):
    X=[]
    Y=[]
    era=[0 for i in range(N)]
    for i in seq:
        if i%2==0:
            X.append((A[i],i))
        else:
            X.append((B[i],i))
        era[i]=1
    for i in range(N):
        if era[i]==0:
            if i%2==0:
                Y.append((B[i],i))
            else:
                Y.append((A[i],i))
    X.sort()
    Y.sort()
    L=[]
    if N%2==1:
        for i in range(M-1):
            L.append(X[i])
            L.append(Y[i])
        L.append(X[-1])
    else:
        for i in range(M):
            L.append(X[i])
            L.append(Y[i])
    #print(L)
    flag2=1
    for i in range(N-1):
        if L[i][0]>L[i+1][0]:
            flag2=0
            break
    if flag2==1:
        flag=1
        S=[L[i][1]+1 for i in range(N)]
        tmp=invnum(N,S)
        ans=min(tmp,ans)
if flag==1:
    print(ans)
else:
    print(-1)
