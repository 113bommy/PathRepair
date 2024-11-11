import sys
sys.setrecursionlimit(10**9)

MOD = 10**9 + 7
N = int(input())
paths = {i:[] for i in range(N+1)}
for _ in range(N-1):
    x, y = map(int, input().split())
    paths[x].append(y)
    paths[y].append(x)

dpt = [[-1] * 2 for i in range(N+1)]

def count_cc(prev, node, color):
    if dpt[node][color] != -1:
        return dpt[node][color]
    if paths[node] == [prev]:
        dpt[node][color] = 1
        return 1
    result = 1
    if color == 0:
        for nxt in paths[node]:
            if nxt == prev:
                continue
            result *= (count_cc(node, nxt, 0) + count_cc(node, nxt, 1))
            result %= MOD
    else:
        for nxt in paths[node]:
            if nxt == prev:
                continue
            result *= count_cc(node, nxt, 0)
            result %= MOD

    dpt[node][color] = result
    return result

print(count_cc(0, 1, 0) + count_cc(0, 1, 1))
