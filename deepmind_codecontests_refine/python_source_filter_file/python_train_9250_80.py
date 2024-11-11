n,k,x,y = [int(input) for i in range(4)]
print(min(n,k) * x + max(n-k,0) * y)