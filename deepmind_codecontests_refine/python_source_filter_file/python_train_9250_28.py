n,k,x,y = (int(input()) for _ in range(4))
print(n*x + y*max(n-k,0))