n = int(input())
node = [[] for i in range(n)]

for i in range(n - 1):
    a, b = map(int,input().split())
    node[a-1].append(b-1)
    node[b-1].append(a-1)

def dfs(v):
    dis = [10 ** 10] * n
    dis[v] = 0
    q = []
    q.append(v)

    while q:
        u = q.pop()
        for i in node[u]:
            if dis[i] > dis[u] + 1:
                dis[i] = dis[u] + 1
                q.append(i)

    return dis

d1 = dfs(0)
d2 = dfs(n - 1)

c = 0
for i in range(2, n - 1):
    if d1[i] <= d2[i]:
        c += 1

if c > (n - 2) // 2:
    print("Fennec")
else:
    print("Snuke")
