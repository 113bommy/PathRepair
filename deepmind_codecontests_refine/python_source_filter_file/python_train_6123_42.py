import sys
from collections import defaultdict


sys.setrecursionlimit(10 ** 6)


def main():
    MOD = 10 ** 9 + 7
    N = int(input())
    adj_nodes = defaultdict(list)
    for _ in range(N - 1):
        x, y = list(map(int, input().split(' ')))
        x -= 1
        y -= 1
        adj_nodes[x].append(y)
        adj_nodes[y].append(x)
    dp_b = [0 for _ in range(N)]
    dp_w = [0 for _ in range(N)]

    def bfs(node, parent):
        black = 1
        white = 1
        for child in adj_nodes[node]:
            if child == parent:
                continue
            bfs(child, node)
            black *= dp_w[child]
            white *= dp_b[child] + dp_w[child]
            black %= MOD
            white %= MOD
        dp_b[node] = black
        dp_w[node] = white

    bfs(0, None)
    print(dp_b[0] + dp_w[0])


if __name__ == '__main__':
    main()