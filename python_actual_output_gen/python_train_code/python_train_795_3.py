from itertools import permutations

n, c = map(int, input().split())
d = [list(map(int, input().split())) for _ in range(c)]
cmat = [list(map(int, input().split())) for _ in range(n)]

dcnt = [[0] * c for _ in range(3)]
for i in range(n):
    for j in range(n):
        mod = (i + j) % 3
        dcnt[mod][c[i][j] - 1] += 1

ans = 10 ** 9
for color in permutations(range(c), 3):
    tmp = 0
    for tgt, cnt in zip(color, dcnt):
        tmp += sum(d[i][tgt] * cnt[i] for i in range(c))
    ans = min(ans, tmp)
print(ans)
