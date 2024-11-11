import math
n=int(input())
t=0
for i in range(n):
    t+=1
    s,d=map(int,input().split())
    k=max(math.ceil((t-s)/d),0)
    t=s+d*k
print(t)
