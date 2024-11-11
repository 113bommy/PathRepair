import itertools

n, m, q = map(int, input().split())
abcd = [tuple(map(int, input().split())) for _ in range(Q)]
ans = 0
for com in itertools.combinations_with_replacement(range(1, M + 1), N):
    score = sum([d for a, b, c, d in abcd if com[b-1] - com[a-1] == c])
    if ans < score:
        ans = score
print(ans)
