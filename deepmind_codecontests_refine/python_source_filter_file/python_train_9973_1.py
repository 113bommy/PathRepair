import math

N = int(input())
P = []
for _ in range(N):
    P.append([int(n) for n in input().split()])

R2 = 0

for i in range(180):
    theta = 2 * math.pi * i / 360 
    a, b = math.cos(theta), math.sin(theta)
    X, Y = 0, 0
    for x, y in P: 
        if a*x+b*y > 0: # 内積が正 ( = なす角度が鋭角 = そのベクトルを加えると距離が増加)
            X += x
            Y += y
    r2 = X**2+Y**2
    if r2 > R2:
        R2 = r2

print(math.sqrt(R2))