INF = 10**5+1
ac = [0 for i in range(INF)]
memo = [True for i in range(INF)]
for i in range(2,INF):
    if memo[i]:
        for j in range(2*i,INF,i):
            memo[j] = False

for x in range(1,INF,2):
    ac[x] = 1 if memo[x] and memo[(x+1)//2] else 0
for x in range(1,INF):
    ac[x] += ac[x-1]
Q = int(input())
for i in range(Q):
    l,r = map(int,input().split())
    print(ac[r]-ac[l-1])
