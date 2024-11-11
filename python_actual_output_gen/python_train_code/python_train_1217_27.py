n=int(input())
x=1
for i in range(n):
    x=x*(n+1)%1000000007
print(x)
