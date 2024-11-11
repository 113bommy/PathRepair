n=int(input())
a=list(map(int,input().split()))
ss=sum(a)
ans=10**9
x=0
for i in range(n-1):
    x+=a[i]
    ans=min(ans,abs(ss-2*x))
print(ans)
