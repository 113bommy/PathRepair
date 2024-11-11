n = int(input())
s = input()
l = s.split(" ")
c = 0
x4 = l.count('4')
x3 = l.count('3')
x2 = l.count('2')
x1 = l.count('1')

c += x4

if x3 == x1:
    c += x1
    x1 = 0
    x3 = 0

if x3 != 0 and x1 != 0:
    if x3 > x1:
        c += x1
        x3 = x3 - x1
        x1 = 0

    elif x3 < x1:
        c += x3
        x1 -= x3
        x3 = 0

if x3 != 0:
    c += x3
    x3 = 0

c += x2 // 2
x2 %= 2

c += x1 // 4
x1 %= 4

if x2 != 0 and x1 != 0:
    if x2 + x1 <= 4:
        c += 1
        x2 = 0
        x1 = 0

    else:
        c += 2
        x1 = 0
        x2 = 0

if x2 != 0:
    c += 1
    x2 = 0

if x1 != 0:
    c += 1
    x1 = 0

print(c)
