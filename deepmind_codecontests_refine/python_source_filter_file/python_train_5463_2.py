import sys
from math import *
from bisect import *
from copy import *
MAX = sys.maxsize
MAXN = 10**5+10
logT = [0]*(MAXN)

def arrIN(x = ' '):
    return list(map(int,sys.stdin.readline().strip().split(x)))
for i in range(2,MAXN):
    logT[i] = logT[i//2]+1

def buildSparse(a):
    n = len(a)
    k = logT[n]+1
    st = [[-MAX for j in range(k)] for i in range(n)]
    for i in range(n):
        st[i][0] = a[i]
    j = 1
    while (1<<j)<=n:
        i = 0
        while (i+(1<<j)-1)<n:
            st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1])
            i+=1
        j+=1
    return st

def query(l,r,st):
    if l>r:
        return -MAX
    tot = r-l+1
    k = logT[tot]
    return max(st[l][k],st[l+tot-(1<<k)][k])

n,m,k = arrIN()
temp = [[] for _ in range(m)]
for _ in range(n):
    x = arrIN()
    for i in range(m):
        temp[i].append(x[i])

st = []
for i in range(m):
    st.append(buildSparse(temp[i]))

lo = 0
hi = n-1
t = [0]*m
ans = [0]*m
while lo<=hi:
    mid = (lo+hi)//2
    i = 0
    f = 0
    while i+mid-1<n:
        for j in range(m):
            t[j] = query(i,i+mid-1,st[j])
        res = sum(t)
        if res<=k:
            ans = deepcopy(t)
            f = 1
            break
        i+=1
    if f:
        lo = mid+1
    else:
        hi = mid-1
print(*ans)



