N,K,*x =map(int,open(0).read().split())
print(sum([min(i,K-i) for i in x]))
