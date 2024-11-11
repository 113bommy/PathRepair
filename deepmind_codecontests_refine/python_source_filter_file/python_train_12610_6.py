n = int(input())
s = list(input())
a = []
b = []
c = []
for i in range(n):
    if s[i] == '0':
        a.append(i)
    elif s[i] == '1':
        b.append(i)
    else:
        c.append(i)
st = n // 3
x = len(a)
y = len(b)
z = len(c)
if x < st:
    i = 0
    while y > st and x < st:
        s[b[i]] = '0'
        i += 1
        x += 1
        y -= 1
    b = b[i:]
    i = 0
    while z > st and x < st:
        s[c[i]] = '0'
        i += 1
        x += 1
        z -= 1
    c = c[i:]
if z < st:
    while y > st and z < st:
        s[b[-1]] = '2'
        b.pop()
        z += 1
        y -= 1
    while x > st and z < st:
        s[a[-1]] = '2'
        a.pop()
        z += 1
        x -= 1
if y < st:
    while x > st and y < st:
        s[a[-1]] = '1'
        a.pop()
        y += 1
        x -= 1
    i = 0
    while z > st and z < st:
        s[c[i]] = '1'
        i += 1
        y += 1
        z -= 1
    c = c[i:]
print(''.join(s))
