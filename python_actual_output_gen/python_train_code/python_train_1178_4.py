n,l=map(int,input().split())
x=l if l>=0 else n+l-1 if n+l<0 else 0
print(n*(2*l+n-1)//2-x)