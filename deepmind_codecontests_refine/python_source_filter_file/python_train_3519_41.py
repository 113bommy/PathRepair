N, K = map(int, input().split())
v = list(map(int, input().split()))
w = v[::-1]

res = 0
for l in range(N):
    for r in range(N):
        if l+r > N or l+r > K:
            break
        x = sorted(v[:l] + w[:r])
        for i in range(l+r):
            if x[i] > 0 or i == K-l-r:
                res = max(res, sum(x[i:]))
                break
print(res)