from math import sqrt
x, y = map(int, input().split())
M = float('inf')
for i in range(int(input())):
    u,k,v = map(int, input().split())
    # x = vt == > t = x/v
    x = sqrt((x-u)**2 + (y-k)**2 )
    t = x/v
    M = min(M, t)
print(M)