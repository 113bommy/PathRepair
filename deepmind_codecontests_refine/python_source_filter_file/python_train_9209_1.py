
from collections import defaultdict , deque

def dfs(node , c):

    if not visited[node]:
        visited[node] = True
        for j in g[node]:
            if not visited[j[0]] and j[1] == c :
                dfs(j[0] , j[1])


n , m = map(int,input().split())
g = defaultdict(list)

for i in range(m):
    u , v , c = map(int,input().split())
    g[u].append([v , c])
    g[v].append([u , c])


q = int(input())
ans = deque()

for k in range(q):

    x , y = map(int,input().split())
    cnt = 0
    for j in range(1 , m):
        visited = [False] * (n + 1)
        dfs(x , j)
        if visited[y] == True:
            cnt +=1

    ans.append(cnt)

#print(ans)

for j in ans:
    print(j)


