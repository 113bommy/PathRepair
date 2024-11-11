


n , m = map(int,input().split())
graph = [[0]*(n+1) for i in range(n+1)]
#print(graph)
visited = [-1]*(n+1)

for i in range(m):
    u , v = map(int,input().split())
    graph[u][v] = 1
    graph[v][u] = 1

def dfs(i , v):
    visited[i] = v
    for j in range(1 , n + 1 ):
        if graph[i][j] == 1 and visited[j] == -1:
            dfs(j , 1-v)

for i in range(1 , n + 1 ):
    if visited[i] == -1:
        dfs(i , 1)

res = 0

for i in range(1,n+1):
    for j in range(i+1 , n + 1 ):
        #print(i , j)
        if graph[i][j] == 1 and visited[i] == visited[j]:
            res +=1


#print(res)

if (n - res) % 2 != 0 :
    print(res + 1 )

else:
    print(res)

