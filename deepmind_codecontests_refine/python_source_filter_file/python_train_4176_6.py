n, m, k = map(int, input().split())
x1, y2 = n, m
if 2 * n * m % k != 0:
    print('NO')
    exit()

print('YES')

s = 2 * n * m // k
y2 = (s + m - 1) // m
x1 = m

x2 = 1
y1 = x1 * y2 - s

print(0, 0)
print(x1, y1)
print(x2, y2)
