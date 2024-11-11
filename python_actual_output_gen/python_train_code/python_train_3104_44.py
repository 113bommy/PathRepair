n,k,*a=map(int,open(0).read().split())
a.sort()
a+=[0]
print(sum(a[:~k])+k)