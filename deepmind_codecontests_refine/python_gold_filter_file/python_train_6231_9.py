N, M = map(int,input().split())

routes = list()
for i in range(M):
    routes.append(list(map(int,input().split())))

score = [0,0] + [10**13] * (N-1)
negative = [False] * (N+1)

for i in range(N-1):
    for a,b,c in routes:
        if(score[b] > score[a] - c):
            score[b] = score[a] - c

ans = -score[N]
            
for i in range(N):
    for a,b,c in routes:
        if(score[b] > score[a] - c):
            score[b] = score[a] - c
            negative[b] = True
        if(negative[a] == True):
            negative[b] = True

if(negative[N] == True):
    print("inf")
else:
    print(ans)