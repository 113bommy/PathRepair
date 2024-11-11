import sys
from collections import deque

readline = sys.stdin.readline
readall = sys.stdin.read
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))


def solve():
    h, w, k = nm()
    sy, sx, gy, gx = nm()
    d = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    sx -= 1; sy -= 1
    gx -= 1; gy -= 1
    C = [ns() for _ in range(h)]
    G = [[10**7]*w for _ in range(h)]
    G[sy][sx] = 0
    q = deque([(sy, sx)])
    while q:
        y, x = q.popleft()
        for i in range(4):
            dy, dx = d[i]
            ny, nx = y, x
            for _ in range(k):
                ny += dy; nx += dx
                if ny < 0 or h <= ny or nx < 0 or w <= nx:
                    break
                if C[ny][nx] == '@' or G[ny][nx] <= G[y][x]:
                    break
                if G[ny][nx] > G[y][x] + 1:
                    G[ny][nx] = G[y][x] + 1
                    q.append((ny, nx))
    ans = G[gy][gx]
    print(ans if ans < 10**7 else -1)
    return

solve()
