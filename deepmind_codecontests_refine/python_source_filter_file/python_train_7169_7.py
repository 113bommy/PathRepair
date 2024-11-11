def cross(x, y):
    return (x.conjugate() * y).imag

def is_parallel(x, y):
    if abs(cross(x, y)) < 1e-8:
        return True
    return False

n = int(input())
for i in range(n):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(float, input().split())
    a = complex(x2, y2) - complex(x1, y1)
    b = complex(x4, y4) - complex(x3, y3)    
    if is_parallel(a, b):
        print('YES')
    else:
        print('NO')