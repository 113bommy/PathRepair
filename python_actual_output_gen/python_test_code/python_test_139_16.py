
data = input().split()
g = [int(x) for x in data]
l1 = g[0]
r1 = g[1]
l2 = g[2]
r2 = g[3]
k = g[4]
l = max(l1,l2)
r = min(r1, r2)
if l > r:
   print(0)
if k >= l and r >= k:
    print(r - l)
else:
    print(r - l + 1)

