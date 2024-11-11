n, k = map(int, input().split())
a = [['.' for i in range(n)] for j in range(4)]

for i in range(min(k // 2, n // 2 - 1)):
    a[1][1 + i] = '#'
    a[1][n - 2 - i] = '#'
    k -= 2
if k > 1:
    for i in range(min(k // 2 + 1, n // 2 - 1)):
        if k <= 0:
            break
        a[2][1 + i] = '#'
        a[2][n - 2 - i] = '#'
        k -= 2
if k % 2 == 1:
    a[1][n // 2] = '#'
if k == 2:
    a[1][n // 2] = '#'
    a[2][n // 2] = '#'
print('YES')
for i in range(4):
    print(''.join(a[i]))
