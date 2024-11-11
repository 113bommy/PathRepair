import sys
readline = sys.stdin.readline
sys.setrecursionlimit(10**8)
mod = 10**9+7
#mod = 998244353
INF = 10**18
eps = 10**-7

N = int(readline())
k = -1
for i in range(1,1000):
    if i*(i-1)//2 == N:
        k = i
        print('Yes')
        break
if k == -1:
    print('No')
    exit()

print(k)
ans = [[] for i in range(k)]

import itertools

for i,(a,b) in enemurate(itertools.combinations(range(k),2),1):
    ans[a].append(i)
    ans[b].append(i)

for aaa in ans:
    print(len(aaa),' '.join(map(str,aaa)))

