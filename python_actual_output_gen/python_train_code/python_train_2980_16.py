n,l,r=map(int,input().split())
min=(n-l)+(l**2+l)//2
max=(n-r)*(2**(r-1))+(2**r-1)
print(min,max)