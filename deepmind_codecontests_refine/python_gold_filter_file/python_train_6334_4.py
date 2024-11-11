n, m = map(int, input().split())
a = list(map(int, input().split()))

imos = [0] * (2 * m)
diff = [0] * (2 * m)
res = 0
for i in range(n - 1):
    l = a[i] - 1
    r = a[i + 1] - 1
    if l > r:
        r += m
    imos[l + 2] += 1
    imos[r + 1] -= 1
    diff[r + 1] += r - l - 1
    res += r - l

ans = [0] * (2 * m)
tmp = 0
for i in range(2 * m):
    tmp += imos[i]
    if i - 1 >= 0:
        ans[i] += ans[i - 1] + tmp
    else:
        ans[i] += tmp
    ans[i] -= diff[i]
    
max_ = 0
for i in range(m):
    max_ = max(max_, ans[i] + ans[i + m])
print(res - max_)