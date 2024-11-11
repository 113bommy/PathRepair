N,*p = map(int,open(0).read().split())
p.sort()
p[-1] /= 2
print(int(sum(p)))
