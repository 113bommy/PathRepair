import math

n, m = map(int, input().split())
num = 0
for i in range(n - 1, 500):
    ok = True
    for d in range(2, int(math.sqrt(i)) + 1):
        if i % d == 0:
            ok = False
    if ok:
        num = i
        break

num = max(num, 2)
print(num, num)
left = m - (n - 1)
just = 10 ** 9
for i in range(n - 1):
    if i == n - 2:
        print(i + 1, i + 2, num - (n - 2))
    else:
        print(i + 1, i + 2, 1)
    for j in range(min(n - i - 2, left)):
        print(i + 1, i + 3 + j, just)
    left -= (n - i - 1)
