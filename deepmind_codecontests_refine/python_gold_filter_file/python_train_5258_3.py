from sys import exit

def cdiff(c1, c2):
    ch = 'a'
    while ch in (c1, c2):
        ch = chr(ord(ch) + 1)
    return ch

n, t = map(int, input().split())
a = input()
b = input()
ra = 0
rb = 0
c = [-1] * n
for i in range(n):
    c[i] = (a[i], b[i])[(ra + rb) % 2]
    ra += c[i] != a[i]
    rb += c[i] != b[i]
if rb < ra:
    ra, rb = rb, ra
    a, b = b, a
if ra < rb:
    for i in range(n):
        if c[i] != b[i] and c[i] == a[i]:
            c[i] = cdiff(a[i], b[i])
            ra += 1
            break
    if ra < rb:
        print(-1)
        exit(0)
if t < ra:
    print(-1)
    exit(0)

i = 0
lst = -1
while ra < t and i < n:
    if a[i] == b[i]:
        c[i] = cdiff(a[i], b[i])
        ra += 1
        rb += 1
    elif c[i] not in (a[i], b[i]):
        pass
    elif lst == -1:
        lst = i
    else:
        c[lst] = cdiff(a[lst], b[lst])
        c[i] = cdiff(a[i], b[i])
        lst = -1
        ra += 1
        rb += 1
    i += 1

if ra != t:
    print(-1)
    exit(0)
print(*c, sep='')

