n,m,a,b = map(int,input().split())
x=n%m
print(min((7-x)*a,x*b))
