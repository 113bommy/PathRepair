n, k = map(int, input().split())
a = list(map(int, input().split()))
ruiseki = [0]*(n+1)
ans = 0
for i in range(n):
    ruiseki[i+1] = ruiseki[i] + a[i]
bb = sorted(ruiseki[1:n])

ans += ruiseki[-1]*k
for i in range(k-1):
    ans -= bb[i]
print(ans)



