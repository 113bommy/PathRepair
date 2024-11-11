n,l,r=map(int,input().split())
min=(n-l)+(2**l-1)
max=(n-r)*(2**(r-1))+(2**r-1)
print(min,max)