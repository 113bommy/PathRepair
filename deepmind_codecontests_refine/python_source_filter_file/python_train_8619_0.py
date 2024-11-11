import sys
input = sys.stdin.readline
N, Q = [int(_) for _ in input().split()]
STX = [[int(_) for _ in input().split()] for _ in range(N)]
D = [int(input()) for _ in range(Q)]
events = []
for stx in STX:
    s, t, x = stx
    events += [[s - x, 1, x], [t - x, 0, x]]
for i in range(Q):
    events += [[D[i], 2, i]]
events.sort()
block = set()
ans = [-1] * Q
m = float('inf')
for e in events:
    if e[1] == 0:
        block.remove(e[2])
        if m == e[2]:
            if block:
                m = min(block)
            else:
                m = float('inf')
    elif e[1] == 1:
        block.add(e[2])
        m = min(m, e[2])
    else:
        if block:
            if m == float('inf'):
                ans[e[2]] = -1
            else:
                ans[e[2]] = m
print(ans, sep='\n')
