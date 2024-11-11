from collections import deque
H, W = map(int, input().split())
q = deque()
A = []
for h in range(H):
    r = input()
    for w in range(W):
        if r[w] == "#":
            q.append([h, w])
    A.append([0 if s=="#" else -1 for s in r])

d = [[-1, 0], [0, -1], [0, 1], [1, 0]]
p = 0

while q:
    h, w = q.popleft()
    p = A[h][w]+1
    for dh, dw in d:
        nh = h+dh
        nw = w+dw
        if not (0 <= nh < H):
            continue
        if not (0 <= nw < W):
            continue
        if A[nh][nw] == -1:
            A[nh][nw] = p
            q.append([nh, nw])

print(p-1)