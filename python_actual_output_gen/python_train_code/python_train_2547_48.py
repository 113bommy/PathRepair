x,*y=map(int,open(0).read().split())
print(sum(y[0::2]-y[1::2])+x)