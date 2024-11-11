#解説参照
import sys
n,*a,=map(int, sys.stdin.read().split())
if a[0]:
    print(-1)
    exit()

ans=0
for i in range(1,n-1):
    if a[i+1]>a[i]+1:
        print(-1)
        exit()
    if a[i+1]-a[i]==1:
        ans+=1
    else:####
        ans+=a[i+1]

print(ans)