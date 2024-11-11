n, m, k = map(int, input().split())
for i in range(k * 2):
    a, b = map(int, input().split())
ans = []
ans += ['L'] * (m - 1)
ans += ['D'] * (n - 1)
for i in range(m):
    if i % 2 == 0:
        ans += ['U'] * (n - 1)
    else:
        ans += ['D'] * (n - 1)
    if i < m - 1:
        ans.append('R')
print(len(ans))
print(''.join(ans))
