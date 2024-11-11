u = 10**18
d = 0
N,A,B = map(int,input().split())
s = A - B
H = []
import math
for i in range(N):
    h = int(input())
    H.append(h)
for i in range(50):
    x = (u+d)//2
    a = 0
    for j in range(N):
        h = H[j]
        h -= B
        if h > 0:
            a += math.ceil(h//A)
    if a > x:
        d = x
    else:
        u = x
print(u)