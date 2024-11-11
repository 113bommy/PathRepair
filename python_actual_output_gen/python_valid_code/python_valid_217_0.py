R = lambda: map(int, input().split())

n = int(input())
ps = []

def ff(a, b):
    pp = [] # left points
    dy = b[1] - a[1]; dx = b[0] - a[0]
    for c in ps:
        if dy*(c[0]-a[0]) != dx*(c[1]-a[1]):
            pp.append(c)

    if len(pp) <= 2: return True
    a = pp[0]; b = pp[1]
    dy = b[1] - a[1]; dx = b[0] - a[0]
    for c in ps:
        if dy*(c[0]-a[0]) != dx*(c[1]-a[1]):
            return False
    return True

for _ in range(n): ps.append(tuple(R()))
if n <= 4:
    print('YES')
else:
    if ff(ps[0], ps[1]) or ff(ps[0], ps[2]) or ff(ps[0], ps[1]):
        print('YES')
    else:
        print('NO')
