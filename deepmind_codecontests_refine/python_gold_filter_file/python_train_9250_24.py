n,k,x,y=[int(input()) for i in range(4)]

print(x*k+(n-k)*y if n-k>0 else n*x)