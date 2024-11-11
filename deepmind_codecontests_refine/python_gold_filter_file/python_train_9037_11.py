import sys
n=int(input())
l=[0]*(n+1)
for i in range(n):
    l[i]=int(input())
    if l[i]>i:print(-1);sys.exit()
for i in range(n):
    if l[i]-l[i-1]>=2:print(-1);sys.exit()
ans=0
for i in range(n+1):
    if l[i]<=l[i-1]:
        ans+=l[i-1]
print(ans)
