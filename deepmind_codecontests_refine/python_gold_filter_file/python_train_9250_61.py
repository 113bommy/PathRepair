n,k,x,y=(int(input()) for _ in range(4))
if n>k:
    print(k*x+(n-k)*y)
else:
    print(n*x)