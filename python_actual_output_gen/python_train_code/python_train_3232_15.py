n,k,m=map(int,input().split())
a=sorted(list(map(int,input().split())))
av=(sum(a)+min(n*k,m))/n
r=0
l=sum(a)
for i in range(n-1):
    r+=a[i]
    av=max(av,(l-r+min(m-i-1,(n-i-1)*k))/(n-i-1))
print(av)