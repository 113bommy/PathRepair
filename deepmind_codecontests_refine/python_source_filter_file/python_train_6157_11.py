inp = lambda: list(map(int, input().split()))
x1, y1 = inp()
x2, y2 = inp()
n, = inp()
W = list(input())

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def __mul__(self, other):
        return Point(self.x * other, self.y * other)

    def __str__(self):
    	return f'({self.x},{self.y})'
    
    def manD(self, other):
        return abs(self.x - other.x) + abs(self.y - other.y)
        
u = Point(x1, y1)
v = Point(x2, y2)

d = {
    'L': Point(-1, 0),
    'R': Point(+1, 0),
    'U': Point(0, +1),
    'D': Point(0, -1),
}

W = [d[x] for x in W]

def sum(W, n=None):
	if n == None:
		n = len(W)
	pos = Point(0, 0)
	for i in range(n):
		pos += W[i]
	return pos

def check(days):
    pos = u + sum(W)*int(days/n) + sum(W, days%n)
    dist = pos.manD(v)
    if dist <= days:
        return True
    return False

l = 1
r = 10**9 + 7
while r - l > 1:
    mid = int((l + r)/2)
    if check(mid):
        r = mid
    else:
        l = mid + 1
res = -1
if check(l):
    res = l
elif check(r):
    res = r
print(res)