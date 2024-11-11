n,m=map(int,input().split())
a=n
while n>0:
    n=n//m
    a=a+n
print(a)