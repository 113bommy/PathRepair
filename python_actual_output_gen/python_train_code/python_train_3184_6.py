n,k,x,y=(int(input()) for i in [0]*4)
print(k*x if n<=k else (k*x+(n-k)*y))