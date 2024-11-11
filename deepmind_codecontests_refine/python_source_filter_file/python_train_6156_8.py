mod=998244353
n=int(input())
a=list(input())
i=1
j=n-2
while a[i-1]==a[i]:
    i+=1
while a[j+1]==a[j]:
    j-=1
j=n-j-1
r=set(a)
if len(r)==1:
    print(((n*(n+1))//2+1)%mod)
else:
    if a[0]==a[-1]:
        ans=(2*i*j+2)%mod
    else:
        ans=(i+j+1)%mod
    print(ans)