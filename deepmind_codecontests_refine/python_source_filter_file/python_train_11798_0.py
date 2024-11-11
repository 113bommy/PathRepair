n=int(input())
l=[1]*n
for i in range(1,n) :
    for j in range(i,n,i) :
        l[j]=l[j]+1
ans=1
a=1
var=1
while a!=n :
    a=a+1
    ans=(var+l[a-1])%998244353
    var=(var+ans)%998244353
print(ans)
    