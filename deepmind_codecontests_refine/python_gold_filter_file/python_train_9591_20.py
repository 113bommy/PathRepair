n, k = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
for i in range(k) :
    ans = max(ans, abs(sum(a) - sum(a[i::k])))
print(ans)