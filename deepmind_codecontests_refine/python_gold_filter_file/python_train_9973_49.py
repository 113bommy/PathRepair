import math
 
N = int(input())
V = []
for _ in range(N):
    V.append([ int(n) for n in input().split() ])
 
R2 = 0
for i in range(100): 
    theta = 2 * math.pi * i / 100  
    a, b = math.cos(theta), math.sin(theta)  ### a=cosθ、b=sinθ　（θ=2π*i/100） 
    X, Y = 0, 0
    for x, y in V: ### xi と yi を取り出す
        if a*x+b*y > 0: ### 正の数ならば
            X += x
            Y += y
    r2 = X**2+Y**2
    if r2 > R2:
        R2 = r2
 
print(math.sqrt(R2))