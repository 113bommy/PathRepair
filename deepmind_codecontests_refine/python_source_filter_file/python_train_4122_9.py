a = input().strip()
b = []
for i in range(len(a)):
    if (a[i] == '+') or a[i] == '-':
        b += [a[i]]
b += ['+']

a = '+'.join(a.split('-'))
q = list(map(int, a.split('+')))
r = 0
c = '+'
for i in range(len(q)):
    if (c == '+'):
        r += q[i]
    if (c == '-'):
        r -= q[i]
    c = b[i]

r = str(r)
v = 0
s = ""
for x in r:
    n = ord(x)
    while v != n:
        v = (v + 1) % 256
        s += '+'
    s += ','
        
print(s)
