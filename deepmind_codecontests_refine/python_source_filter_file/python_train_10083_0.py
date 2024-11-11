n, a, b = map(int, input().split())
c = list(map(int, input().split()))

ans = 0
for i in range(n-1):
    ans += min(c[i+1] - c[i], b)
print(ans)