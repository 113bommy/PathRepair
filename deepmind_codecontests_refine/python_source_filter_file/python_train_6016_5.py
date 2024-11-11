N, M, Q = map(int, input().split())
abcd = [list(map(int, input().split())) for _ in range(Q)]

ans = []
import itertools
for A in itertools.combinations_with_replacement(range(1, 10), N):
    tmp = 0
    for a, b, c, d in abcd:
        if A[b-1] - A[a-1] == c:
            tmp += d
    ans.append(tmp)
print(max(ans))