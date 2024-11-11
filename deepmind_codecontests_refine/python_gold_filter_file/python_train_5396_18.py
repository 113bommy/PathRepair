from collections import deque

H, W = [int(i) for i in input().split()]
S = [list(input()) for _ in range(H)]

white = sum(s.count(".") for s in S)

Q = deque([(0, 0, 1)])
while Q:
    h, w, count = Q.popleft()
    if (h, w) == (H - 1, W - 1):
        print(white - count)
        quit()

    for nh, nw in [(h, w + 1), (h, w - 1), (h + 1, w), (h - 1, w)]:
        if not (0 <= nh < H and 0 <= nw < W):
            continue
        if S[nh][nw] == ".":
            S[nh][nw] = "" # visited
            Q.append((nh, nw, count + 1))
print(-1)