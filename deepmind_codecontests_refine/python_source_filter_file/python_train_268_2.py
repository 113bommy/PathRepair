n, k, m = map(int, input().split())
line = list(map(int, input().split()))
line.sort()
t = sum(line)
ans = 0
for i in range(n):
    if m - t * i < 0:
        break
    mm = m - t * i
    ans1 = (n + 1) * i
    for j in range(n):
        ans1 += min(n - i, mm // line[j])
        mm -= min(n - i, mm // line[j]) * line[j]
    ans = max(ans, ans1)
print(ans)