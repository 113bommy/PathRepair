n, m = map(int, input().split())
x = 180 / n

y = int(m / x)

z = y * x

w = (y + 1) * x

if m - z <= w - m:
    v = y
else:
    v = y + 1
if v == 0:
    v = 1
if v >= n:
    print(1, 2, 3)
else:
    print(2, 1, 2 + v)
    
            
