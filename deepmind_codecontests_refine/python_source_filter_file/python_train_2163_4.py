n=int(input())
a=list(map(int,input().split()))
x=sum(a)
y=sum(a[i]**2 for i in range(n))
z=(x*x-y)/2

print(z%1000000007)

