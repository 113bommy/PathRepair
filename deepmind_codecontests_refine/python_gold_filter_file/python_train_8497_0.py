n = int(input())
*a, = map(int, input().split())
b, c = [0], [0]
cur = 1
for i in range(1, n + 1):
    for j in range(a[i]):
        b.append(cur)
    cur += a[i]
cur = 1
for i in range(1, n + 1):
    if a[i] > 1 and a[i - 1] > 1:
        c.append(cur - 1)
        for j in range(1, a[i]):
            c.append(cur)
    else:
        for j in range(a[i]):
            c.append(cur)
    cur += a[i]
if b == c:
    exit(print('perfect'))
print('ambiguous')
print(*b)
print(*c)