n=int(input())

k=2
ans=n
while k*k<n:
    while n%k==0:
        n//=k
        ans+=n
    if k==2:
        k=3
    else:
        k+=2
if n>1:
    ans+=1
print(ans)
        
