from math import gcd
n = int(input())
li = []
for i in range(n):
    s = input()
    if '.' in s:
        a, b = s.split('.')
        t = 10 ** len(b)
        li.append((int(a) * t + int(b), t))
    else:
        li.append((int(s), 1))
p = [[0] * 30 for _ in range(30)]
cnt = 0
for i in range(n):
    x, y = li[i]
    g = gcd(x, y)
    x //= g
    y //= g
    if y == 1:
        cnt += 1
    li[i] = x
    a1, b1 = 0, 0
    while x % 2 == 0:
        a1 += 1
        x //= 2
    while x % 5 == 0:
        b1 += 1
        x //= 5
    a2, b2 = 0, 0
    while y % 2 == 0:
        a2 += 1
        y //= 2
    while y % 5 == 0:
        b2 += 1
        y //= 5
    p[a1 - a2 + 9][b1 - b2 + 9] += 1
ans = 0
for i in range(0, 30):
    for j in range(0, 30):
        for a in range(max(0, 18 - i), 30):
            for b in range(max(0, 18 - j), 30):
                ans += p[i][j] * p[a][b]
print((ans - cnt) // 2)
