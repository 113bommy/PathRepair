from collections import deque
H,W = map(int, input().split())
A = 0
dp = [None] * H
mat = deque()
for h in range(H):
    s = list(input())
    for w, x in zip(range(W), s):
        if x == "#":
            mat.append((h, w, 0))
    dp[h] = s

while len(mat):
    h, w, cnt = mat.popleft()

    for t, h, w, cnt in [(h > 0, h - 1, w, cnt),(h < H-1, h + 1, w, cnt),(w > 0, h , w - 1, cnt),(w < W-1, h , w + 1, cnt)]:
        if t and dp[h][w] == ".":
            mat.append((h, w, cnt+1))
            dp[h][w] = "#"

print(cnt)
