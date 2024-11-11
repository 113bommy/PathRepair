n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
m=0
for l in range(n):
    x=a[l]
    y=b[l]
    for r in range(l+1,n):
        x=x|a[r]
        y=y|b[r]
        m=max(m,x+y)
print(m)