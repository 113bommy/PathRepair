from collections import deque

H, W = map(int,input().split())
A = [list(input()) for _ in range(H)]
p = deque()
for i, Ai in enumerate(A):
    for j, Aij in enumerate(Ai):
        if Aij == "#":
            p.append([i, j, 0])

while p:
    y, x, cnt = p.popleft()
    for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
        if 0 <= y + dy < H and 0 <= x + dx < W and A[y + dy][x + dx] == ".":
            p.append([y + dy, x + dx, cnt + 1])
            A[y + dy][x + dx] = "#"
print(cnt)
