import sys
from collections import deque


def bfs(x1, y1, d):
    q = deque([])
    q.append((d, x1, y1))
    M[x1][y1] = d

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
                if x2 < 0 or x2 >= H:  # 枠外
                    break
                if y2 < 0 or y2 >= W:  # 枠外
                    break
                if m[x2][y2] == '@':  # 蓮の葉
                    break
                if M[x2][y2] < d + 1:  # より良い経路を探索済み。
                    break
                if M[x2][y2] == d + 1:  # 同等の良さの経路を探索済み。　飛び越えて次のマスを探索する。
                    continue

                q.append((d + 1, x2, y2))
                M[x2][y2] = d + 1

    print(-1)


H, W, K = map(int, sys.stdin.readline().strip().split())
xs, ys, xg, yg = map(int, sys.stdin.readline().strip().split())
xg -= 1
yg -= 1

m = []
for _ in range(H):
    m.append(list(map(str, sys.stdin.readline().strip())))

M = [[float('inf')] * W for _ in range(H)]

bfs(xs - 1, ys - 1, 0)
