n,*a=map(int,open(0).read().split())
b=[s//400 for s in a if s<3200]
c=len(set(b))
print(c,n-len(b)+c)