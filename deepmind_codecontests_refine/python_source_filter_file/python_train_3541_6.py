n = int(input())
child = {}
parent = {}

for i in range(n):
    a = list(map(int, input().split()))
    child[a[0]] = a[2:]
    for i in child[a[0]]:
        parent[i] = a[0] 

root = (set(child)-set(parent)).pop()
depth = [None]*n
depth[root] = 0
parent[root] = -1

    
def dfs(s):
    for i in child[s]:
            depth[i]=depth[s]+1
            dfs(i)
    
dfs(root)
    
for i in range(n):
    node_type = "root" if parent[i] == -1 else "leaf" if len(child[i]) == 0 else "internal node"
    print(f'node{i}: parent = {parent[i]}, depth = {depth[i]}, {node_type}, {child[i]}')


