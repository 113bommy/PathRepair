import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
input=lambda:sys.stdin.readline().rstrip()
from collections import defaultdict
def resolve():
    n,a,d=map(int,input().split())
    if(d==0):
        if(a!=0):
            print(n+1)
        else:
            print(1)
        return

    if(d<0): a,d=-a,-d # d>0
    D=defaultdict(list)
    for k in range(n+1):
        q,r=divmod(k*a,d)
        L=q+k*(k-1)//2
        R=q+k*(2*n-k-1)//2
        D[r].append((L,1)) # 1 -> add
        D[r].append((R,2)) # 2 -> remove

    ans=0
    for arr in D.values():
        arr.sort()
        # print(arr)
        over=0
        for v,q in arr:
            if(q==1 and over==0):
                left=v
            over+=1 if(q==1) else -1
            if(over==0):
                ans+=v-left+1
    print(ans)
resolve()