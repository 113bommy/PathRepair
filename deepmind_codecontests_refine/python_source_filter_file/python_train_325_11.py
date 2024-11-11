n, x, y = map(int, input().split())
q = input()
ans = 0
for i in range(n - 1, n - x, -1):
    if i != n - y - 1 and q[i] == '1':
        ans += 1
    if i == n - y - 1 and q[i] == '0':
        ans += 1
print(ans)
