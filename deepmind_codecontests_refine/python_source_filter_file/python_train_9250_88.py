n,k,x,y = [int().split() for _ in range(4)]
print(k*x+(n-k)*y if n>=k else k*x)