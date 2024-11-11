import sys
import bisect
input=sys.stdin.readline
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
n,t=map(int,input().split())
a=list(map(int,input().split()))
pre=[0]*(n+1)
for i in range(n):
    pre[i+1]=pre[i]+a[i]
pre.sort(reverse=True)
upsum=[-10**18]
for i in range(n+1):
    if i==0 or pre[i]!=pre[i-1]:
        upsum.append(pre[i])
upsum.sort(reverse=True)
def lower(i):
    l=0;r=len(upsum)
    while r-l>1:
        m=(l+r)//2
        if upsum[m]<=i:
            r=m
        else:
            l=m
    return l
ans=0
cur=0
BIT=Bit(n+1)
BIT.add(lower(0)+1,1)
for aa in a:
    cur+=aa
    ans+=BIT.sum(lower(cur-t))
    BIT.add(lower(cur)+1,1)
print(ans)