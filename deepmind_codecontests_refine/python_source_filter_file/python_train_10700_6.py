N, K = map(int, input().split())
a = list(map(int, input().split()))
s = sum(a[:K])
ans = s
for i in range(N-K):
    s = s - s[i] + s[i+K]
    ans = max(s, ans)
print(ans)