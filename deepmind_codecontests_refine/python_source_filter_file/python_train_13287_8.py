n, a, b = [int(x) for x in input().strip().split()]
ans = 0
for i in range(n+1):
    ans = max(ans, min(float('inf') if n-i == 0 else a//(n-i), float('inf') if i == 0 else b//i))
print(ans)
