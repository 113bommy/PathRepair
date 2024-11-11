import math
t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    y=math.floor(math.log10(b+1))
    print(y*a)