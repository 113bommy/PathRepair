import math
t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    print(a*math.floor(math.log10(b+1)))