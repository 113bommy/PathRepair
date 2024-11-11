n=int(input())
x=1
for i in range(1,n+1):
    x=x*(i%(10**9+7))
print(x)