from collections import deque

def dfs(neighbours, x, n):
    parents = [None for i in range(n)]
    dq = deque()
    dq.append(x)
    parents[x] = 0
    while len(dq)!=0:
        ret = dq.popleft()
        for i in neighbours[ret]:
            if parents[i] == None:
                parents[i] = parents[ret]+1
                dq.append(i)
    return parents

ans = []
test_cases = int(input())
for i in range(test_cases):
    n, a, b, da, db = [int(j) for j in input().split()]
    a = a-1
    b = b-1
    neighbours = [[] for j in range(n)]
    for i in range(n-1):
        x, y = [int(node)-1 for node in input().split()]
        neighbours[x].append(y)
        neighbours[y].append(x)
    distances = dfs(neighbours, a, n)
    distw = max(distances)
    w = distances.index(distw)
    diam = max(dfs(neighbours, w, n))
    if distances[b] <= da:
        ans.append('Alice')
    elif diam <= 2*da:
        ans.append('Alice')
    elif db < 2*da:
        ans.append('Alice')
    else:
        ans.append('Bob')
for i in range(test_cases):
    print(ans[i])