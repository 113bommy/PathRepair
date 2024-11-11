s, x = map(int, input().split())
a, b = 1, 0
for i in range(5):
    c, d = s & (1 << i), x & (1 << i)
    # print(i, a, b, c, d)
    if c == d:
        if c:
            a, b = 2 * a, 0
        else:
            a, b = a, a
    else:
        if c:
            a, b = b, b
        else:
            a, b = 0, 2 * b
if s == x:
    a -= 2
print(a)