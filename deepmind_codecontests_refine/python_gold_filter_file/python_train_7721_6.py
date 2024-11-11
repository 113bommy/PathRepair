n, m = map(int, input().split())
p = [list() for i in range(m)]
for i in range(n):
    ans = input()
    for j in range(m):
        p[j].append(ans[j])

b = list(map(int, input().split()))

res = 0

for i in range(m):
    mn = max(p[i].count(c) for c in 'ABCDE')
    res += b[i] * mn

print(res)