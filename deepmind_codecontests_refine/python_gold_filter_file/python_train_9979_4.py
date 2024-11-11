n=int(input())
a=[0]*(n+1)
ans=1
for i in range(2,n+1):
    x=i
    p=2
    while x>1:
        while x%p==0:
            a[p]+=1
            x//=p
        p+=1
for i in a:
    ans=(ans*(i+1))%(10**9+7)
print(ans)
