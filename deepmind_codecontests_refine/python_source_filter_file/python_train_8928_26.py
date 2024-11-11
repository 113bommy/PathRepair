from collections import deque
import sys


def bfs(x1, y1, d):
    q = deque()
    q.append((d, x1, y1))

    while q:
        d, x1, y1 = q.popleft()

        M[x1][y1] = d

        if [x1, y1] == [xg, yg]:
            print(d)
            return

        for dx, dy in ((0, 1), (1, 0), (0, -1), (-1, 0)):
            for k in range(1, K + 1):
                x2 = x1 + dx * k
                y2 = y1 + dy * k

                if (0 <= x2 < H) and (0 <= y2 < W):
                    if m[x2][y2] == '@':
                        break
                    elif M[x2][y2] == -1:
                        # M[x2][y2] = d + 1
                        q.append((d + 1, x2, y2))
                    elif M[x2][y2] < d + 1:
                        break
                else:
                    break
    print(-1)


H, W, K = map(int, input().split())
xs, ys, xg, yg = map(int, input().split())
xs, ys, xg, yg = xs - 1, ys - 1, xg - 1, yg - 1

m = []
for i in range(H):
    m.append(list(map(str, sys.stdin.readline().strip())))

M = [[-1] * W for i in range(H)]

bfs(xs, ys, 0)