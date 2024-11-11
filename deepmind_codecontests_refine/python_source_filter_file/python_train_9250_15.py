n,k,x,y=[int(input()) for i in range(n)]
if k<=x:
    print(n*k)
else:
    print(k*x+(n-k)*y)