read = lambda: map(int, input().split())
n, k = read()
a = list(read())
b = sorted([(a[i], i) for i in range(n)])
if sum(a) < k:
    print(-1)
    exit()
j = 0
x2 = 0
for i in range(n):
    x = b[i][0]
    cur = (n - j) * x
    if cur > k: break
    x2 = x
    k -= cur
    j += 1
if n == j:
    print()
    exit()
y = k // (n - j)
for i in range(n):
    a[i] -= y
m = k % (n - j)
ans = []
j1 = 0
i1 = 0
for i in range(n):
    if a[i] > x2 and j1 < m:
        j1 += 1
        if a[i] > x2 + 1:
            ans.append(i + 1)
    if j1 == m:
        i1 = i + 1
        if m == 0: i1 = 0
        break
c = [i + 1 for i in range(i1, n) if a[i] > x2]
ans = c + ans
print(*ans)
