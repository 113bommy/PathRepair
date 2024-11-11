n,k,x,y = [int(input()) for _ in range(4)]
print(n*x-max(0,n-k)*(x-y))