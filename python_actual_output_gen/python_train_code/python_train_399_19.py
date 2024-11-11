n, *A = map(int, open(0).read().split())
c = [0]*9
for a in A:
  c[min(8, a//400)] += 1

cl = 8-c[:-1].count(0)
cmin = max(1, cl)
cmax = min(8, cl+c[8])
print(cmin, cmax)