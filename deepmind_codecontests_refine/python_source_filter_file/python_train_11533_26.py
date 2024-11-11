from collections import deque

int1 = lambda x: int(x) - 1

H, W = map(int, input().split())
Ch, Cw = map(int1, input().split())
Dh, Dw = map(int1, input().split())
S = [[0 if s == '.' else -1 for s in input()] for _ in range(H)]

d = deque([(Ch, Cw)])
cur = 0
while True:
    visited = set()
    while d:
        h, w = d.pop()
        visited.add((h, w))
        S[h][w] = cur
        if (h, w) == (Dh, Dw):
            print(cur)
            exit()
        for dh, dw in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            if 0 <= h + dh < H and 0 <= w + dw < W and S[h + dh][w + dw] == 0:
                d.append((h + dh, w + dw))

    for h, w in visited:
        for dh in range(-2, 3):
            for dw in range(-2, 3):
                if 0 <= h + dh < H and 0 <= w + dw < W and S[h + dh][w + dw] == 0:
                    d.append((h + dh, w + dw))
    if not d:
        print(-1)
        exit()
    cur += 1
