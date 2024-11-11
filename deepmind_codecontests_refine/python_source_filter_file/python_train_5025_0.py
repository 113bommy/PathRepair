diameter = 0
def dfs(u, tree, depth):
    global diameter
    length = 0
    level[u] = depth
    isCheck[u] = True
    for vertex in tree[u]:
        if isCheck[vertex] != True:
            isCheck[vertex] = True
            cur = dfs(vertex, tree, depth + 1) + 1
            diameter = max(diameter, cur + length)
            length = max(length, cur)
    return length
t = int(input())
for _ in range(t):
    n, a, b, da, db = map(int, input().split())
    tree = [[] for _ in range(n+1)]
    for _ in range(n-1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)
    isCheck = [0 for _ in range(n+1)]
    level = [0 for _ in range(n+1)]
    
    diameter = 0
    dfs(1, tree, 1)
    dist = abs(level[a] - level[b]) - 1
    
    if dist <= da:
        print('Alice')
    elif 2 * da >= min(diameter, db):
        print('Alice')
    elif db > 2 * da:
        print('Bob')



