n,m,a,b=map(int,input().split())
k=n%m
print(min(k*a,(m-k)*b))