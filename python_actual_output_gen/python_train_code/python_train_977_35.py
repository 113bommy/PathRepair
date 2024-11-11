n,m,d=map(int,input().split())
e=1.00001
if d==0:
    print(e*(m-1)/n)
else:
    print((2*e*(n-d)*(m-1))/(n*n))
