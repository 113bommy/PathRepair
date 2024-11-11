s = input().strip()
if s == '#':
    print(-1)
    exit(0)
b1 = 0
for i in s:
    if i == '(':
        b1 += 1
    else:
        b1 -= 1
b1 += 1
k = s.count('#')
l = 0
b2 = 0
if (b1 == 0):
    print(-1)
    exit(0)
for i in s:
    if i == '(':
        b2 += 1
    elif i == ')':
        b2 -= 1
    else:
        if i == '#':
            l += 1
        if l < k:
            b2 -= 1
        else:
            b2 -= b1
    if (b2 < 0):
        print(-1)
        exit(0)
if b2 != 0:
    print(-1)
else:
    print(*([1] * (k - 1) + [b1]), sep = '\n')