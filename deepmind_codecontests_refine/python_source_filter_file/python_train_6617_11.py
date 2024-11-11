n,n1,n2=map(int,input().split())
a=list(map(int,input().split()))
a.sort(reverse=True)
if n1>n2:
    x=sum(a[:n2])/n2
    y=sum(a[n2:n2+n1])/n1
    print(x+y)
else:
    x=sum(a[:n1])/n1
    y=sum(a[n1:n2+n1])/n1
    print(x+y)