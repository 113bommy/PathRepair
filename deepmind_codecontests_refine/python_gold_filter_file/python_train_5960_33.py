n, m, k = [int(x) for x in input().split()]
for i in range(k):
    x, y = [int(x) for x in input().split()]
print(m + n - 3 + m * n)
s = ''
for i in range(n):
    if i % 2 == 0:
        s += 'D' + (m - 1) * 'L'
    else:
        s += 'D' + (m - 1) * 'R'
print((m - 1) * 'R' + (n - 1) * 'U' + s[1:]) 