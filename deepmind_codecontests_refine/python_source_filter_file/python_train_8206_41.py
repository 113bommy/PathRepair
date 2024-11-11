n=int(input())
a=list(map(int,input().split()))
x=sum(a)
y=0
ans=10**9+7
for i in range(n):
    y+=a[i]
    if(i+1<n):
        ans=min(ans,abs(x-2*y))
print(ans)
