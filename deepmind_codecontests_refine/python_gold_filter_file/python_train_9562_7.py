n, T = map(int, input().split())
t = list(map(int, input().split()))
ans = T
for i in range(1, n):
    ans += min(T, t[i]-t[i-1])
print(ans)