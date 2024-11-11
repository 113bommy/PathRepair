N, K = map(int, input().split())
V = [int(i) for i in input().split()]
V2 = V[::-1]
R = min(N, K)
ans = 0
for a in range(R):
    for b in range(R-a):
        c = K - (a + b)
        t = 0
        for v in sorted(V[:a]+V2[:b]):
            if v < 0 and c > 0:
                c -=1
                continue
            t += v
        ans=max(t, ans)
print(ans)
