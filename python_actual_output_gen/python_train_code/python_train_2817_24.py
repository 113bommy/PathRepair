n=int(input())
a=list(map(int,input().split()))

ans=10**9
t=sum(a)

s=0

for i in range(0,n):
#    s=sum(a[:i])
    s+=a[i]
    ans=min(ans,abs(t-2*s))
print(ans)
