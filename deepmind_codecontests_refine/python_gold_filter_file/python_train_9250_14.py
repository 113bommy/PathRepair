n,k,x,y = (int(input()) for i in range(4))
print(x*n if n<=k else (x*k)+((n-k)*y))
