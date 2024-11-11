N=int(input())
a=list(map(int,input().split()))
l,r=a.pop(0),sum(a)
ans=10**10
for i in a:
    ans=min(ans,abs(l-r))
    l,r=l+i,r-i
print(ans)