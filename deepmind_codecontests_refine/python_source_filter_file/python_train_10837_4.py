h = input()
a = len(h)
print(a)
b = a // 20
if a % 20 != 0:
    b += 1
print(b, end=' ')
c = a // b
d = a % b
if d != 0:
    c += 1
print(c)
d = b * c - a
e = 0
for i in range(b):
    for u in range(c):
        if d != 0 and u == 0:
            print('*', end='')
            e += 1
            d -= 1
        else:
            print(h[i * c + u - e], end='')
        if u == c - 1:
            print()