n=int(input())
a=list(map(int,input().split()))

ans=n*10**9
t=sum(a)

s=0

for i in range(n-1):
#    s=sum(a[:i])
    s+=a[i]
    ans=min(ans,abs(t-2*s))
print(ans)