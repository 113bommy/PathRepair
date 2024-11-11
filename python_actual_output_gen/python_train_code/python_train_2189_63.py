n,*p=map(int,open(0).read().split())
print(sum(sorted(p)[:-1])+p[-1]//2)