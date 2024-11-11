from itertools import*
n,c=map(int,input().split())
cost=[list(map(int,input().split()))for i in range(c)]
d=[[0]*c for i in range(3)]
for i in range(n):
    for j,v in enumerate(map(int,input().split())):
        d[(i+j)%3][v-1]+=1
print(min(sum(d[j][cmb[i]]*cost[i][j]for j in range(c)for i in range(3))for cmb in permutations(range(c),3)))