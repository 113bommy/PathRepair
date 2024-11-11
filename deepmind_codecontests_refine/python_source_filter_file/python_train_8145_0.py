import sys
from collections import deque

t = int(input())
for _ in range(t):
    n, a, b = [int(x) for x in input().split()]
    a -= 1
    b -= 1
    edges = set()
    adj = [[] for x in range(n)]
    for _ in range(n-1):
        u, v = [int(x) for x in sys.stdin.readline().split()]
        u -= 1
        v -= 1
        edges.add((u, v))
        edges.add((v, u))
        adj[u].append(v)
        adj[v].append(u)


    to_a = [-1 for x in range(n)]
    to_a[a] = a
    stack = [a]
    while len(stack):
        cur = stack.pop()
        for nb in adj[cur]:
            if to_a[nb] == -1:
                to_a[nb] = cur
                stack.append(nb)

    snake = [b]
    while snake[-1] != a:
        snake.append(to_a[snake[-1]])

    snake = deque(snake)

    adj = [set(l) for l in adj]
    leaves = [x for x in range(n) if len(adj[x]) == 1]
    num_branch_points = sum([1 for l in adj if len(l) >= 3])
    new_leaves = []

    if len(snake) == 2:
        print("YES" if num_branch_points >= 1 else "NO")
        continue

    while True:
        head = snake.pop()
        tail = snake.popleft()
        if len(adj[head]) == 1 and len(adj[tail]) == 1:
            print("NO")
            break
        if len(adj[head]) == 1:
            snake.append(head)
        else:
            snake.appendleft(tail)

        for leaf in leaves:
            if len(adj[leaf]) == 0:
                continue
            nb = adj[leaf].pop()
            adj[nb].remove(leaf)
            if len(adj[nb]) == 2:
                num_branch_points -= 1
            if len(adj[nb]) == 1:
                new_leaves.append(nb)

        leaves, new_leaves = new_leaves, []
        
        if num_branch_points == 0:
            print("NO")
            break
        
        if len(snake) == 2:
            print("YES")
            break
