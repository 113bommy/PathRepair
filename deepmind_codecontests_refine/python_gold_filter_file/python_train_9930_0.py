import sys
input = sys.stdin.readline

'''

'''

n, m = map(int, input().split())
g = [[] for _ in range(n)]

for _ in range(m):
    x, y = map(int, input().split())
    g[x-1].append(y-1)
    g[y-1].append(x-1)

def ring(n, m, g):
    if all(len(l) == 2 for l in g):
        return True
    else:
        return False

def star(n, m, g):
    return any(len(l) == m for l in g)

def bus(n, m, g):
    for node in range(3):
        if len(g[node]) == 2:
            break
    else:
        return False
    
    exit = 0
    visited = [0] * n
    visited[node] = 1
    nodes = [node]

    while nodes:
        cur = nodes.pop()

        count = 0
        for new_node in g[cur]:
            if not visited[new_node]:
                visited[new_node] = 1
                nodes.append(new_node)
                count += 1
        
        if count == 0:
            exit += 1
    
    return exit == 2



if m == n-1 and bus(n, m, g):
    print("bus topology")
elif m == n and ring(n, m, g):
    print("ring topology")
elif m == n-1 and star(n, m, g):
    print("star topology")
else:
    print("unknown topology")
