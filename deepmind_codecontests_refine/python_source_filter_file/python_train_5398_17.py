# https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b

from itertools import combinations

N,K=map(int,input().split())
a=list(map(int,input().split()))

minc=10**12
ai=[i for i in range(N)]
for i in combinations(ai,K):
    ac=a[:]
    cost=0
    i=list(i)
    for j in range(1,K):
        costt=max(max(ac[:i[j]])-ac[i[j]]+1,0)
        ac[i[j]]+=costt
        costa+=costt
    minc=min(cost,minc)
print(minc)