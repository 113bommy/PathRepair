a = int(input())
b = list(input())
c = list(input())
d = 0
e = 0
f = 0
s = 0
for i in range(a):
    b[i] = int(b[i])
    c[i] = int(c[i])
for i in range(a):
    if b[i] == 9:
        d = abs(c[i] + 1)
        e = abs(9 - c[i])
        f += min(d,e)
        e = 0
        d = 0
    else:
        d = abs(b[i] - c[i])
        e = (9-b[i]) + 1
        s = b[i] + 1 + (9 - c[i])
        f += min(d,e,s)
        e = 0
        d = 0
        s = 0
print(f)
