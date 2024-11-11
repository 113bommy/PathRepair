n,m,a,b=map(int,input().split())
if n%m == 0:
    print(0)
else:
    k=n%m
    print(min(k*b,abs((n-k*m)*a)))