arr = [0 for i in range(0 , int(1e5) + 6)]
adj = [[] for i in range(0 , int(1e5) + 6)]
vis = [0 for i in range(0 , int(1e5) + 6)]
def BFS(index):
    que = []
    mini = arr[index]
    que.append(index)
    while (len(que)!= 0):
        cur = que[0]
        que.remove(que[0])
        vis[cur] = 1
        mini = min( mini , arr[cur])
        for i in range(0 , len(adj[cur])):
            if(vis[adj[cur][i]] == 0):
                que.append(adj[cur][i])
    return mini
n , m = map(int,input().split(' '))
k = list(map(int,input().split(' ')))
for i in range(0 , n):
    arr[i] = k[i]
for i in range(0 , m):
    a , b = map(int,input().split(' '))
    --a
    --b
    adj[a].append(b)
    adj[b].append(a)
sum = 0
for i in range(0 , n):
    if(vis[i] == 0):
        sum += BFS(i)
print(sum)

