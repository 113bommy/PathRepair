n,*a=map(int,open(0).read().split())
print(sum(sorted(a)[::-1][:2*n][1::2]))