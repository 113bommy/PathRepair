n, m, k = map(int, input().split())
a = [[0 for i in range(m)] for j in range(n)]
for i in range(n):
    s = input()
    for j in range(m):
        if s[j] == '.':
            a[i][j] = 1
        else:
            a[i][j] = 0
ans = 0
for i in range(n):
    s = 0
    for j in range(m):
        if a[i][j]:
            res += 1
            if res >= k:
                ans += 1
        else:
            res = 0
for i in range(m):
    s = 0
    for j in range(n):
        if a[j][i]:
            res += 1
            if res >= k:
                ans += 1
        else:
            res = 0
if not k - 1: ans //= 2
print(ans)
