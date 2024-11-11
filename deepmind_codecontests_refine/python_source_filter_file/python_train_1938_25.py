import math 
r, d = map(int, input().split())
n = int(input())
s = 0
for i in range(0, n):
    x, y, r1 = map(int, input().split())
    if math.sqrt(x**2 + y**2) - r1 > r-d and math.sqrt(x**2 + y**2) + r1 < r:
        s+=1
print(s)