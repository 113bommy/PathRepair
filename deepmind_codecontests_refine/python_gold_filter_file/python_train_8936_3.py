import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
a = list(map(int, input().split()))
from collections import defaultdict
ns = defaultdict(set)
for i in range(n-1):
    u,v = map(int, input().split())
    u -= 1
    v -= 1
    ns[u].add(v)
    ns[v].add(u)
    
    
def sub(u, p):
    if len(ns[u])==1 and p in ns[u]:
        return a[u]
    ub = 0
    mv = 0
    msum = 0
    for v in ns[u]:
        if p==v:
            continue
        val = sub(v, u)
        if val is None:
            return None
        mv = max(mv, val)
        msum += val
    lb = max(mv, msum//2)
    if not (lb<=a[u]<=msum):
#         print(u,lb, msum, mv)
        return None
    else:
        return a[u] - (msum-a[u])
if n==2:
    if a[0]==a[1]:
        print("YES")
    else:
        print("NO")
else:
    if len(ns[0])>1:
        ans = sub(0, -1)
    else:
        ans = sub(list(ns[0])[0], -1)

    if ans is None or ans!=0:
        print("NO")
    else:
        print("YES")