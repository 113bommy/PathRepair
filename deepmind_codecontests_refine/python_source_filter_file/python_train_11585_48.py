import math
t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    print(math.ceil(abs(a-b)))