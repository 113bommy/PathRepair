n,*l=map(int,open(0).read().split())

print(int((sum(l)**2 - sum([a**2 for a in l])) / 2) % (10**9 + 7))
