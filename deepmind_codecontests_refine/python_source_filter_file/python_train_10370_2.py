n, k = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
ost = 0
for i in range(n):
    ans += min(8, a[i] + ost)
    if a[i] > 8:
        ost += a[i] - 8
    elif a[i] < 8 and ost > 0:
        ost = max(0, ost - 8 + a[i])
    print(ans, ost)
    if ans >= k:
        print(i + 1)
        exit()
print(-1)
        
