import math

def sqr(x):
    return x*x

n, b, s = map(int, input().split())
coords = list(map(int, input().split()))
x,y = map(int, input().split())
c = 1
dist = math.sqrt(sqr(x-coords[1])+sqr(y))
for i in range(2,n):
    if (float(coords[i])-coords[c])/b+math.sqrt(sqr(x-coords[i])+sqr(y))/s<=dist/s and dist>math.sqrt(sqr(x-coords[i])+sqr(y)):
        c=i
        dist=math.sqrt(sqr(x-coords[i])+sqr(y))
print(c+1)
    