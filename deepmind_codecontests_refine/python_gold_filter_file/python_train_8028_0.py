from collections import defaultdict
from sys import stdin, setrecursionlimit
import threading
input = stdin.buffer.readline


def work():
    res = 0
    ans = 0
    setrecursionlimit(1 << 18)
    n = int(input())
    a = list(map(int, input().split()))
    a.insert(0, 0)
    graph = defaultdict(list)
    dist = dict()
    for v in range(n-1):
        a1, b = map(int, input().split())
        graph[a1].append(b)
        graph[b].append(a1)

    def dfs(v, par, h=0):
        nonlocal res
        res += h*a[v]
        dist[v] = a[v]

        for node in graph[v]:
            if node != par:
                dfs(node, v, h+1)
                dist[v] += dist[node]

    def dfs2(v, par):
        nonlocal ans, res
        ans = max(ans, res)
        for node in graph[v]:
            if node != par:
                res -= dist[node]
                dist[v] -= dist[node]
                res += dist[v]
                dist[node] += dist[v]
                dfs2(node, v)

                dist[node] -= dist[v]
                res -= dist[v]
                dist[v] += dist[node]
                res += dist[node]

    dfs(1, -1)
    dfs2(1, -1)
    print(ans)


setrecursionlimit(300050)
threading.stack_size(100000000)
thread = threading.Thread(target=work)
thread.start()

