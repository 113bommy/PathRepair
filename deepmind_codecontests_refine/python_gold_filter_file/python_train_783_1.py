class vec(object):
    def __init__(self, x, y):
        self.x, self.y = x, y
    def cross(self, k):
        return self.x * k.y - self.y * k.x
    def dot(self, k):
        return self.x * k.x + self.y * k.y
    def __sub__(self, k):
        return vec(self.x - k.x, self.y - k.y)

n, w, v, u = map(int, input().split(' '))
p = vec(v, u)
l = [vec(*map(int, input().split(' '))) for _ in range(n)]

b, c = 0, 0
for i in l:
    if p.cross(i) <= 0:
        c += 1
    if p.cross(i) >= 0:
        b += 1

if b == n or c == n:
    print('%.8f' % (w / u))
    exit(0)

r = [l[(i + 1) % n] - l[i] for i in range(n)]
i = 0
while p.cross(r[i % n]) > 0:
    i += 1
while p.cross(r[i % n]) < 0:
    i += 1

i %= n
b = (l[i].cross(p) + v * w) / u / v


print('%.8f' % b)
