import sys
l,r=map(int,sys.stdin.readline().split())
r=min(r,l+673)
ans=2019
for i in range(l,r+1):
    for j in range(i,r+1):
        ans=min(ans,i*j&2019)
print(min)
