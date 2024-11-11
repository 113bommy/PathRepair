n, m, k = map(int, input().split())

p = (k - 1) // 2
y = (p // m) + 1
x = (p // n) + 1

if k % 2 == 0:
    print(x, y, 'R')
if k % 2 == 1:
    print(x, y, 'L')
