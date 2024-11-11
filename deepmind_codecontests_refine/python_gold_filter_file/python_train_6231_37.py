N,M = map(int,input().split())
abc = []
for _ in range(M):
    abc.append(list(map(int,input().split())))

cost = [-float('inf')]*N
cost[0] = 0

for i in range(N):
    update = False
    for a,b,c in abc:
        a,b = a-1,b-1
        if cost[a] != -(10**10)*N:
            if cost[b] < cost[a] + c:
                cost[b] = cost[a] + c
                update = True
    if i == 0:
        Max = cost[N-1]
    elif i < N-1:
        Max = max(Max,cost[N-1])


if update == True and Max < cost[N-1]:
    print('inf')
else:
    print(Max)
