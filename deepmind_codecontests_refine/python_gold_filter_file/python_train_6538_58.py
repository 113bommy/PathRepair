from collections import deque
H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]
sharps = []
for h, line in enumerate(A):
    sharps += [[h, w, 0] for w, p in enumerate(line) if p == '#']

q = deque(sharps)
while q:
    i, j, score = q.popleft()
    for mi, mj in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
        ni = i + mi
        nj = j + mj
        if ni < 0 or H <= ni or nj < 0 or W <= nj or A[ni][nj] == '#':
            continue
        A[ni][nj] = '#'
        q.append([ni, nj, score+1])
print(score)