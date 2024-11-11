n, k = map(int, input().split())
u = list(map(int, input().split()))
a = [0] * k
for i in range(n):
    a[u[i] % k] += 1
ans = a[0] - a[0] % 2
for i in range(1, k // 2 + 1):
    if i != k - i:
        ans += min(a[i], a[-i]) * 2
    else:
        ans += a[i] - a[i] % 2
print(ans)
#print(a)
    
