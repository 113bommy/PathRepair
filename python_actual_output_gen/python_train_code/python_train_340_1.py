n=int(input())
a=list(map(int,input().split()))
x=a[1:]
for i in a:
    n-=min(x)<=i<max(x)
    x+=[i]
print(n)