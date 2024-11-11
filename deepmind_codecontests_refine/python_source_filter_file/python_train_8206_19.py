n=int(input())
a=list(map(int,input().split()))

y=sum(a)
x=0
mn=10**9
for i in range(n-1):
    x+=a[i]
    y-=a[i]
    mn=min(mn, abs(x-y))

print(mn)