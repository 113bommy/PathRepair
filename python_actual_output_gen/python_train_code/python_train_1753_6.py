N, D, A = map(int, input().split())
H = [list(map(int, input().split())) for i in range(N)]
H.sort(key = lambda x:x[0])
INF = int(1e18)
H.append((INF, INF))

ans = 0
S = [0] * (N + 1)
l, r = 0, 0
while r < N:
    while H[r][0] - H[l][0] <= D * 2: r += 1
    h = H[l][1] - S[l]
    num = (h - 1) // A + 1 if h > 0 else 0
    ans += num
    S[l] += A * num
    S[r] -= A * num
    l += 1
    S[l] += S[l - 1]
print(ans)
