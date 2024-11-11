n,k,x,y=[int(input()) for i in range(4)]
if k>n:
    print(n*x)
else:
    print(k*x+(n-k)*y)