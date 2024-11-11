n,a=[int(x) for x in input().split()]
a-=1
t=[int(x) for x in input().split()]
ans=sum(t)
l=a-1
r=a+1
while l>=0 and r<n:
    ans-=(t[l]+t[r])%2
    l-=1
    r+=1
print(ans)
        