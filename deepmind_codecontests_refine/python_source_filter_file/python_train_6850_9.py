from collections import deque as dq
n,m = list(map(int,input().split()))
graph = [[] for i in range(n)]
for i in range(m):
    a,b = list(map(int,input().split()))
    a -= 1;b -= 1
    graph[a].append(b)
s,t = list(map(int,input().split()))
s -= 1;t -= 1
check = [[-1,-1,-1] for i in range(n)]
que = dq()
que.appendleft([s,0])
check[s][0] = 0
while (que):
    v,l = que.pop()
    for i in graph[v]:
        if check[i][(l+1)%3] == -1:
            que.append([i,(l+1)%3])
            check[i][(l+1)%3] = check[v][l] + 1
if check[t][0] == -1:
    print(-1)
else:
    print(check[t][0] // 3)