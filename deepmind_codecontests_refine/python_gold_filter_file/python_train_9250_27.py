n,k,x,y = (int(input()) for i in range(4))
print(n*x+(y-x)*max(n-k,0))