from math import*
n=int(input())
ans=0
k=1
for r in sorted(map(int,input().split())):ans+=r*r*k;k*=-1
print(ans*pi)