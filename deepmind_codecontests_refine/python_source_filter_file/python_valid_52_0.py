import sys
input=sys.stdin.readline


t=int(input())

for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    left=sum(a)
    ans=-10**9
    right=0
    k=1
    for i in range(n-1):
        right+=a[i]
        left-=a[i]
        ans=max(right/k+left/(n-k),ans)
        k+=1
    print(ans)
    
