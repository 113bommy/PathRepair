n,m=map(int,input().split())
a=n
while n>=m:
    n=n-m+1
    a=a+1
print(a)