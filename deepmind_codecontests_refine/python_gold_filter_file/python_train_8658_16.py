n,l,r=map(int,input().split())
mi=(n-l+1)+2**l-2
ma=2**r-1+(n-r)*2**(r-1)
print(mi,ma)