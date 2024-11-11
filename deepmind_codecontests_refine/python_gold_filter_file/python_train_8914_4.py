from math import gcd
input=__import__('sys').stdin.readline
n = int(input())
lis = list(map(int,input().split()))
ans=[0]*n
pre=[1<<30]*(n)
for i in range(n-1,-1,-1):
    pre[i]=min(lis[i],pre[i+1] if i+1 < n else 1<<30 )
#print(pre)    
for i in range(n):
    l=i
    r=n-1
    while l<=r:
        mid = l + (r-l)//2
        a=pre[mid]
        if a<lis[i]:
            l=mid+1
        else:
            r=mid-1
    if r<i:
        ans[i]=-1
    else:    
        ans[i]=r-i-1
print(*ans)                    

        
