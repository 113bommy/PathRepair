data = tuple(map(int, input().split()))

a = (data[0], data[1])
b = (data[2], data[3])
c = (data[4], data[5])

def d(a, b):
    dx = a[0] - b[0]
    dy = a[1] - b[1]
    return dx * dx + dy * dy

def v(a, b):
    return (b[0] - a[0], b[1] - a[1])

def m(a, b):
    return a[0] * b[1] - a[1] * b[0]
    
print("NO" if d(a, b) != d(b, c) or m(v(a, b), v(b, c)) != 0 else "YES")
