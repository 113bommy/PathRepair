import bisect
import sys
sys.setrecursionlimit(3*10**5)

INF = 10**10

N = int(input())
a = list(map(int,input().split()))
T = [set() for x in range(N)]
for i in range(N-1):
    u,v = map(int,input().split())
    u -= 1
    v -= 1
    T[u].add(v)
    T[v].add(u)

search = [0]*N

A = [INF]

ans = [-1]*N

def dfs(V):
    num = a[V]
    added = 0
    if A[-1] > num:
        A.append(num)
        added = 1
    else:
        k = bisect.bisect_left(A,num)
        v = A[k]
        A[k] = num
    ans[V] = len(A)
    for VV in T[V]:
        if search[VV]:
            continue
        search[VV] = 1
        dfs(VV)
    if added:
        A.pop()
    else:
        A[k] = v

search[0] = 1
dfs(0)

print(*ans,sep="\n")