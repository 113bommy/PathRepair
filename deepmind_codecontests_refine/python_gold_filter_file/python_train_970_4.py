from sys import stdin, stdout

def find(node):
    x = []
    while dsu[node] > 0:
        x.append(node)
        node = dsu[node]
    for i in x:
        dsu[i] = node
    return node

def union(node1, node2):
    if node1 != node2:
        if dsu[node1] > dsu[node2]:
            node1, node2 = node2, node1
        dsu[node1] += dsu[node2]
        dsu[node2] = node1

n = int(stdin.readline().strip())
dsu = [-1]*(n+1)
m = int(stdin.readline().strip())
for __ in range(m):
    a, b = map(int, stdin.readline().strip().split())
    union(find(a), find(b))
k = int(stdin.readline().strip())

for __ in range(k):
    a, b = map(int, stdin.readline().strip().split())
    p_a = find(a)
    p_b = find(b)
    if p_a == p_b:
        dsu[p_a] = 0
maxm = 0
for i in range(1, n+1):
    if dsu[i] < 0:
        maxm = max(maxm, abs(dsu[i]))
stdout.write(f'{maxm}')


