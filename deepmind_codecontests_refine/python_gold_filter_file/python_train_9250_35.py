n,k,x,y = (int(input()) for _ in range(4))
print(min(n,k)*x + y*max(n-k,0))