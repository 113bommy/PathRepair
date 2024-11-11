n = int(input())
graph = [[0 for i in range(n)] for j in range(n)]
d = [0] * n
f = [0] * n
queue = [0]


for i in range(n):
   a = list(map(int, input().split()))
   for j in range(0, a[1], 1):
       graph[a[0] - 1][a[2 + j] - 1] = 1

while len(queue) != 0:
    i = queue.pop(0)
    for j in range(n):
        if (graph[i][j] == 1) & (f[j] == 0):
            queue.append(j)
            f[j] = 1
            d[j] = d[i] + 1

[print(i+1, d[i] if (i == 0) | (d[i] != 0) else -1) for i in range(n)]
