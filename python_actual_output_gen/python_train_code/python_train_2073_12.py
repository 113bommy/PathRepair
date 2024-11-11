from itertools import combinations_with_replacement as cwr

N, M, Q, *Z = map(int, open(0).read().split())
*Z, = zip(*[iter(Z)]*4)
print(Z)

ans = 0
for A in cwr(range(M), N):
    score = 0
    for a, b, c, d in Z:
        if A[b-1]-A[a-1] == c:
            score += d

    if score > ans:
        ans = score

print(ans)
