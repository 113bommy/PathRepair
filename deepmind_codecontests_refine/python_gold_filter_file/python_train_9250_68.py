n,k,x,y=[int(input()) for _ in range(4)]
print(k*x+(n-k)*y if n>k else n*x)