ru = (1,2)
r = (2,0)
rd = (1,-2)
ld = (-1,-2)
l = (-2,0)
lu = (-1,2)
x, y = 0, 0
n = int(input())
l = -1
r = int(1e18)
while r - l > 1:
    m = (r + l)//2
    if 5 * m + 3 * m * (m - 1) > n: r = m
    else: l = m
    
x += l * (1)
y += l * (-2)
n -= 5 * l + 3 * l * (l - 1)
if n<r:
    x+= n * 1
    y+= n * (2)
    n = 0
else:
    n -= r
    x+=r*1
    y+=r*2
    
if n<r-1:
    x+= n * (-1)
    y+= n * 2
    n = 0
else:
    n -= l
    x+=l*(-1)
    y+=l*2
if n < r:
    x+=-2 * n
    n = 0
else:
    n-=r
    x+=-2 * r
if n < r:
    x+=-1 * n
    y+=-2 * n
    n = 0
else:
    n -= r
    x+=-1 * r
    y+=-2 * r
    
if n < r:
    x-=-1 * n
    y-=2 * n
    n = 0
else:
    n -= r
    x += -1*r
    y += 2*r
    
if n < r:
    x+=2*n
    
print(x, y)
    


