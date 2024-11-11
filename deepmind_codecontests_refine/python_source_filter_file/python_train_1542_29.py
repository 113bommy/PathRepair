n, *a = map(int, open(0).read().split())

ans = [0] * n
for i in range(n-1, -1, -1):
    cnt = 0
    for j in range(i+1, n, i+1): cnt += ans[j-1]
    if cnt%2!=a[i]: ans[i] = 1

print(sum(ans))
for i in range(n):
    if ans[i]: print(i+1)