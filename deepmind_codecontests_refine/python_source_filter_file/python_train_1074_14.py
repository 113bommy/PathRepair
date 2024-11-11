import math
t=int(input())
n=list(map(float,input().split()))
n.sort()
n=n[::-1]
s=0
for i in range(0,t-1,2):
    s=s+(n[i]**2-(n[i+1]**2))
if t%2==0:
    print(math.pi*(s*s))
else:
    print(math.pi*(s+(n[t-1])**2))
