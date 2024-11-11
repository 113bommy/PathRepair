def inpl(): return list(map(int, input().split()))

N, K = inpl()
S = [0]*26
for _ in range(N):
    S[ord(input()[0]) - 65] += 1

ans = 0
while True:
    S = sorted(S, reverse=True)
    s = S[K-1]
    if s == 0:
        break
    ans += 1
    for i in range(K):
        S[i] -= 1
print(ans)