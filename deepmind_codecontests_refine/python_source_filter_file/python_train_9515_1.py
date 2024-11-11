n=int(input())
a=list(map(int,input().split()))
x=-a[0]
for i in range(n-1):
    for j in range(i+1,n+1):
        b=a[i:j]
        x=max(x,b.count(0)-b.count(1))
print(a.count(1)+x)
