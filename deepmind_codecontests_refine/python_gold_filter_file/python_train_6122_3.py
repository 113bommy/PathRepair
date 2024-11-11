from collections import defaultdict
N = int(input())
S = list(map(int, input().split()))
ans = 0
d = defaultdict(int)
for c in range(1, N):
    tmp = 0
    k = 0
    while (k + 1) * c < N - 1:
        if k * c == N - 1 - k * c:
            break
        if d[k * c] == c or d[N - 1 - k * c] == c:
            break
        d[k * c] = c
        d[N - 1 - k * c] = c
        tmp += S[k * c] + S[N - 1 - k * c]
        ans = max(ans, tmp)
        k += 1

print(ans)
