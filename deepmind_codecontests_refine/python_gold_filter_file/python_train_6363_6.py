def movetotochka(a, b, c, d):
    x = a
    y = b
    if a > c:
        while x != c:
            print(x, y)
            x -= 1
    else:
        while x != c:
            print(x, y)
            x += 1
    if b > d:
        while y != d:
            print(x, y)
            y -= 1
    else:
        while y != d:
            print(x, y)
            y += 1


a, b = list(map(int, input().split()))
c, d = list(map(int, input().split()))
e, f = list(map(int, input().split()))
g = min(a, c, e)
h = max(a, c, e)
j = min(b, d, f)
k = max(b, d, f)
n1 = [a, c, e]
n2 = [b, d, f]
l = 0
m = 0
x = -1
y = -1
summa = 10000000000
for i in range(3):
    for i1 in range(3):
        l = n1[i]
        m = n2[i1]
        n = abs(l - a) + abs(l - c) + abs(l - e) + abs(m - b) + abs(m - d) + abs(m -f)
        if n < summa:
            summa = n
            x = l
            y = m
if x != -1 and y != -1:
    print(summa + 1)
    movetotochka(a, b, x, y)
    movetotochka(c, d, x, y)
    movetotochka(e, f, x, y)
    print(x, y)
