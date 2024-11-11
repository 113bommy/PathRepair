n = int(input())
tree = [0] * (n+1)
edges = []
for i in range(n-1):
    u, v = map(int, input().split())
    edges.append((u, v))
    tree[u] += 1
    tree[v] += 1
left = 0
right = n-2
for u, v in edges:
    if tree[u] != 1 and tree[v] != 1:
        print(left)
        left += 1
    else:
        print(right)
        right -= 1