n,*l=map(int,open(0).read().split())
print((sum(l)**2-sum(i**2 for i in l)//2)%(10**9+7))