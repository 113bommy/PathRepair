def ii():
    return int(input())
def mi():
    return map(int, input().split())
def li():
    return list(mi())
    
def abss(x, y):
    return (x ** 2 + y ** 2) ** 0.5
    
def norm(x, y):
    a = abss(x, y)
    return x / a, y / a

R, x1, y1, x2, y2 = mi()
if (y2 - y1) ** 2 + (x2 - x1) ** 2 >= R * R:
    ans = x1, y1, R
elif (x1, y1) == (x2, y2):
    ans = x1, y1 - R / 2, R / 2
else:
    dx, dy = x1 - x2, y1 - y2
    d = R + abss(dx, dy)
    d /= 2
    dx, dy = norm(dx, dy)
    x3 = x2 + dx * d
    y3 = y2 + dy * d
    ans = x3, y3, d
print('{:.8f} {:.8f} {:.8f}'.format(*ans))