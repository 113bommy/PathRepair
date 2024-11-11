n = int(input())
S = []
for i in range(n):
    S.append(input())
color = [-1]*n #0:黒, 1:白
color[0] = 0
stack = [0]
colored = [0]*n
colored[0] = 1
while len(stack) != 0:
    temp = stack.pop()
    col = color[temp]
    cur = S[temp]
    for j in range(n):
        if cur[j] == '1':
            if colored[j] != 0:
                if color[j] == col:
                    print(-1)
                    exit()
            else:
                if col == 1:
                    color[j] = 0
                else:
                    color[j] = 1
                colored[j] = 1
                stack.append(j)
maxdist = 0
dist = []
for i in range(n):
    d = [10**10]*n
    d[i] = 0
    dist.append(d)
for i in range(n):
    for j in range(n):
        if S[i][j] == '1':
            dist[i][j] = 1
for k in range(n):
    for i in range(n):
        for j in range(n):
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
for i in range(n):
    for j in range(n):
        maxdist = max(maxdist, dist[i][j])
print(maxdist+1)
