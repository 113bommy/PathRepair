n, x = map(int, input().split())
c = 0
for i in range(n):
    l, r = map(int, input().split())
    if i == 0:
        if l > x:
            y = x + 1
        else:
            y = 1
    if y + x <= l:
        while y + x <= l:
            y += x
        c += r - y + 1
        y += r - y + 1
    else:
        c += r - y + 1
        y = r + 1
print(c)