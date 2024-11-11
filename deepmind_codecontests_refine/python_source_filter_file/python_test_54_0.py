from collections import defaultdict
from sys import stdin, setrecursionlimit
import threading
input = stdin.readline

def work():
    def dfs(curr):
        nonlocal c1, c2, ok
        if color[curr] == 1:
            c1 += 1
        else:
            c2 += 1

        for node in graph[curr]:
            if color[node[0]] == -1:
                color[node[0]] = color[curr] ^ node[1]
                dfs(node[0])

            elif color[node[0]] != -1:

                if node[1] == 1 and color[node[0]] == color[curr]:
                    ok = False
                if node[1] == 0 and color[node[0]] != color[curr]:
                    ok = False

    setrecursionlimit(2*10**5+50)
    for _ in range(int(input())):
        ok = True

        n, m = map(int, input().split())
        color = [-1 for __ in range(n + 1)]
        graph = defaultdict(list)
        for __ in range(m):
            u, v, c = input().split()
            u, v = int(u), int(v)
            if c == 'imposter':
                graph[u].append((v, 1))
                graph[v].append((u, 1))
            else:
                graph[u].append((v, 0))
                graph[v].append((u, 0))

        ans = 0
        for i in range(1, n+1):
            c1 = c2 = 0
            if color[i] == -1:
                color[i] = 0
                dfs(1)
                ans += max(c1, c2)

        print(-1 if not ok else ans)


threading.stack_size(2*10**8)
threading.Thread(target=work).start()
