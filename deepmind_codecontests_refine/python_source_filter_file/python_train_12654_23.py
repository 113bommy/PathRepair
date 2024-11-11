n = int(input())
ans = 1
tot = 0
c = 0
r = -1
col = -1
a = [[int(x) for x in input().split()] for y in range(n)]
if n == 1:
    print(1)
    exit(0)
for i in range(n):
    for j in range(n):
        if a[i][j] == 0:
            r = i
            col = j
            break
    if r != -1:
        break

for i in range(0, n):
    if i == r:
        continue
    c = 0
    for j in range(n):
        c = c + a[i][j]
    if tot != 0 and tot != c:
        ans = -1
        break
    else:
        tot = c
    if ans == -1:
        break

if ans != -1:
    c = 0
    for i in range(n):
        c += a[r][i]
a[r][col] = tot - c

for i in range(0, n):
    c = 0
    for j in range(n):
        c = c + a[j][i]
    if tot != c:
        ans = -1
        break
    else:
        tot = c
    if ans == -1:
        break

c = 0

for i in range(0, n):
    c = c + a[i][i]

if c != tot:
    ans = -1

c = 0

for i in range(n - 1, -1, -1):
    c = c + a[n - i - 1][i]

if c != tot:
    ans = -1

if ans == -1 or pow(10, 18) < a[r][col] or a[r][col] == 0:
    print(-1)
else:
    print(a[r][col])
